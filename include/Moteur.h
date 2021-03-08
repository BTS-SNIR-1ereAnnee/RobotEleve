#ifndef MOTEUR_H
#define MOTEUR_H
#include <stdint.h>
class Moteur
{
private:
    uint8_t pinSens;
    uint8_t pinPWM;
    uint8_t pwm;
    const float rapportReduction;
    bool sens; //valeur pin de sens
    bool running;
    
    bool valSensAvant;

public:
    
    //permet de donner uniquement le sens avant ou arriere cf: setSens()
    // Avant: le robot avance Arriere : le robot recul
    typedef enum {
        Avant,Arriere
    } SENS;
    Moteur(uint8_t pinSens, uint8_t pinPWM, float rapportReduction,bool valSensAvant);
    void setup();
    void run();
    void stop();
    bool isRunning();

    uint8_t getPWM();
    void setPWM(int val);
    SENS getSens();
    void setSens(SENS sens);
    float getRapportDeReduction();
    ~Moteur();
};
#endif
