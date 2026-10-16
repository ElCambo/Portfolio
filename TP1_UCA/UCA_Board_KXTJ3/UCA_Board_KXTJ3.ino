// Étape 4.4 – Accéléromètre 3 axes KXTJ3-1057 (I2C, adresse 0x0E) – 115200 bauds
#include "kxtj3-1057.h"

float sampleRate = 6.25;  // Hz : 0.781, 1.563, 3.125, 6.25, 12.5, 25, 50, 100, 200, 400, 800, 1600
uint8_t accelRange = 2;   // ±2, 4, 8 ou 16 g
bool highRes = false;     // mode haute résolution

KXTJ3 myIMU(0x0E);        // adresse 0x0E ou 0x0F

void setup() {
  Serial.begin(115200);
  delay(100);

  if (myIMU.begin(sampleRate, accelRange, highRes) == IMU_SUCCESS) {
    Serial.println("IMU initialized.");
  } else {
    Serial.println("Failed to initialize IMU.");
    while (true);
  }
}

void loop() {
  myIMU.standby(false);  // sort l'IMU du mode veille

  uint8_t dataLowRes = 0;

  if (myIMU.readRegister(&dataLowRes, KXTJ3_XOUT_H) == IMU_SUCCESS) {
    Serial.print(" Acceleration X float = ");
    Serial.println(myIMU.axisAccel(X), 4);
  }
  if (myIMU.readRegister(&dataLowRes, KXTJ3_YOUT_H) == IMU_SUCCESS) {
    Serial.print(" Acceleration Y float = ");
    Serial.println(myIMU.axisAccel(Y), 4);
  }
  if (myIMU.readRegister(&dataLowRes, KXTJ3_ZOUT_H) == IMU_SUCCESS) {
    Serial.print(" Acceleration Z float = ");
    Serial.println(myIMU.axisAccel(Z), 4);
  }

  myIMU.standby(true);   // remet l'IMU en veille
  delay(1000);
}
