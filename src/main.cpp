#include <Arduino.h>
#include "QTRSensors.h" //librairie du suiveur de ligne à capteur QTR
#include <VL53L1X.h>    //bilbiothèque LIDAR VL53L1X

#include "Led.h"
#include "Moteur.h"
#include "Lidar.h"
#include "Encodeur.h"
#include "Roue.h"
#include "BlocMoteur.h"
#include "SuiveurDeLigne.h"
#include "Robot.h"



void setup()
{
  Serial.begin(115200); // Démarre la communication série pour le débugage sur le moniteur série
  
}

void loop()
{


}
