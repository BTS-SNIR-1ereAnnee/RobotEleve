#ifndef ROBOT_H
#define ROBOT_H
#include "BlocMoteur.h"
#include "Lidar.h"
#include "Led.h"
#include "SuiveurDeLigne.h"

class Robot
{
public:

    /**
     * @brief Etats possibles pour l'asservissement du robot en positon
     *          - ATTENTE_POSITION  : blocG ou BlocD n'ont pas atteint leur consignes respectives
     *          - POSITION_ATTEINTE : blocG et BlocD ont atteint leur consignes respectives
     * 
     */
    enum ETAT_POSITION {ATTENTE_POSITION,POSITION_ATTEINTE};
    /**
     * @brief Mode d'asservissement
     *          - ASSERVISSEMENT_POSITION : asservissement en postion (suppose l'asservissement en vitesse )
     *          - ASSERVISSEMENT_VITESSE  : asservissement en vitesse uniquement
     * 
     */
    enum MODE_ASSERVISSEMENT {ASSERVISSEMENT_POSITION,ASSERVISSEMENT_VITESSE};
    /**
     * @brief Disponnibilité pour de nouvelles commandes
     *          - EN_ATTENTE prêt pour de nouvelle commande
     *          - OCCUPE traitement d'une commande en cours
     * 
     */
    enum ETAT_ROBOT {EN_ATTENTE, OCCUPE, EN_PAUSE};


private:
    // bloc moteurs : moteur + reducteur + encodeur + roue
    BlocMoteur blocG;
    BlocMoteur blocD;
    Lidar lidar;
    SuiveurDeLigne suiveurLigne;
    Led ledCarte;
    MODE_ASSERVISSEMENT modeAsservissement;
    ETAT_POSITION etatPosition;
    ETAT_ROBOT etatRobot;

    
public:
    
    /**
     * @brief Construit un nouveau Robot:: Robot object
     *         - par défaut asservissement en position
     * 
     * @param _blocG le bloc moteur gauche
     * @param _blocD le bloc moteur droit
     * @param _lidar le lidar
     * @param _suiveur le suiveur de ligne
     * @param _ledCarte la led
     */
    Robot(BlocMoteur _blocG,BlocMoteur _blocD, Lidar _lidar, SuiveurDeLigne _suiveur, Led _ledCarte);
    /**
     * @brief Calibrage du suiveur signalé par la led
     * 
     */
    void initSuiveur();
    /**
     * @brief setup des élements :
     *          - led carte
     *          - lidar
     *          - lidar
     *          - blocs moteurs
     * 
     */
    void setup();
    /**
     * @brief asservissement en vitesse et/ou position
     * 
     */
    void asservir();
    /**
     * @brief fait tourner le robot sur lui même
     * 
     * @param angle angle à atteindre
     */
    void tourner(int angle);
    /**
     * @brief Avance en ligne droite de deplacement mm
     * 
     * @param deplacement déplacement en mm
     */
    void avancer(int deplacement);
    void stop();
    bool isPositionAtteinte();
    Robot::ETAT_ROBOT getEtatRobot() const;
    ~Robot();
};



#endif