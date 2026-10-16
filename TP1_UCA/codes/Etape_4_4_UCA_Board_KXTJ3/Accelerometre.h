#pragma once
#include <Arduino.h>
#include "kxtj3-1057.h"

// La bibliothèque KXTJ3 définit une macro getName() qui casse FastLED : on la supprime.
#ifdef getName
#undef getName
#endif

struct Acceleration {
  float x;  // en g
  float y;
  float z;
};

// Accéléromètre 3 axes KXTJ3-1057 (I2C, adresse 0x0E ou 0x0F).
class Accelerometre {
public:
  explicit Accelerometre(uint8_t adresse = 0x0E);

  // frequence en Hz, plage en g (2, 4, 8 ou 16)
  bool begin(float frequence, uint8_t plage, bool hauteResolution = false);
  void veille(bool active);
  Acceleration lire();

private:
  KXTJ3 imu_;
};
