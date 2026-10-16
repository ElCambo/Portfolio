// Partie 5.II – Station météo embarquée (115200 bauds)
// a. Affichage toutes les 5 s
// b. T > 30 °C et HR < 30 % -> "Risque de sécheresse"
// c. Luminosité < 100 lux   -> "Nuit détectée"
#include <Arduino.h>
#include "CapteurTempHum.h"
#include "CapteurLumiere.h"
#include "Minuterie.h"

namespace {
constexpr unsigned long DEBIT_BAUDS = 115200;
constexpr unsigned long PERIODE_MS = 5000;
constexpr float TEMPERATURE_SECHERESSE = 30.0f;
constexpr float HUMIDITE_SECHERESSE = 30.0f;
constexpr float SEUIL_NUIT_LUX = 100.0f;

CapteurTempHum capteurTempHum;
CapteurLumiere capteurLumiere;
Minuterie periodeAffichage(PERIODE_MS);
}  // namespace

void setup() {
  Serial.begin(DEBIT_BAUDS);
  delay(1000);

  if (!capteurTempHum.begin()) {
    Serial.println("SHTC3 : init failed");
  }
  if (!capteurLumiere.begin()) {
    Serial.println("LTR-303 : introuvable");
  }
  Serial.println("Station meteo demarree");
}

void loop() {
  if (!periodeAffichage.estEcoulee()) {
    return;  // non bloquant
  }
  Serial.println("----- Station meteo -----");

  MesureTempHum climat{};
  const bool climatOk = capteurTempHum.lire(climat);
  if (climatOk) {
    Serial.print("Temperature : ");
    Serial.print(climat.temperature, 2);
    Serial.println(" C");
    Serial.print("Humidite    : ");
    Serial.print(climat.humidite, 2);
    Serial.println(" %");
  } else {
    Serial.println("Erreur lecture SHTC3");
  }

  MesureLumiere lumiere{};
  const bool lumiereOk = capteurLumiere.lire(lumiere);
  if (lumiereOk) {
    Serial.print("Luminosite  : ");
    Serial.print(lumiere.lux, 1);
    Serial.println(" lux");
  } else {
    Serial.println("Erreur lecture LTR-303");
  }

  if (climatOk && climat.temperature > TEMPERATURE_SECHERESSE && climat.humidite < HUMIDITE_SECHERESSE) {
    Serial.println("Risque de sécheresse");
  }
  if (lumiereOk && lumiere.lux < SEUIL_NUIT_LUX) {
    Serial.println("Nuit détectée");
  }
}
