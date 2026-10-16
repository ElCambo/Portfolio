#pragma once
#include <Arduino.h>

// Alerte IoT : s'affiche une seule fois, au moment où sa condition devient vraie.
// Format : "Alerte : <type> à <millis> ms"
class Alerte {
public:
  explicit Alerte(const char* type);

  void verifier(bool condition, Print& sortie);

private:
  const char* type_;
  bool active_;
};
