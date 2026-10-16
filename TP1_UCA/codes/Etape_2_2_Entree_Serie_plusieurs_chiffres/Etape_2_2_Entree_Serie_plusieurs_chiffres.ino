// Étape 2.2 (suite) – Lecture d'un nombre de plusieurs chiffres (ex. "12") avec une boucle while,
// pendant que le programme tourne (lecture dans loop()). Délai saisi en millisecondes.
unsigned long blinkDelay = 1000;
unsigned long previousMillis = 0;
long saisie = 0;
bool chiffreRecu = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Entrez un delai en ms puis Entree :");
}

void loop() {
  // Lecture caractère par caractère tant que le buffer n'est pas vide
  while (Serial.available() > 0) {
    char c = Serial.read();
    if (c >= '0' && c <= '9') {
      saisie = saisie * 10 + (c - '0');
      chiffreRecu = true;
    } else if ((c == '\n' || c == '\r') && chiffreRecu) {
      blinkDelay = saisie;
      Serial.print("Nouveau delai : ");
      Serial.print(blinkDelay);
      Serial.println(" ms");
      saisie = 0;
      chiffreRecu = false;
    }
  }

  // Clignotement non bloquant avec millis()
  if (millis() - previousMillis >= blinkDelay) {
    previousMillis = millis();
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
}
