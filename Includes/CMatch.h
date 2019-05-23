/*! \file CMatch.h
        \brief Classe qui contient toute l'application
*/

#ifndef _MATCH_H_
#define _MATCH_H_

#include "../ModeleSCT/src/CPPTimerInterface.h"
#include "CMoteurs.h"
#include "CServoMoteurSD20.h"
#include "CServoMoteurAX.h"
#include "math.h"

#define SQUARE(A) (A*A)

class IA;

// -----------------------------
//! Classe de gestion des options d'exécution passees en ligne de commande
class CMatch {
#define MODEL_REFRESH_PERIOD 20 // [msec]
public :
    float m_duree;
    unsigned char m_couleur_equipe;
    unsigned char m_dde_couleur_equipe;
    unsigned char m_dde_test_actionneurs;
    unsigned char m_dde_choix_strategie;
    unsigned char m_choix_strategie;
    float m_old_cde_mot[NBRE_MAX_MOTEURS+1]; // +1 par facilité de lecture du code car l'index utilisé MOTEUR_1, ... commence à  1 et pas à  "0"
    float m_old_cde_servo[NBRE_SERVOS_SD20+1]; // +1 (même explication)
    unsigned short m_score_total;
    //tableau contenant la stratégie à appliquer

    int32_t strategie[10];

    CMatch();
    ~CMatch();

    //! Initialise les structures
    void Initialise(void);

    //! Execute un pas de calcul
    void step(void);

    //! Indique si le match est en cours ou non
    bool isMatchEnCours();
    //! Indique si le match est terminé
    bool isMatchTermine();

    //! Debug sur la RS232
    void debug(void);

    IA *m_ia;
    CPPTimerInterface m_timer_sct;
    //    IA::DefaultSCI *m_iaSCI;
    //    IA::SCI_Chariot *m_iaSCI_Chariot;
    static bool frontMontant(float prec_value, float value);

    // Détection et évitement d'obstacle
    float m_telemetre_AVG;
    float m_telemetre_AVD;
    float m_telemetre_ARG;
    float m_telemetre_ARD;
    bool m_obstacle_detecte_AVG;
    bool m_obstacle_detecte_AVD;
    bool m_obstacle_detecte_ARG;
    bool m_obstacle_detecte_ARD;
    unsigned char m_obstacle_detecte_bitfield;
    int m_obstacleDetecte;
    int m_sens_deplacement;
    unsigned short m_num_etape_evitement;
    unsigned char m_nbre_tentatives_evitement;
    bool m_evitement_en_cours;
    bool m_forcage_detect_obstacle_sans_position;
    bool m_inhibe_obstacle;
    unsigned char m_choix_strategie_evitement;

    int isObstacle(float x, float y, float teta, float speed, float sens);

    float m_distance_mem;
    float m_teta_mem;
    float m_x_pos_hold;
    float m_y_pos_hold;
    float m_teta_pos_hold;

private :
    float m_convergence_old;
    float m_convergence_rapide_old;
    int m_tirette_old;
    int m_convergence_rack_old;
    int m_convergence_rack_conf;


};

/*class methodeAsser : public GROSBOT::SCI_Ascenseur_OCB
{
public:
    void Manuel(sc_real mot_gauche, sc_real mot_droit) = 0;
};*/

#endif


