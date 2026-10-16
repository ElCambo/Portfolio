// Partie 5.II – Clignotement des LEDs RGB selon l'accélération (115200 bauds)
// X > 1 g -> rouge, Y > 1 g -> vert, Z > 1 g -> bleu (les couleurs s'additionnent)
#include <Arduino.h>
#include "Accelerometre.h"
#include "BandeauLed.h"
#include "Minuterie.h"

namespace {
constexpr unsigned long DEBIT_BAUDS = 115200;
constexpr float SEUIL_G = 1.0f;
constexpr unsigned long DEMI_PERIODE_MS = 200;  // 200 ms allumé / 200 ms éteint

Accelerometre accelerometre(0x0E);
BandeauLed bandeau;
Minuterie clignotement(DEMI_PERIODE_MS);
bool allume = false;

CRGB couleurPour(const Acceleration& a) {
  CRGB couleur = CRGB::Black;
  if (a.x > SEUIL_G) couleur += CRGB::Red;
  if (a.y > SEUIL_G) couleur += CRGB::Green;
  if (a.z > SEUIL_G) couleur += CRGB::Blue;
  return couleur;
}
}  // namespace

void setup() {
  Serial.begin(DEBIT_BAUDS);
  bandeau.begin(84);

  // Plage ±4 g pour mesurer au-delà de 1 g sans saturer
  if (!accelerometre.begin(50, 4)) {
    Serial.println("Failed to initialize IMU.");
    for (;;) {
    }
  }
  accelerometre.veille(false);
  Serial.println("IMU initialized.");
}

void loop() {
  if (!clignotement.estEcoulee()) {
    return;
  }
  const Acceleration a = accelerometre.lire();
  allume = !allume;

  bandeau.remplir(allume ? couleurPour(a) : CRGB(CRGB::Black));
  bandeau.afficher();

  Serial.print("X=");
  Serial.print(a.x, 2);
  Serial.print(" Y=");
  Serial.print(a.y, 2);
  Serial.print(" Z=");
  Serial.println(a.z, 2);
}
