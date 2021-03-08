#ifndef ENCODEUR_H
#define ENCODEUR_H
#include <stdint.h>
/**
 * @brief Classe de Gestion d'un encodeur
 * @todo gérer l'overflow sur nbImpulsionsTotal
 * 
 */
class Encodeur
{
private:
    const uint8_t pinSens, pinCompteur, nbImpulsionsTour;
    volatile long nbImpulsionsTotal,
        temps, // le temps écoulé depuis la dernière interuption
        dernierTemps, // horodatage du dernier temps mesuré
        nbImpulsions; // le nombre d'impulsions (remis à 0 si == nbImpusionsCalcul) 
    const bool valeurAvantPinSens;
    int nbImpusionsCalcul;    


public:
    Encodeur(uint8_t pinSens, uint8_t pinCompteur,uint8_t nbImpulsionsTour,bool valeurAvantPinSens = 0,int nbImpusionsCalcul = 1);
    void setup();
    void compter();
    long getNbImpulsionsCalcul();
    uint8_t getNbImpulsionsTour();
    long getNbImpulsionsTotal();
    long getDernierTemps();
    long getTempsEcoule();
    long getTemps();
    void reset();
    ~Encodeur();
};
#endif
