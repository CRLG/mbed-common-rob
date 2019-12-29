#ifndef IA_BASE_H
#define IA_BASE_H

#include "sm_datasinterface.h"
#include "sm_inputsinterface.h"
#include "sm_outputsinterface.h"
#include "sm_statemachinebase.h"
#include "sm_main.h"
#include "sm_sequenceur.h"
#include "sm_evitement.h"
#include "sm_debuginterface.h"

class IABase
{
public:
    IABase();
    virtual ~IABase();

    void setDebugger(SM_DebugInterface* sm_debuger);

    // Interfaces
    SM_DatasInterface           m_datas_interface;
    SM_InputsInterface          m_inputs_interface;
    SM_OutputsInterface         m_outputs_interface;

    // Debugger
    SM_DebugInterface           *m_sm_debug;

    // States machines
    SM_Main                     m_sm_main;
    SM_Sequenceur               m_sm_sequenceur;
    SM_Evitement                m_sm_evitement;
/*
    SM_Autotest                 m_sm_autotest;
    SM_ActiverPhare             m_sm_activer_phare;
    SM_DeployerPavillon         m_sm_deployer_pavillon;
    SM_DeposerBoueesDansPort    m_sm_deposer_bouees_dans_port;
    SM_DetecterNordSud          m_sm_detecter_nord_sud;
    SM_Recup2BoueesZoneDepart   m_sm_recup_2_bouees_zone_depart;
    SM_Recup4BoueesChemin       m_sm_recup_4_bouees_chemin;
    SM_RecupBoueesDistributeur  m_sm_recup_bouees_distributeur;
    SM_ArriverABonPort          m_sm_arriver_a_bon_port;
*/
    // Choix d'un algo parmi plusieurs pour la sélection de la prochaine mission à exécuter
    typedef enum {
        ALGO_PERTINENT_MISSION_NEXT_INDEX = 0,
        ALGO_PERTINENT_MISSION_CHOIX_PRIORITE,              // Cas d'utilisation : dans le stand, juste avant le match, mise au point avec l'équipe adverse et décision de prendre telle ou telle stratégie (choix par lecture EEPROM)
        ALGO_PERTINENT_MISSION_SCORE_MAX,
        ALGO_PERTINENT_MISSION_DISTANCE_MIN,
        ALGO_PERTINENT_MISSION_CHEMIN_SANS_OBSTACLE
    }tAlgoNextPertinentMission;

    // API
    virtual void step() = 0;
    virtual void initAllStateMachines() = 0;
    bool isMatchEnCours();
    bool isMatchTermine();
    void stepAllStateMachines();
    void stopAllStateMachines();
    void stopAllOthersStateMachines(SM_StateMachineBase *sm_to_keep_alive);
    int getSMCOunt();
    void activeMainMission(SM_StateMachineBase *mission);
    bool isOneMainMissionActive();
    SM_StateMachineBase *activeNextPertinentMainMission(tAlgoNextPertinentMission algo);

    unsigned short getScore();

#define NBRE_MAX_STATE_MACHINES 25
    SM_StateMachineBase *m_sm_liste[NBRE_MAX_STATE_MACHINES];
protected :
    int m_state_machine_count;
};

#endif // IA_BASE_H
