// Étape 2.2 – Entrée série : l'utilisateur saisit le délai de clignotement (0..9 s)
// Version du TP, avec en plus la vérification que le caractère reçu est bien un chiffre.
unsigned long blinkDelay = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  while (true) {
    Serial.println("Please enter the blink delay (0..9) in (s): ");
    while (!Serial.available());          // attente d'un caractère
    char c = Serial.read();
    while (Serial.available()) Serial.read(); // vide le buffer (\r, \n…)
    if (c >= '0' && c <= '9') {
      blinkDelay = (c - '0') * 1000UL;    // ASCII -> nombre, puis en ms
      break;
    }
    Serial.println("Entree invalide, recommencez.");
  }
  Serial.print("Delai = ");
  Serial.print(blinkDelay);
  Serial.println(" ms");
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(blinkDelay);
  digitalWrite(LED_BUILTIN, LOW);
  delay(blinkDelay);
}
