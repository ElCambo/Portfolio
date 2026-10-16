// Étape 4.3 – Capteur de lumière LTR-303A (I2C) – moniteur série à 115200 bauds
#include "Adafruit_LTR329_LTR303.h"

Adafruit_LTR303 ltr = Adafruit_LTR303();

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    delay(10);
  }
  Serial.println("Adafruit LTR-303 simple test");

  if (!ltr.begin()) {
    Serial.println("Couldn't find LTR sensor!");
    while (1) delay(10);
  }
  Serial.println("Found LTR sensor!");

  ltr.setGain(LTR3XX_GAIN_1);                   // gain x1
  ltr.setIntegrationTime(LTR3XX_INTEGTIME_50);  // intégration 50 ms
  ltr.setMeasurementRate(LTR3XX_MEASRATE_50);   // une mesure toutes les 50 ms
}

void loop() {
  bool valid;
  uint16_t visible_plus_ir, infrared;

  if (ltr.newDataAvailable()) {
    valid = ltr.readBothChannels(visible_plus_ir, infrared);
    if (valid) {
      Serial.print("CH0 Visible + IR: ");
      Serial.print(visible_plus_ir);
      Serial.print("\t\tCH1 Infrared: ");
      Serial.println(infrared);
    }
  }
  delay(1000);
}
