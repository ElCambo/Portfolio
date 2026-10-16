#pragma once
#include <Arduino.h>

// Minuterie non bloquante basée sur millis().
// estEcoulee() renvoie true une seule fois par période.
class Minuterie {
public:
  explicit Minuterie(unsigned long periodeMs);

  bool estEcoulee();
  void setPeriode(unsigned long periodeMs);
  unsigned long periode() const;

private:
  unsigned long periodeMs_;
  unsigned long precedent_;
};
