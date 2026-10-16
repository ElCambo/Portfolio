// Étape 2.1 – Sortie série : l'état de la LED est envoyé sur l'UART (9600 bauds)
#include <Arduino.h>
#include "Led.h"

namespace {
constexpr unsigned long DEBIT_BAUDS = 9600;
constexpr unsigned long DUREE_MS = 1000;
Led ledBleue(LED_BUILTIN);
}  // namespace

void setup() {
  Serial.begin(DEBIT_BAUDS);
  ledBleue.begin();
  Serial.println("Initialisation OK");
}

void loop() {
  ledBleue.allumer();
  Serial.println(1);  // visible dans le moniteur et le traceur série
  delay(DUREE_MS);

  ledBleue.eteindre();
  Serial.println(0);
  delay(DUREE_MS);
}
