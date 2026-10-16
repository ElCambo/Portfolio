// Étape 2.2 – Entrée série : l'utilisateur saisit le délai de clignotement (0..9 s)
#include <Arduino.h>
#include "Led.h"

namespace {
constexpr unsigned long DEBIT_BAUDS = 9600;
Led ledBleue(LED_BUILTIN);
unsigned long delaiMs = 1000;

// Attend un chiffre valide sur le port série et le renvoie (0..9)
uint8_t demanderChiffre() {
  for (;;) {
    Serial.println("Please enter the blink delay (0..9) in (s): ");
    while (!Serial.available()) {
      // attente active d'un caractère
    }
    const char c = static_cast<char>(Serial.read());
    while (Serial.available()) {
      Serial.read();  // vide le buffer (\r, \n...)
    }
    if (c >= '0' && c <= '9') {
      return static_cast<uint8_t>(c - '0');  // conversion ASCII -> nombre
    }
    Serial.println("Entree invalide, recommencez.");
  }
}
}  // namespace

void setup() {
  Serial.begin(DEBIT_BAUDS);
  ledBleue.begin();

  delaiMs = demanderChiffre() * 1000UL;  // secondes -> millisecondes
  Serial.print("Delai = ");
  Serial.print(delaiMs);
  Serial.println(" ms");
}

void loop() {
  ledBleue.allumer();
  delay(delaiMs);
  ledBleue.eteindre();
  delay(delaiMs);
}
