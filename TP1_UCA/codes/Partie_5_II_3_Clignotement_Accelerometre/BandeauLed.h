#pragma once
#include <Arduino.h>
#include <FastLED.h>

// Les 21 LEDs RGB WS2812 de la carte UCA (ligne de données sur D4).
class BandeauLed {
public:
  static constexpr uint8_t NB_LEDS = 21;
  static constexpr uint8_t BROCHE_DONNEES = 4;

  void begin(uint8_t luminosite = 84);
  void definir(uint8_t index, const CRGB& couleur);
  void remplir(const CRGB& couleur);
  void attenuer(uint8_t facteur);  // multiplie chaque LED par facteur/256
  void afficher();

private:
  CRGB leds_[NB_LEDS];
};
