// Étape 4.4 – Accéléromètre KXTJ3-1057 (115200 bauds)
#include <Arduino.h>
#include "Accelerometre.h"

namespace {
constexpr unsigned long DEBIT_BAUDS = 115200;
constexpr float FREQUENCE_HZ = 6.25f;  // 0.781 ... 1600 Hz
constexpr uint8_t PLAGE_G = 2;         // ±2, 4, 8 ou 16 g
constexpr bool HAUTE_RESOLUTION = false;

Accelerometre accelerometre(0x0E);
}  // namespace

void setup() {
  Serial.begin(DEBIT_BAUDS);
  delay(100);

  if (accelerometre.begin(FREQUENCE_HZ, PLAGE_G, HAUTE_RESOLUTION)) {
    Serial.println("IMU initialized.");
  } else {
    Serial.println("Failed to initialize IMU.");
    for (;;) {
    }
  }
}

void loop() {
  accelerometre.veille(false);  // sort l'IMU du mode veille
  const Acceleration a = accelerometre.lire();
  accelerometre.veille(true);   // remet l'IMU en veille

  Serial.print(" Acceleration X float = ");
  Serial.println(a.x, 4);
  Serial.print(" Acceleration Y float = ");
  Serial.println(a.y, 4);
  Serial.print(" Acceleration Z float = ");
  Serial.println(a.z, 4);

  delay(1000);
}
