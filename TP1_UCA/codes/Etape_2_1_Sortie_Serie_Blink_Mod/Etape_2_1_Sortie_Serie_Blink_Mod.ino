// Étape 2.1 – Sortie série : Blink + écriture de l'état de la LED sur l'UART
void setup() {
  Serial.begin(9600);               // UART à 9600 bauds
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Initialisation OK");
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println(1);                // "1" -> visible dans le moniteur et le traceur série
  delay(1000);

  digitalWrite(LED_BUILTIN, LOW);
  Serial.println(0);
  delay(1000);
}
