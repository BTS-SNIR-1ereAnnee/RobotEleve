#ifndef LIDAR_H
#define LIDAR_H
#include "VL53L1X.h"
class Lidar
{
private:
    VL53L1X sensor;
    unsigned int distance;         //distance mesurée par le Lidar
    unsigned int distanceMax;     //distance max mesurée par le Lidar
    unsigned int distanceSeuil; //distance seuil de l'obstacle en mm
    unsigned long dernierTempsMesure;
    ///periode de la mesure de distance en microseconde
    unsigned long periodeMesure; 
    void initLidar();
public:
    Lidar(unsigned long periodeMesure = 500000,unsigned int distanceSeuil = 200);
    void setup();
    ~Lidar();
    bool seuilAtteint();
    void mesureLoopAsservie();
    void mesureForcee();
    unsigned int getDistance();
    unsigned int getDistanceMax();
    void setDistanceMax(unsigned int val);
    void setDistanceMax();
    void setPeriodeMesure(unsigned long val);
    unsigned long getPeriodeMesure();
};


#endif