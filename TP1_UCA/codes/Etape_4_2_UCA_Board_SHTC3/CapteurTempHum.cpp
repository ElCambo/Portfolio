#include "CapteurTempHum.h"

bool CapteurTempHum::begin() {
  Wire.begin();
  return sht_.init();
}

bool CapteurTempHum::lire(MesureTempHum& mesure) {
  if (!sht_.readSample()) {
    return false;
  }
  mesure.temperature = sht_.getTemperature();
  mesure.humidite = sht_.getHumidity();
  return true;
}
