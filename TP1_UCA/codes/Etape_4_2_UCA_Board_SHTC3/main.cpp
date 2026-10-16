// Étape 4.2 – Capteur de température et d'humidité SHTC3 (9600 bauds)
#include <Arduino.h>
#include "CapteurTempHum.h"

namespace {
constexpr unsigned long DEBIT_BAUDS = 9600;
constexpr unsigned long PERIODE_MS = 1000;
CapteurTempHum capteur;
}  // namespace

void setup() {
  Serial.begin(DEBIT_BAUDS);
  delay(1000);  // laisse le temps au moniteur série de s'ouvrir

  Serial.println(capteur.begin() ? "init(): success" : "init(): failed");
}

void loop() {
  MesureTempHum mesure{};
  if (capteur.lire(mesure)) {
    Serial.println("SHT:");
    Serial.print("  RH: ");
    Serial.println(mesure.humidite, 2);
    Serial.print("  T:  ");
    Serial.println(mesure.temperature, 2);
  } else {
    Serial.println("Error in readSample()");
  }
  delay(PERIODE_MS);
}
