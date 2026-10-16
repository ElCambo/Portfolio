// Étape 3.1 – Clignotement non bloquant avec millis() (encapsulé dans la classe Minuterie)
#include <Arduino.h>
#include "Led.h"
#include "Minuterie.h"

namespace {
constexpr unsigned long INTERVALLE_MS = 1000;
Led ledBleue(LED_BUILTIN);
Minuterie minuterie(INTERVALLE_MS);
}  // namespace

void setup() {
  ledBleue.begin();
}

void loop() {
  if (minuterie.estEcoulee()) {
    ledBleue.basculer();
  }
  // loop() n'est jamais bloquée : on pourrait faire d'autres tâches ici
}
