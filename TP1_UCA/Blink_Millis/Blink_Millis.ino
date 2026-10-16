// Étape 3.1 – Clignotement non bloquant avec millis()
const unsigned long interval = 1000;  // ms

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  static unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));  // bascule l'état de la LED
  }
}
