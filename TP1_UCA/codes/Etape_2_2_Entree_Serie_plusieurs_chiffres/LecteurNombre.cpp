#include "LecteurNombre.h"

LecteurNombre::LecteurNombre(Stream& flux) : flux_(flux), accumulateur_(0), chiffreRecu_(false) {}

bool LecteurNombre::lire(unsigned long& valeur) {
  while (flux_.available() > 0) {
    const char c = static_cast<char>(flux_.read());

    if (c >= '0' && c <= '9') {
      accumulateur_ = accumulateur_ * 10 + static_cast<unsigned long>(c - '0');  // ASCII -> chiffre
      chiffreRecu_ = true;
    } else if ((c == '\n' || c == '\r') && chiffreRecu_) {
      valeur = accumulateur_;
      accumulateur_ = 0;
      chiffreRecu_ = false;
      return true;
    }
    // Les autres caractères sont ignorés
  }
  return false;
}
