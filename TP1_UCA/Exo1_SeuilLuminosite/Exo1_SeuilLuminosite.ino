// Partie 5.I – Seuil de luminosité
// Les 21 LEDs RGB s'allument en rouge quand la luminosité ambiante dépasse 500 lux,
// et un message est affiché sur le moniteur série (115200 bauds).
#include <FastLED.h>
#include "Adafruit_LTR329_LTR303.h"

#define NUM_LEDS 21
#define DATA_PIN 4
#define SEUIL_LUX 500.0

CRGB leds[NUM_LEDS];
Adafruit_LTR303 ltr = Adafruit_LTR303();

// Conversion des comptes bruts en lux (formule de la datasheet LTR-303, gain x1, intégration 100 ms)
float calculLux(uint16_t ch0, uint16_t ch1) {
  if (ch0 + ch1 == 0) return 0;
  float ratio = (float)ch1 / (ch0 + ch1);
  if (ratio < 0.45) return 1.7743 * ch0 + 1.1059 * ch1;
  if (ratio < 0.64) return 4.2785 * ch0 - 1.9548 * ch1;
  if (ratio < 0.85) return 0.5926 * ch0 + 0.1185 * ch1;
  return 0;
}

void setup() {
  Serial.begin(115200);
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(84);
  FastLED.clear(true);

  if (!ltr.begin()) {
    Serial.println("Capteur LTR-303 introuvable !");
    while (1) delay(10);
  }
  ltr.setGain(LTR3XX_GAIN_1);
  ltr.setIntegrationTime(LTR3XX_INTEGTIME_100);
  ltr.setMeasurementRate(LTR3XX_MEASRATE_500);
  Serial.println("Seuil de luminosite : pret");
}

void loop() {
  uint16_t visible_plus_ir, infrared;

  if (ltr.newDataAvailable() && ltr.readBothChannels(visible_plus_ir, infrared)) {
    float lux = calculLux(visible_plus_ir, infrared);

    Serial.print("Visible+IR = ");
    Serial.print(visible_plus_ir);
    Serial.print("  IR = ");
    Serial.print(infrared);
    Serial.print("  Lux = ");
    Serial.println(lux, 1);

    if (lux > SEUIL_LUX) {
      fill_solid(leds, NUM_LEDS, CRGB::Red);
      Serial.println("Luminosite > 500 lux : LEDs rouges allumees");
    } else {
      fill_solid(leds, NUM_LEDS, CRGB::Black);
    }
    FastLED.show();
  }
  delay(500);
}
