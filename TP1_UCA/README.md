# TP1 — Introduction à la programmation de la carte UCA

Chaque dossier de `codes/` correspond à **une étape du TP**. Ouvre le fichier `.ino` du dossier dans l'Arduino IDE (*File → Open*), puis clique sur **Téléverser**.

Réglages à faire une fois dans l'IDE : *Tools → Board → RFThings AVR Boards → **RFThings UCA***, *Board Version : **3.9 and newer (ATMega328PB)***, *Port : le port COM de la carte*.

| Étape du TP | Dossier à ouvrir | Moniteur série | Ce que tu dois observer |
|---|---|---|---|
| 1.6 Test de clignotement | [`Etape_1_6_Blink`](codes/Etape_1_6_Blink/Etape_1_6_Blink.ino) | — | La LED bleue clignote (1 s allumée / 1 s éteinte) |
| 2.1 Sortie série | [`Etape_2_1_Sortie_Serie_Blink_Mod`](codes/Etape_2_1_Sortie_Serie_Blink_Mod/Etape_2_1_Sortie_Serie_Blink_Mod.ino) | 9600 | « Initialisation OK » puis 1 / 0 ; signal carré dans le traceur série |
| 2.2 Entrée série (code du TP) | [`Etape_2_2_Entree_Serie_1_chiffre`](codes/Etape_2_2_Entree_Serie_1_chiffre/Etape_2_2_Entree_Serie_1_chiffre.ino) | 9600 | Taper un chiffre de 0 à 9 → la LED clignote avec ce délai en secondes |
| 2.2 Entrée série (plusieurs chiffres) | [`Etape_2_2_Entree_Serie_plusieurs_chiffres`](codes/Etape_2_2_Entree_Serie_plusieurs_chiffres/Etape_2_2_Entree_Serie_plusieurs_chiffres.ino) | 9600 | Taper un délai en ms (ex. 250) + Entrée → le clignotement change |
| 3.1 Fonction millis() | [`Etape_3_1_Millis`](codes/Etape_3_1_Millis/Etape_3_1_Millis.ino) | — | La LED clignote toutes les 1 s sans `delay()` |
| 4.2 Capteur SHTC3 | [`Etape_4_2_UCA_Board_SHTC3`](codes/Etape_4_2_UCA_Board_SHTC3/Etape_4_2_UCA_Board_SHTC3.ino) | 9600 | Humidité (RH) et température (T) chaque seconde |
| 4.3 Capteur LTR-303 | [`Etape_4_3_UCA_Board_LTR303`](codes/Etape_4_3_UCA_Board_LTR303/Etape_4_3_UCA_Board_LTR303.ino) | **115200** | Valeurs CH0 (visible + IR) et CH1 (IR) |
| 4.4 Accéléromètre KXTJ3 | [`Etape_4_4_UCA_Board_KXTJ3`](codes/Etape_4_4_UCA_Board_KXTJ3/Etape_4_4_UCA_Board_KXTJ3.ino) | **115200** | X, Y, Z en g (Z ≈ 1 à plat) ; bouger la carte |
| 4.5 LEDs RGB | [`Etape_4_5_UCA_Board_RGBLED`](codes/Etape_4_5_UCA_Board_RGBLED/Etape_4_5_UCA_Board_RGBLED.ino) | 57600 | Effet arc‑en‑ciel aller‑retour sur les 21 LEDs |
| 5.I Seuil de luminosité | [`Partie_5_I_1_Seuil_Luminosite`](codes/Partie_5_I_1_Seuil_Luminosite/Partie_5_I_1_Seuil_Luminosite.ino) | **115200** | LEDs rouges + message si > 500 lux (éclairer avec un téléphone) |
| 5.I Détection d'inclinaison | [`Partie_5_I_2_Detection_Inclinaison`](codes/Partie_5_I_2_Detection_Inclinaison/Partie_5_I_2_Detection_Inclinaison.ino) | **115200** | « Inclinée à droite / à gauche / A plat » |
| 5.II Station météo | [`Partie_5_II_1_Station_Meteo`](codes/Partie_5_II_1_Station_Meteo/Partie_5_II_1_Station_Meteo.ino) | **115200** | Données toutes les 5 s ; « Nuit détectée » si on cache le capteur |
| 5.II Alerte IoT | [`Partie_5_II_2_Alerte_IoT`](codes/Partie_5_II_2_Alerte_IoT/Partie_5_II_2_Alerte_IoT.ino) | **115200** | `Alerte : … à … ms` (secouer fort, cacher le capteur) |
| 5.II Clignotement / accélération | [`Partie_5_II_3_Clignotement_Accelerometre`](codes/Partie_5_II_3_Clignotement_Accelerometre/Partie_5_II_3_Clignotement_Accelerometre.ino) | **115200** | Rouge (X > 1 g), vert (Y > 1 g), bleu (Z > 1 g) |

## Bibliothèques à installer (Tools → Manage Libraries)

- **FastLED** (Daniel Garcia) — étape 1.5
- **arduino-sht** (Johannes Winkelmann) — SHTC3
- **Adafruit LTR329 and LTR303** (Adafruit) — LTR-303 ; accepter l'installation des dépendances
- **KXTJ3-1057** (Leonardo Bispo) — accéléromètre

## Compte rendu

Le compte rendu complet (réponses, explications et code) est dans [`rapport/`](rapport/) en PDF, Word (`.docx`, à compléter avec vos noms et votre groupe) et Markdown.

> Si les couleurs des LEDs sont inversées (rouge affiché en vert), remplacer `RGB` par `GRB` dans `FastLED.addLeds<...>`.
