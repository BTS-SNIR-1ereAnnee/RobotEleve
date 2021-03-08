#ifndef __ROUE_H__
#define __ROUE_H__
/**
 * @brief les roues 
 * @todo remplacer par une struct?
 * 
 */
class Roue
{
public:
    const float diametre; //mm
    const float ecart;//mm
    Roue(float diametre, float ecart):diametre(diametre),ecart(ecart){};
};



#endif