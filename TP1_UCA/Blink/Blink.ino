// Étape 1.6 – Test de clignotement de la LED bleue (LED_BUILTIN = D13 sur la carte UCA)
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // LED_BUILTIN en sortie
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // LED allumée
  delay(1000);                      // 1 s
  digitalWrite(LED_BUILTIN, LOW);   // LED éteinte
  delay(1000);                      // 1 s
}
