#ifndef __BLOCMOTEUR_H__
#define __BLOCMOTEUR_H__
#include "Moteur.h"
#include "Encodeur.h"
#include "Roue.h"
/**
 * @brief gestion d'un bloc moteur: 
 *          - moteur + reducteur
 *          - encodeur
 *          - asservissement vitesse/position
 * @todo passer tout ce qui peut l'être en statique (partage entre les objet de roues param rafraichessement...) class scope
 * @todo faire une classe pseudoServoMoteur composée d'un encodeur et d'un moteur
 *
 */
class BlocMoteur
{
public:
typedef enum {Avant,Arriere} SENS;
    /**
     * @brief Construit un nouveau Bloc Moteur
     * 
     * @param moteur reférence objet moteur
     * @param encodeur référence objet encodeur
     * 
     * @todo utiliser constructeur par délégation
     */
    
    BlocMoteur(Moteur &moteur, Encodeur &encodeur, Roue &roue, 
        float vMin = 0.1, float vMax = 1, 
        float precisionPosition = 1, 
        float distanceAcceleration = 10, 
        float positionMax = 2000, float positionMin = 2000, 
        float pasPosition = 20);
    // BlocMoteur(uint8_t pinMotSens,
    //            uint8_t pinMotPWM,
    //            float rapportReduction,
    //            uint8_t pinEncSens,
    //            uint8_t pinEncCompteur,
    //            uint8_t nbImpulsionsTour,
    //            int nbImpusionsCalcul = 1,
    //            bool valeurAvantPinSens = 0);
    void setup();
    void setSens(SENS sens);
    void setConsigneVitesse(float consigne);
    void setConsignePosition(float consigne);
    void setPosition(float position);
    void reset();
    float getVitesseMin();
    void loopVitesseAsservie();
    void loopPositionAsservie(); 

    bool isPositionAtteinte() const;
    float getPosition() const;
    float getConsignePosition() const;
    

    ~BlocMoteur();

    Roue &getRoue() const;

private:
    
    Moteur &moteur;
    Encodeur &encodeur;
    Roue &roue;
    float conversionTempsVitesse;                  //converti le temps (micros) en vitesse (tr/s); vitesse=conversion/temps
    float vitesseMax;                              // tr/s A ADAPTER EN FONCTION DU MOTEUR OU DU COMPORTEMENT VOULU entre 50% et 80% de la vitesse à vide
    float vitesseMin;                              // tr/s A choisir en fonction de l'utilisation, en dessous le moteur s'arrête
    unsigned long dureeMaxRafraichissementVitesse; //duree max entre 2 calculs de la vitesse, calculée dans le set up
    unsigned long dureeMinRafraichissementVitesse; //duree min entre 2 calculs de la vitesse, calculée dans le set up
    unsigned long dureeVitesseNulle;               //duree sans nouvelle implusion à partir de laquelle on considère que la vitesse est nulle
    unsigned long periodeAsservissementVitesse;    //periode de l'asservissement numérique de la vitesse en microseconde
    unsigned long dernierTempsAsservissementVitesse;
    SENS sens;
    float vitesse;
    float consigneVitesse;
    float erreurVitesse, sommeErreursVitesse, Kp, Ki;
    float precisionPosition; // précision de la position en mm
    float position; // distance parcourue par la roue gauche en mm
    float conversionImpulsionPosition; //en mm par nombre d'impulsion total
    float distanceAcceleration = 10;//distance pour atteindre Vmax en mm
    float acceleration;//acceleration pour atteindre Vmax
    unsigned long periodeAsservissementPosition;//periode de l'asservissement numérique de la position en microseconde
    unsigned long dernierTempsAsservissementPosition;
    const float positionMax = 2000;// mm A ADAPTER EN FONCTION DU SYSTEME                                                                                                                 // mm A ADAPTER EN FONCTION DU SYSTEME
    const float positionMin = 2000;// mm A ADAPTER EN FONCTION DU SYSTEME                                                                                                                 // mm A ADAPTER EN FONCTION DU SYSTEME
    const float pasPosition = 20;//incrément de la position pour la consigne manuelle

float consignePosition;
float erreurPosition;
bool positionAtteinte;
    void controleVitesse();
    void controlePosition();
    void _debug();


};

#endif