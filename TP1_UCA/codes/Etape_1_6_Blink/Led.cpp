#include "Led.h"

Led::Led(uint8_t broche) : broche_(broche), allumee_(false) {}

void Led::begin() {
  pinMode(broche_, OUTPUT);
  eteindre();
}

void Led::allumer() {
  digitalWrite(broche_, HIGH);
  allumee_ = true;
}

void Led::eteindre() {
  digitalWrite(broche_, LOW);
  allumee_ = false;
}

void Led::basculer() {
  if (allumee_) {
    eteindre();
  } else {
    allumer();
  }
}

bool Led::estAllumee() const {
  return allumee_;
}
