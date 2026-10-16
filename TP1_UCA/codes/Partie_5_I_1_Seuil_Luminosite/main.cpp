// Partie 5.I – Seuil de luminosité : LEDs rouges + message si > 500 lux (115200 bauds)
#include <Arduino.h>
#include "BandeauLed.h"
#include "CapteurLumiere.h"
#include "Minuterie.h"

namespace {
constexpr unsigned long DEBIT_BAUDS = 115200;
constexpr float SEUIL_LUX = 500.0f;

BandeauLed bandeau;
CapteurLumiere capteur;
Minuterie periodeMesure(500);
}  // namespace

void setup() {
  Serial.begin(DEBIT_BAUDS);
  bandeau.begin(84);

  if (!capteur.begin()) {
    Serial.println("Capteur LTR-303 introuvable !");
    for (;;) {
      delay(10);
    }
  }
  Serial.println("Seuil de luminosite : pret");
}

void loop() {
  if (!periodeMesure.estEcoulee()) {
    return;
  }

  MesureLumiere mesure{};
  if (!capteur.lire(mesure)) {
    return;
  }

  Serial.print("Visible+IR = ");
  Serial.print(mesure.visibleIr);
  Serial.print("  IR = ");
  Serial.print(mesure.infrarouge);
  Serial.print("  Lux = ");
  Serial.println(mesure.lux, 1);

  const bool tropLumineux = mesure.lux > SEUIL_LUX;
  if (tropLumineux) {
    Serial.println("Luminosite > 500 lux : LEDs rouges allumees");
  }
  bandeau.remplir(tropLumineux ? CRGB::Red : CRGB::Black);
  bandeau.afficher();
}
