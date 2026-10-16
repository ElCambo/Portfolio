// Partie 5.II – Clignotement des LEDs RGB synchronisé avec l'accéléromètre
// X > 1 g -> rouge, Y > 1 g -> vert, Z > 1 g -> bleu (les couleurs s'additionnent si plusieurs axes)
#include <FastLED.h>
#include "kxtj3-1057.h"

#define NUM_LEDS 21
#define DATA_PIN 4
#define SEUIL_G 1.0
const unsigned long DEMI_PERIODE = 200;  // ms : 200 ms allumé / 200 ms éteint

CRGB leds[NUM_LEDS];
KXTJ3 myIMU(0x0E);

void setup() {
  Serial.begin(115200);
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(84);
  FastLED.clear(true);

  // Plage ±4 g pour pouvoir mesurer au-delà de 1 g sans saturer
  if (myIMU.begin(50, 4, false) != IMU_SUCCESS) {
    Serial.println("Failed to initialize IMU.");
    while (true);
  }
  myIMU.standby(false);
  Serial.println("IMU initialized.");
}

void loop() {
  static unsigned long previousMillis = 0;
  static bool allume = false;

  float x = myIMU.axisAccel(X);
  float y = myIMU.axisAccel(Y);
  float z = myIMU.axisAccel(Z);

  CRGB couleur = CRGB::Black;
  if (x > SEUIL_G) couleur += CRGB::Red;
  if (y > SEUIL_G) couleur += CRGB::Green;
  if (z > SEUIL_G) couleur += CRGB::Blue;

  if (millis() - previousMillis >= DEMI_PERIODE) {
    previousMillis = millis();
    allume = !allume;

    fill_solid(leds, NUM_LEDS, allume ? couleur : CRGB::Black);
    FastLED.show();

    Serial.print("X="); Serial.print(x, 2);
    Serial.print(" Y="); Serial.print(y, 2);
    Serial.print(" Z="); Serial.println(z, 2);
  }
}
