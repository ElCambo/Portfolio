// Étape 4.5 – 21 LEDs RGB (WS2812) – effet « cylon » multicolore – 57600 bauds
#include <FastLED.h>

#define NUM_LEDS 21
#define DATA_PIN 4
#define CLOCK_PIN 13   // inutile pour des WS2812 (une seule ligne de données)

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(57600);
  Serial.println("resetting");
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(84);
}

void fadeall() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].nscale8(250);  // multiplie chaque composante par 250/256
  }
}

void loop() {
  static uint8_t hue = 0;
  Serial.print("x");
  for (int i = 0; i < NUM_LEDS; i++) {          // aller
    leds[i] = CHSV(hue++, 255, 255);
    FastLED.show();
    fadeall();
    delay(10);
  }
  Serial.print("x");
  for (int i = NUM_LEDS - 1; i >= 0; i--) {     // retour
    leds[i] = CHSV(hue++, 255, 255);
    FastLED.show();
    fadeall();
    delay(10);
  }
}
