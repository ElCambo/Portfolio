// Étape 1.6 – Test de clignotement de la LED bleue (LED_BUILTIN = D13)
#include <Arduino.h>
#include "Led.h"

namespace {
constexpr unsigned long DUREE_MS = 1000;
Led ledBleue(LED_BUILTIN);
}  // namespace

void setup() {
  ledBleue.begin();
}

void loop() {
  ledBleue.allumer();
  delay(DUREE_MS);
  ledBleue.eteindre();
  delay(DUREE_MS);
}
