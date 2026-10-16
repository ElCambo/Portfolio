// Étape 4.3 – Capteur de lumière LTR-303A (115200 bauds)
#include <Arduino.h>
#include "CapteurLumiere.h"

namespace {
constexpr unsigned long DEBIT_BAUDS = 115200;
CapteurLumiere capteur;
}  // namespace

void setup() {
  Serial.begin(DEBIT_BAUDS);
  while (!Serial) {
    delay(10);
  }
  Serial.println("Adafruit LTR-303 simple test");

  // Gain x1, intégration 50 ms, une mesure toutes les 50 ms (comme dans le TP)
  if (!capteur.begin(LTR3XX_INTEGTIME_50, LTR3XX_MEASRATE_50)) {
    Serial.println("Couldn't find LTR sensor!");
    for (;;) {
      delay(10);
    }
  }
  Serial.println("Found LTR sensor!");
}

void loop() {
  MesureLumiere mesure{};
  if (capteur.nouvelleDonnee() && capteur.lire(mesure)) {
    Serial.print("CH0 Visible + IR: ");
    Serial.print(mesure.visibleIr);
    Serial.print("\t\tCH1 Infrared: ");
    Serial.print(mesure.infrarouge);
    Serial.print("\t\tLux: ");
    Serial.println(mesure.lux, 1);
  }
  delay(1000);
}
