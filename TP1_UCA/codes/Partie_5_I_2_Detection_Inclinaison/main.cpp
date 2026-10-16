// Partie 5.I – Détection d'inclinaison (115200 bauds)
// X > 0.5 g -> "Inclinée à droite", X < -0.5 g -> "Inclinée à gauche"
#include <Arduino.h>
#include "Accelerometre.h"
#include "Minuterie.h"

namespace {
constexpr unsigned long DEBIT_BAUDS = 115200;
constexpr float SEUIL_G = 0.5f;  // sin(30°) = 0.5 -> seuil d'environ 30°

enum class Inclinaison { Gauche, APlat, Droite };

Accelerometre accelerometre(0x0E);
Minuterie periodeAffichage(500);

Inclinaison determinerInclinaison(float x) {
  if (x > SEUIL_G) {
    return Inclinaison::Droite;
  }
  if (x < -SEUIL_G) {
    return Inclinaison::Gauche;
  }
  return Inclinaison::APlat;
}

const char* texte(Inclinaison inclinaison) {
  switch (inclinaison) {
    case Inclinaison::Droite: return "Inclinée à droite";
    case Inclinaison::Gauche: return "Inclinée à gauche";
    default:                  return "A plat";
  }
}
}  // namespace

void setup() {
  Serial.begin(DEBIT_BAUDS);
  delay(100);
  // 50 Hz, ±2 g suffit : on mesure la projection de la gravité (|X| <= 1 g)
  if (!accelerometre.begin(50, 2)) {
    Serial.println("Failed to initialize IMU.");
    for (;;) {
    }
  }
  accelerometre.veille(false);  // accéléromètre actif en continu
  Serial.println("IMU initialized.");
}

void loop() {
  if (!periodeAffichage.estEcoulee()) {
    return;
  }
  const float x = accelerometre.lire().x;

  Serial.print("X = ");
  Serial.print(x, 3);
  Serial.print(" g  -> ");
  Serial.println(texte(determinerInclinaison(x)));
}
