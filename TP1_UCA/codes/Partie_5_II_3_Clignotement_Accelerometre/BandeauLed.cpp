#include "BandeauLed.h"

void BandeauLed::begin(uint8_t luminosite) {
  // Si les couleurs sont inversées sur la carte, remplacer RGB par GRB
  FastLED.addLeds<WS2812, BROCHE_DONNEES, RGB>(leds_, NB_LEDS);
  FastLED.setBrightness(luminosite);
  remplir(CRGB::Black);
  afficher();
}

void BandeauLed::definir(uint8_t index, const CRGB& couleur) {
  if (index < NB_LEDS) {
    leds_[index] = couleur;
  }
}

void BandeauLed::remplir(const CRGB& couleur) {
  fill_solid(leds_, NB_LEDS, couleur);
}

void BandeauLed::attenuer(uint8_t facteur) {
  for (CRGB& led : leds_) {
    led.nscale8(facteur);
  }
}

void BandeauLed::afficher() {
  FastLED.show();
}
