// Étape 2.2 (suite) – Lecture d'un nombre de plusieurs chiffres pendant que la LED clignote.
// Taper un délai en millisecondes puis Entrée (moniteur série à 9600 bauds, "Nouvelle ligne").
#include <Arduino.h>
#include "Led.h"
#include "Minuterie.h"
#include "LecteurNombre.h"

namespace {
constexpr unsigned long DEBIT_BAUDS = 9600;
Led ledBleue(LED_BUILTIN);
Minuterie clignotement(1000);
LecteurNombre lecteur(Serial);
}  // namespace

void setup() {
  Serial.begin(DEBIT_BAUDS);
  ledBleue.begin();
  Serial.println("Entrez un delai en ms puis Entree :");
}

void loop() {
  unsigned long nouveauDelai;
  if (lecteur.lire(nouveauDelai)) {
    clignotement.setPeriode(nouveauDelai);
    Serial.print("Nouveau delai : ");
    Serial.print(nouveauDelai);
    Serial.println(" ms");
  }

  if (clignotement.estEcoulee()) {
    ledBleue.basculer();
  }
}
