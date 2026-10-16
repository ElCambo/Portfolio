// Partie 5.II – Simulation d'une alerte IoT
// a. Inclinaison dangereuse : |accélération| > 2 g sur n'importe quel axe
// b. Surchauffe             : température > 40 °C
// c. Obscurité totale       : luminosité < 10 lux
// Format : "Alerte : [Type d'alerte] à [millis] ms"
// Une alerte est émise au moment où la condition devient vraie (front montant),
// pour ne pas inonder le moniteur série tant que la condition reste vraie.
#include <Wire.h>
#include "SHTSensor.h"
#include "Adafruit_LTR329_LTR303.h"
#include "kxtj3-1057.h"

SHTSensor sht;
Adafruit_LTR303 ltr = Adafruit_LTR303();
KXTJ3 myIMU(0x0E);

bool alerteChoc = false, alerteChaud = false, alerteNoir = false;

float calculLux(uint16_t ch0, uint16_t ch1) {
  if (ch0 + ch1 == 0) return 0;
  float ratio = (float)ch1 / (ch0 + ch1);
  if (ratio < 0.45) return 1.7743 * ch0 + 1.1059 * ch1;
  if (ratio < 0.64) return 4.2785 * ch0 - 1.9548 * ch1;
  if (ratio < 0.85) return 0.5926 * ch0 + 0.1185 * ch1;
  return 0;
}

void envoyerAlerte(const char *type) {
  Serial.print("Alerte : ");
  Serial.print(type);
  Serial.print(" à ");
  Serial.print(millis());
  Serial.println(" ms");
}

// Émet l'alerte uniquement lors du passage faux -> vrai
void verifier(bool condition, bool &etat, const char *type) {
  if (condition && !etat) envoyerAlerte(type);
  etat = condition;
}

void setup() {
  Wire.begin();
  Serial.begin(115200);
  delay(1000);

  if (!sht.init()) Serial.println("SHTC3 : init failed");
  if (!ltr.begin()) Serial.println("LTR-303 : introuvable");
  ltr.setGain(LTR3XX_GAIN_1);
  ltr.setIntegrationTime(LTR3XX_INTEGTIME_100);
  ltr.setMeasurementRate(LTR3XX_MEASRATE_100);

  // Plage ±8 g : avec ±2 g la mesure sature à 2 g et le seuil "> 2 g" ne serait jamais atteint
  if (myIMU.begin(100, 8, false) != IMU_SUCCESS) Serial.println("KXTJ3 : init failed");
  myIMU.standby(false);

  Serial.println("Systeme IoT pret");
}

void loop() {
  // Accéléromètre : lu toutes les 20 ms pour ne pas rater un choc bref
  float ax = myIMU.axisAccel(X), ay = myIMU.axisAccel(Y), az = myIMU.axisAccel(Z);
  verifier(fabs(ax) > 2.0 || fabs(ay) > 2.0 || fabs(az) > 2.0, alerteChoc, "Inclinaison dangereuse");

  // Température et lumière : toutes les 500 ms
  static unsigned long previousMillis = 0;
  if (millis() - previousMillis >= 500) {
    previousMillis = millis();

    if (sht.readSample()) verifier(sht.getTemperature() > 40.0, alerteChaud, "Surchauffe");

    uint16_t ch0, ch1;
    if (ltr.readBothChannels(ch0, ch1)) verifier(calculLux(ch0, ch1) < 10.0, alerteNoir, "Obscurité totale");
  }
  delay(20);
}
