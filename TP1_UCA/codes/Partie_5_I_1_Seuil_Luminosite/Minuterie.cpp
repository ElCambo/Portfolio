#include "Minuterie.h"

Minuterie::Minuterie(unsigned long periodeMs) : periodeMs_(periodeMs), precedent_(0) {}

bool Minuterie::estEcoulee() {
  const unsigned long maintenant = millis();
  // Soustraction non signée : reste correcte lors du débordement de millis() (~49,7 jours)
  if (maintenant - precedent_ >= periodeMs_) {
    precedent_ = maintenant;
    return true;
  }
  return false;
}

void Minuterie::setPeriode(unsigned long periodeMs) {
  periodeMs_ = periodeMs;
}

unsigned long Minuterie::periode() const {
  return periodeMs_;
}
