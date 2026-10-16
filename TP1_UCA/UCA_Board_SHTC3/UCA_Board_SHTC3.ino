// Étape 4.2 – Capteur de température et d'humidité SHTC3 (I2C)
#include <Wire.h>
#include "SHTSensor.h"

SHTSensor sht;
// Pour forcer un modèle précis : SHTSensor sht(SHTSensor::SHTC3);

void setup() {
  Wire.begin();
  Serial.begin(9600);
  delay(1000);  // laisse le temps au moniteur série de s'ouvrir

  if (sht.init()) {
    Serial.print("init(): success\n");
  } else {
    Serial.print("init(): failed\n");
  }
}

void loop() {
  if (sht.readSample()) {
    Serial.print("SHT:\n");
    Serial.print("  RH: ");
    Serial.print(sht.getHumidity(), 2);
    Serial.print("\n");
    Serial.print("  T:  ");
    Serial.print(sht.getTemperature(), 2);
    Serial.print("\n");
  } else {
    Serial.print("Error in readSample()\n");
  }
  delay(1000);
}
