#pragma once
#include <Arduino.h>
#include "Adafruit_LTR329_LTR303.h"

struct MesureLumiere {
  uint16_t visibleIr;   // canal 0 : visible + infrarouge (comptes bruts)
  uint16_t infrarouge;  // canal 1 : infrarouge seul (comptes bruts)
  float lux;            // éclairement calculé
};

// Capteur de lumière LTR-303A (I2C, adresse 0x29), gain x1.
class CapteurLumiere {
public:
  bool begin(ltr329_integrationtime_t integration = LTR3XX_INTEGTIME_100,
             ltr329_measurerate_t frequence = LTR3XX_MEASRATE_500);

  bool nouvelleDonnee();
  bool lire(MesureLumiere& mesure);

private:
  static float integrationEnMs(ltr329_integrationtime_t integration);
  float calculerLux(uint16_t ch0, uint16_t ch1) const;

  Adafruit_LTR303 ltr_;
  float integrationMs_ = 100.0f;
};
