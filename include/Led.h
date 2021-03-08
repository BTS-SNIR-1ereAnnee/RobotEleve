#ifndef LED_H
#define LED_H
#include <stdint.h>
/**
 * @brief Pilote une led
 * 
 */
class Led
{
private:
    const uint8_t pin;

public:
    /**
     * @brief Constructeur
     * 
     * @param pin le pin de la led
     */
    Led(uint8_t _pin);
    /**
     * @brief configuration du pin en OUTPUT
     * 
     */
    void setup();
    /**
     * @brief Allume la led
     * 
     */
    void allumer();
    /**
     * @brief éteint la led
     * 
     */
    void eteindre();
    //~Led();
};
#endif
