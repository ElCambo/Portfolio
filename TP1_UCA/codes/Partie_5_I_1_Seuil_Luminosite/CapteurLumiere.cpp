#include "CapteurLumiere.h"

bool CapteurLumiere::begin(ltr329_integrationtime_t integration, ltr329_measurerate_t frequence) {
  if (!ltr_.begin()) {
    return false;
  }
  ltr_.setGain(LTR3XX_GAIN_1);
  ltr_.setIntegrationTime(integration);
  ltr_.setMeasurementRate(frequence);
  integrationMs_ = integrationEnMs(integration);
  return true;
}

bool CapteurLumiere::nouvelleDonnee() {
  return ltr_.newDataAvailable();
}

bool CapteurLumiere::lire(MesureLumiere& mesure) {
  if (!ltr_.readBothChannels(mesure.visibleIr, mesure.infrarouge)) {
    return false;
  }
  mesure.lux = calculerLux(mesure.visibleIr, mesure.infrarouge);
  return true;
}

float CapteurLumiere::integrationEnMs(ltr329_integrationtime_t integration) {
  switch (integration) {
    case LTR3XX_INTEGTIME_50:  return 50.0f;
    case LTR3XX_INTEGTIME_150: return 150.0f;
    case LTR3XX_INTEGTIME_200: return 200.0f;
    case LTR3XX_INTEGTIME_250: return 250.0f;
    case LTR3XX_INTEGTIME_300: return 300.0f;
    case LTR3XX_INTEGTIME_350: return 350.0f;
    case LTR3XX_INTEGTIME_400: return 400.0f;
    default:                   return 100.0f;
  }
}

// Formule de la datasheet LTR-303 (gain x1) : dépend du rapport IR / (visible + IR)
float CapteurLumiere::calculerLux(uint16_t ch0, uint16_t ch1) const {
  const float somme = static_cast<float>(ch0) + ch1;
  if (somme == 0.0f) {
    return 0.0f;
  }
  const float ratio = ch1 / somme;
  float lux;
  if (ratio < 0.45f) {
    lux = 1.7743f * ch0 + 1.1059f * ch1;
  } else if (ratio < 0.64f) {
    lux = 4.2785f * ch0 - 1.9548f * ch1;
  } else if (ratio < 0.85f) {
    lux = 0.5926f * ch0 + 0.1185f * ch1;
  } else {
    lux = 0.0f;
  }
  return lux / (integrationMs_ / 100.0f);  // correction du temps d'intégration
}
