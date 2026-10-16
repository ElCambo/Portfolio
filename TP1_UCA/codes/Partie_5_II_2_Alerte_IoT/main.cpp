// Partie 5.II – Simulation d'une alerte IoT (115200 bauds)
// a. Inclinaison dangereuse : |accélération| > 2 g sur un axe
// b. Surchauffe             : température > 40 °C
// c. Obscurité totale       : luminosité < 10 lux
// Format : "Alerte : [Type d'alerte] à [millis] ms" (émise quand la condition devient vraie)
#include <Arduino.h>
#include "Accelerometre.h"
#include "CapteurTempHum.h"
#include "CapteurLumiere.h"
#include "Minuterie.h"
#include "Alerte.h"

namespace {
constexpr unsigned long DEBIT_BAUDS = 115200;
constexpr float SEUIL_CHOC_G = 2.0f;
constexpr float SEUIL_SURCHAUFFE_C = 40.0f;
constexpr float SEUIL_OBSCURITE_LUX = 10.0f;

Accelerometre accelerometre(0x0E);
CapteurTempHum capteurTempHum;
CapteurLumiere capteurLumiere;

Minuterie periodeAccel(20);     // lecture rapide pour ne pas rater un choc
Minuterie periodeCapteurs(500);

Alerte alerteInclinaison("Inclinaison dangereuse");
Alerte alerteSurchauffe("Surchauffe");
Alerte alerteObscurite("Obscurité totale");

bool depasse(const Acceleration& a, float seuil) {
  return fabs(a.x) > seuil || fabs(a.y) > seuil || fabs(a.z) > seuil;
}
}  // namespace

void setup() {
  Serial.begin(DEBIT_BAUDS);
  delay(1000);

  if (!capteurTempHum.begin()) {
    Serial.println("SHTC3 : init failed");
  }
  if (!capteurLumiere.begin(LTR3XX_INTEGTIME_100, LTR3XX_MEASRATE_100)) {
    Serial.println("LTR-303 : introuvable");
  }
  // Plage ±8 g : avec ±2 g la mesure sature à 2 g et "> 2 g" ne serait jamais atteint
  if (!accelerometre.begin(100, 8)) {
    Serial.println("KXTJ3 : init failed");
  }
  accelerometre.veille(false);

  Serial.println("Systeme IoT pret");
}

void loop() {
  if (periodeAccel.estEcoulee()) {
    alerteInclinaison.verifier(depasse(accelerometre.lire(), SEUIL_CHOC_G), Serial);
  }

  if (periodeCapteurs.estEcoulee()) {
    MesureTempHum climat{};
    if (capteurTempHum.lire(climat)) {
      alerteSurchauffe.verifier(climat.temperature > SEUIL_SURCHAUFFE_C, Serial);
    }
    MesureLumiere lumiere{};
    if (capteurLumiere.lire(lumiere)) {
      alerteObscurite.verifier(lumiere.lux < SEUIL_OBSCURITE_LUX, Serial);
    }
  }
}
