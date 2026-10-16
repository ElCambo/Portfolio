// Partie 5.I – Détection d'inclinaison
// X > 0.5 g  -> "Inclinée à droite"
// X < -0.5 g -> "Inclinée à gauche"
#include "kxtj3-1057.h"

#define SEUIL_G 0.5

KXTJ3 myIMU(0x0E);

void setup() {
  Serial.begin(115200);
  delay(100);
  // 50 Hz, plage ±2 g suffisante (on mesure la projection de la gravité, |X| <= 1 g)
  if (myIMU.begin(50, 2, false) != IMU_SUCCESS) {
    Serial.println("Failed to initialize IMU.");
    while (true);
  }
  myIMU.standby(false);  // on laisse l'accéléromètre actif en continu
  Serial.println("IMU initialized.");
}

void loop() {
  float x = myIMU.axisAccel(X);

  Serial.print("X = ");
  Serial.print(x, 3);
  Serial.print(" g  -> ");

  if (x > SEUIL_G) {
    Serial.println("Inclinée à droite");
  } else if (x < -SEUIL_G) {
    Serial.println("Inclinée à gauche");
  } else {
    Serial.println("A plat");
  }
  delay(500);
}
