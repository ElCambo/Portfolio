// Partie 5.II – Station météo embarquée
// a. Affiche température, humidité et luminosité toutes les 5 s
// b. T > 30 °C et HR < 30 %  -> "Risque de sécheresse"
// c. Luminosité < 100 lux    -> "Nuit détectée"
#include <Wire.h>
#include "SHTSensor.h"
#include "Adafruit_LTR329_LTR303.h"

const unsigned long PERIODE = 5000;  // ms

SHTSensor sht;
Adafruit_LTR303 ltr = Adafruit_LTR303();

float calculLux(uint16_t ch0, uint16_t ch1) {
  if (ch0 + ch1 == 0) return 0;
  float ratio = (float)ch1 / (ch0 + ch1);
  if (ratio < 0.45) return 1.7743 * ch0 + 1.1059 * ch1;
  if (ratio < 0.64) return 4.2785 * ch0 - 1.9548 * ch1;
  if (ratio < 0.85) return 0.5926 * ch0 + 0.1185 * ch1;
  return 0;
}

void setup() {
  Wire.begin();
  Serial.begin(115200);
  delay(1000);

  if (!sht.init()) Serial.println("SHTC3 : init failed");
  if (!ltr.begin()) Serial.println("LTR-303 : introuvable");
  ltr.setGain(LTR3XX_GAIN_1);
  ltr.setIntegrationTime(LTR3XX_INTEGTIME_100);
  ltr.setMeasurementRate(LTR3XX_MEASRATE_500);

  Serial.println("Station meteo demarree");
}

void loop() {
  static unsigned long previousMillis = 0;
  if (millis() - previousMillis < PERIODE) return;  // non bloquant
  previousMillis = millis();

  Serial.println("----- Station meteo -----");

  bool shtOk = sht.readSample();
  float t = sht.getTemperature();
  float h = sht.getHumidity();
  if (shtOk) {
    Serial.print("Temperature : "); Serial.print(t, 2); Serial.println(" C");
    Serial.print("Humidite    : "); Serial.print(h, 2); Serial.println(" %");
  } else {
    Serial.println("Erreur lecture SHTC3");
  }

  uint16_t ch0, ch1;
  bool ltrOk = ltr.readBothChannels(ch0, ch1);
  float lux = calculLux(ch0, ch1);
  if (ltrOk) {
    Serial.print("Luminosite  : "); Serial.print(lux, 1); Serial.println(" lux");
  } else {
    Serial.println("Erreur lecture LTR-303");
  }

  if (shtOk && t > 30.0 && h < 30.0) Serial.println("Risque de sécheresse");
  if (ltrOk && lux < 100.0)          Serial.println("Nuit détectée");
}
