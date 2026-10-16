// Étape 4.5 – 21 LEDs RGB : effet « cylon » multicolore (57600 bauds)
#include <Arduino.h>
#include "BandeauLed.h"

namespace {
constexpr unsigned long DEBIT_BAUDS = 57600;
constexpr uint8_t FACTEUR_ATTENUATION = 250;  // 250/256 par pas
constexpr unsigned long PAS_MS = 10;

BandeauLed bandeau;
uint8_t teinte = 0;

void allumerEtAttenuer(uint8_t index) {
  bandeau.definir(index, CHSV(teinte++, 255, 255));
  bandeau.afficher();
  bandeau.attenuer(FACTEUR_ATTENUATION);
  delay(PAS_MS);
}
}  // namespace

void setup() {
  Serial.begin(DEBIT_BAUDS);
  Serial.println("resetting");
  bandeau.begin(84);
}

void loop() {
  Serial.print("x");
  for (uint8_t i = 0; i < BandeauLed::NB_LEDS; ++i) {  // aller
    allumerEtAttenuer(i);
  }
  Serial.print("x");
  for (int i = BandeauLed::NB_LEDS - 1; i >= 0; --i) {  // retour
    allumerEtAttenuer(static_cast<uint8_t>(i));
  }
}
