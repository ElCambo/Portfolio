#pragma once
#include <Arduino.h>

// Lit de façon non bloquante un nombre entier positif saisi sur un flux série
// (plusieurs chiffres, validé par la touche Entrée).
class LecteurNombre {
public:
  explicit LecteurNombre(Stream& flux);

  // Renvoie true quand un nombre complet a été reçu ; il est alors écrit dans 'valeur'.
  bool lire(unsigned long& valeur);

private:
  Stream& flux_;
  unsigned long accumulateur_;
  bool chiffreRecu_;
};
