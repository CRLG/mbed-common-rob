/*! \file CGlobale.h
        \brief Classe qui contient toute l'application
*/
#ifndef _GLOBALE_H_
#define _GLOBALE_H_

#include "ia.h"
#include "CAsservissement.h"
#include "CRoues.h"
#include "CLaBotBox.h"
#include "CCapteurs.h"
#include "CElectrobot.h"
#include "CLeds.h"
#include "CLed.h"
#include "CEEPROM.h"
#include "CServoMoteurSD20.h"
#include "CServoMoteurAX.h"
#include "CMoteurs.h"
#include "CAsservissementSulfateuse.h"
#include "CAsservissementChariot.h"
#include "MessengerXbeeNetwork.h"
#include "PowerElectrobot.h"
#include "CTelemetres.h"
#include "CDetectionObstaclesBase.h"
#include "kmar.h"


typedef enum {
    MODE_AUTONOME = 0,
    MODE_PILOTE_LABOTBOX,
    MODE_PILOTE_TERMINAL
}tModeFonctionnement;

// Pour le séquenceur de tâche
#define PERIODE_TICK    (10)
#define TEMPO_10msec    (10/PERIODE_TICK)
#define TEMPO_20msec    (20/PERIODE_TICK)
#define TEMPO_50msec    (50/PERIODE_TICK)
#define TEMPO_100msec   (100/PERIODE_TICK)
#define TEMPO_200msec   (200/PERIODE_TICK)
#define TEMPO_500msec   (500/PERIODE_TICK)
#define TEMPO_1sec      (1000/PERIODE_TICK)
#define TEMPO_2sec      (2000/PERIODE_TICK)
#define TEMPO_5sec      (5000/PERIODE_TICK)
#define TEMPO_10sec     (10000/PERIODE_TICK)
#define TEMPO_15sec     (15000/PERIODE_TICK)

#define POWER_ELECTROBOT_I2C_ADDR 0x54

// -----------------------------
//! Classe de gestion des options d'exécution passees en ligne de commande
class CGlobale {
public :
    //! Le mode de fonctionnement (autonome ou piloté via Anaconbot)
    unsigned int ModeFonctionnement;

    //le temps max de gonflage du ballon
    unsigned int TempsMaxGonflage;

    //! Le match à  jouer
    IA m_modelia;
    //! La gestion des roues gauches et droites
    CRoues m_roues;
    //! La gestion d'Anaconbot
    CLaBotBox m_LaBotBox;
    //! La gestion des capteurs
    CElectrobot m_electrobot;
    //! Le gestionnaire d'EEPROM
    CEEPROM m_eeprom;
    //! La gestion des Led
    CLed m_led1;
    CLed m_led2;
    CLed m_led3;
    CLed m_led4;
    CLeds m_leds;
    //! L'asservissement de vitesse/position du robot
    // ATTENTION : l'instance de la classe asservisement doit être mise après l'instance de eeprom car CAsservissement utilise CEEPROM dans son constructeur
    CAsservissement m_asservissement;
    //! Carte PowerElectrobot
    PowerElectrobot m_power_electrobot;
    //! Gestion des servos moteurs controlés par le SD20
    CServoMoteurSD20 m_servos_sd20;
    //! Gestion des servos moteurs AX
    CServoMoteurAX m_servos_ax;
    //! Gestion des moteurs
    CMoteurs m_moteurs;
    //! Gestion des télémètres
    CTelemetres m_telemetres;
    //! Gestion des détections d'obstacles (à priori l'algo de la classe de base suffit).
    CDetectionObstaclesBase m_detection_obstacles;
    //! Gestion des capteurs
    CCapteurs m_capteurs;

    //! Gestion de l'asservissement de la sulfateuse
    CAsservissementSulfateuse m_asservissement_sulfateuse;

    //! Gestion de l'asservissement du chariot
    CAsservissementChariot m_asservissement_chariot;

    MessengerXbeeNetwork m_messenger_xbee_ntw;

    CKmar       m_kmar;

    //debug
    float m_x_debug, m_y_debug, m_teta_debug;

    //camera
    int m_distance_camera;

    // Charge CPU
    unsigned long m_cpu_overload_counter;            // indicateur de surcharge CPU
    unsigned long m_cpu_load_delta_t;       // delta T entre les 2 derniers appels de la tache surveillee
    unsigned long m_cpu_load_last_time_us;

    CGlobale();
    ~CGlobale();

    //! Point d'entree pour lancer l'application
    void Run(void);


    //!  Le programme d'IRQ qui gere le timer
    void IRQ_Tick_ModeAutonome(void);
    //!  Le programme d'IRQ qui gere le timer
    void IRQ_Tick_ModePiloteLaBotBox(void);
    //!  Le programme d'IRQ qui gere le timer
    void IRQ_Tick_ModePiloteTerminal(void);


private : 
    //! Le tick du sequenceur de tache
    unsigned int Tick;


    //! Gestion du mode autonome
    void ModeAutonome(void);
    //! Sequenceur de taches en mode autonome
    void SequenceurModeAutonome(void);
    //! Sequenceur de taches en mode pilote par Anaconbot
    void SequenceurModePiloteLaBotBox(void);
    //! Sequenceur de taches en mode pilote par teminal RS232
    void SequenceurModePiloteTerminal(void);



    //! Gestion du mode piloté via Anaconbot
    void ModePiloteLaBotBox(void);
    //! Reception RS232 en IRQ
    //void ReceiveRS232_ModePiloteLaBotBox(void);
    //! Verifie et traite la reception de trames d'Anaconbot
    //void CheckReceptionTrame(void);
    //! Envoie les trames vers LABOTBOX
    //void SendTramesLaBotBox(void);

    //! Gestion du mode piloté par terminal
    void ModePiloteTerminal(void);
    //! Reception RS232 en IRQ
    void ReceiveRS232_ModePiloteTerminal(void);

    //! Lecture eeprom
    void readEEPROM();

    //! Calcul de la surcharge CPU
    void RefreshIndicateurSurchargeCPU();
};


extern CGlobale Application;


#endif 



