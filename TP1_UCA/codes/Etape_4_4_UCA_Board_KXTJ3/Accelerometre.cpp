#include "Accelerometre.h"

Accelerometre::Accelerometre(uint8_t adresse) : imu_(adresse) {}

bool Accelerometre::begin(float frequence, uint8_t plage, bool hauteResolution) {
  return imu_.begin(frequence, plage, hauteResolution) == IMU_SUCCESS;
}

void Accelerometre::veille(bool active) {
  imu_.standby(active);
}

Acceleration Accelerometre::lire() {
  return Acceleration{imu_.axisAccel(X), imu_.axisAccel(Y), imu_.axisAccel(Z)};
}
