#pragma once
#include <Arduino.h>
#include <Wire.h>
#include "SHTSensor.h"

struct MesureTempHum {
  float temperature;  // °C
  float humidite;     // %HR
};

// Capteur de température et d'humidité SHTC3 (I2C, adresse 0x70).
class CapteurTempHum {
public:
  bool begin();
  bool lire(MesureTempHum& mesure);

private:
  SHTSensor sht_;
};
