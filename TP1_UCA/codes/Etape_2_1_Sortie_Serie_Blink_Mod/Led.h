#pragma once
#include <Arduino.h>

// Pilote une LED simple branchée sur une broche numérique.
class Led {
public:
  explicit Led(uint8_t broche);

  void begin();          // configure la broche en sortie
  void allumer();
  void eteindre();
  void basculer();       // allumée -> éteinte, éteinte -> allumée
  bool estAllumee() const;

private:
  uint8_t broche_;
  bool allumee_;
};
