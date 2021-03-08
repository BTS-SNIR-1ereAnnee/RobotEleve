#ifndef SUIVEURDELIGNE_H
#define SUIVEURDELIGNE_H
#include "QTRSensors.h"
class SuiveurDeLigne: private QTRSensors
{
private:
    uint8_t nbCapteurs;      // nombre de capteurs sur le suiveur
    uint8_t *pins = nullptr;      // nombre de capteurs sur le suiveur
    

    
public:
    SuiveurDeLigne(uint8_t *pins,uint8_t nbCapteurs);
    ~SuiveurDeLigne();
    void setup();
    void calibrer();
    void lireValeurs();

    uint8_t getNbCapteurs() const;
    uint16_t *valeurs;
    uint16_t position;

    void _debug();
};



#endif