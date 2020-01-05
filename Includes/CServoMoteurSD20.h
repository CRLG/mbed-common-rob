/*! \file CServoMoteurSD20.h
        \brief Classe qui contient la gestion des roues motrices gauche et droite
*/

#ifndef _SERVO_MOTEUR_SD20_H_
#define _SERVO_MOTEUR_SD20_H_

#include "CServoMoteurSD20Base.h"

// -----------------------------
//! Classe de gestion des options d'exécution passees en ligne de commande
class CServoMoteurSD20 : public CServoMoteurSD20Base
{
public :
    CServoMoteurSD20();

    void Init(void);
    void GestionTransfert(void);
    void setDureesMinMaxPulseSD20(unsigned int duree_min_us, unsigned int duree_max_us);

private : 
    //! Lecture de l'EEPROM
    void readEEPROM(void);
};


#endif  // _SERVO_MOTEUR_SD20_H_

