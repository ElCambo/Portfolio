#include "Alerte.h"

Alerte::Alerte(const char* type) : type_(type), active_(false) {}

void Alerte::verifier(bool condition, Print& sortie) {
  if (condition && !active_) {  // front montant : faux -> vrai
    sortie.print("Alerte : ");
    sortie.print(type_);
    sortie.print(" à ");
    sortie.print(millis());
    sortie.println(" ms");
  }
  active_ = condition;
}
