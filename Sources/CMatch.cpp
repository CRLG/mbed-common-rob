/*! \file CMatch.cpp
	\brief Classe qui contient toute l'application
*/
#include "CMatch.h"
#include "mbed.h"
#include "RessourcesHardware.h"

#include "CGlobale.h"
#include "ConfigSpecifiqueCoupe.h"

//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CMatch::CMatch() 
{
    //Initialise();
}

//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CMatch::~CMatch() 
{

}


//___________________________________________________________________________
 /*!
   \brief Initialise toutes les structures de donnéess du match à  jouer

   \param --
   \return --
*/
void CMatch::Initialise(void)
{
//     _led1 = true;_led2 = false;_led3 = false;_led4 = false;wait(1);
// _led1 = false;_led2 = true;_led3 = false;_led4 = false;wait(1);
//  _led1 = false;_led2 = false;_led3 = true;_led4 = false;wait(1);
//   _led1 = false;_led2 = false;_led3 = false;_led4 = true;wait(1);
//   _led1 = false;_led2 = false;_led3 = false;_led4 = false;wait(1);
	
    //m_iaSCI=m_ia->getDefaultSCI();
    //m_iaSCI_Chariot=m_ia->getSCI_Chariot();
    for(int i=0;i<10;i++)
        strategie[i]=0;

    m_distance_mem=0;
    m_teta_mem=0;

    m_x_pos_hold=0;
    m_y_pos_hold=0;
    m_teta_pos_hold=0;

    m_duree = 0;
    m_couleur_equipe = 1;
    m_dde_couleur_equipe=1;
    m_dde_test_actionneurs = 0;
    m_dde_choix_strategie = 0;
    m_convergence_old=0;
    m_convergence_rapide_old=0;
    m_tirette_old=0;
    m_convergence_rack_old=0;
    m_convergence_rack_conf=0;

    m_obstacleDetecte=0;
    m_telemetre_AVD=Application.m_telemetres.getDistanceAVD();
    m_telemetre_ARD=Application.m_telemetres.getDistanceARD();
    m_telemetre_AVG=Application.m_telemetres.getDistanceAVG();
    m_telemetre_ARG=Application.m_telemetres.getDistanceARG();
    m_seuil_detection_obstacle = 35; // [cm] valeur par défaut historique si aucune autre valeur n'est affectée
    m_obstacle_detecte_AVG = m_telemetre_AVG<=m_seuil_detection_obstacle;
    m_obstacle_detecte_AVD = m_telemetre_AVD<=m_seuil_detection_obstacle;
    m_obstacle_detecte_ARG = m_telemetre_ARG<=m_seuil_detection_obstacle;
    m_obstacle_detecte_ARD = m_telemetre_ARD<=m_seuil_detection_obstacle;

    m_num_etape_evitement = 0;
    m_nbre_tentatives_evitement = 0;
    m_evitement_en_cours = 0;

    m_score_total = 0;
    
    // _led1 = 0;
    _led2 = 0;
    _led3 = 0;
    _led4 = 0;

    m_ia.initAllStateMachines();
    m_ia.m_inputs_interface.TE_Modele = 0.02;
    m_ia.m_sm_recup_2_bouees_zone_depart.setPrioriteExecution(0); // pour l'essai uniquement
    m_ia.m_sm_main.start();
    m_ia.m_inputs_interface.dde_test_actionneurs = 1;
}
	
//___________________________________________________________________________
 /*!
   \brief Inidique si le match est en cours

   \param --
   \return --
*/
bool CMatch::isMatchEnCours()
{
    //return (m_duree >=0.02) && (m_duree < (DUREE_MATCH-0.06));
    return m_ia.isMatchEnCours();
}

//___________________________________________________________________________
 /*!
   \brief Inidique si le match est terminé

   \param --
   \return --
*/
bool CMatch::isMatchTermine()
{
    //return (m_duree >= (DUREE_MATCH-0.06));
    return m_ia.isMatchTermine();
}


//___________________________________________________________________________
 /*!
   \brief Execute un pas de calcul du match

   \param --
   \return --
*/
void CMatch::step(void)
{
    // =====================================================================
    // Recopie les valeurs de l'environnement vers les entrées du modèle
	
    //____________________________
    //Variables de l'Ecran ou du switch
    //if(Application.m_electrobot.m_b_Etor5==1)//jaune

    //____________________________
    //capteurs US
    /* Ajouté dans IA.cpp
    m_telemetre_AVD=Application.m_telemetres.getDistanceAVD();
    m_telemetre_ARD=Application.m_telemetres.getDistanceARD();
    m_telemetre_AVG=Application.m_telemetres.getDistanceAVG();
    m_telemetre_ARG=Application.m_telemetres.getDistanceARG();

    m_obstacle_detecte_AVG = m_telemetre_AVG<=m_seuil_detection_obstacle;
    m_obstacle_detecte_AVD = m_telemetre_AVD<=m_seuil_detection_obstacle;
    m_obstacle_detecte_ARG = m_telemetre_ARG<=m_seuil_detection_obstacle;
    m_obstacle_detecte_ARD = m_telemetre_ARD<=m_seuil_detection_obstacle;

    // Permet de reconstituer une valeur entre 0 et 15 représentant toutes les situations de blocage
    m_obstacle_detecte_bitfield = (m_obstacle_detecte_ARG << 3) | (m_obstacle_detecte_ARD << 2) | (m_obstacle_detecte_AVG << 1) | (m_obstacle_detecte_AVD << 0);
*/
    //____________________________
    //Variables calculées
    //sens de deplacement: en fonction du signe si + alors marche avant
    m_sens_deplacement=copysignf(1.0,Application.m_asservissement.erreur_distance);
    m_obstacleDetecte=isObstacle(Application.m_asservissement.X_robot,
                                Application.m_asservissement.Y_robot,
                                Application.m_asservissement.angle_robot,
                                Application.m_asservissement.vitesse_avance_robot,
                                m_sens_deplacement);
    //____________________________
	//Capteurs TOR
    //m_b_Etor1==1 => tirette enlevee
    //m_ia.m_inputs_interface.Tirette = Application.m_electrobot.m_b_Eana1<2.0f;
    //_led2 = Application.m_electrobot.m_b_Etor1;
    m_ia.m_inputs_interface.Tirette = Application.m_electrobot.m_b_Etor1;
    /*
    if((Application.m_electrobot.m_b_Eana1<2.0f)&&(m_tirette_old==0))
    {
        m_tirette_old=1;
    }*/


    //____________________________
	//Variables de l'aservissement
	
	//Variables de l'asservissement chariot

	//TODO:
	//diag de blocage, pour l'instant on claque les tempo

    // =====================================================================
    //Appel de la strategie du modele
    m_ia.step();



    // =====================================================================
    //SORTIES de MODELE
    //m_obstacleDetecte=ModeleRobot_Y.OUT_isObstacle;

	// ___________________________ 
	// Divers
    //m_duree = m_iaSCI->get_tempsMatch();
    //m_couleur_equipe = m_iaSCI->get_couleur();
    //m_choix_strategie = m_iaSCI->get_choixStrategie();
    //m_score_total = m_iaSCI->get_score_total();
    //m_num_etape_evitement = m_iaSCI->get_evit_debug_etape();
    //m_nbre_tentatives_evitement = m_iaSCI->get_evit_nombre_tentatives();
    //m_evitement_en_cours = m_iaSCI->get_evitementEnCours();
    //m_forcage_detect_obstacle_sans_position = m_iaSCI->get_forceObstacle();
    //m_inhibe_obstacle = m_iaSCI->get_inhibeObstacle();
    //m_choix_strategie_evitement = m_iaSCI->get_evit_choix_strategie();
    //m_seuil_detection_obstacle = m_iaSCI->get_evit_seuil_detection_obstacle();
	
	// Asservissement
	//Application.m_asservissement.CalculsMouvementsRobots();

}




//___________________________________________________________________________
 /*!
   \brief Envoie les infos sur la  RS232

   \param --
   \return --
*/
void CMatch::debug(void)
{
   _rs232_pc_tx.putc(0xC);	// Saut de page pour que toutes les infos soient affichées toujours au meme endroit sur la page (avec hyperterminal)
//   _rs232_pc_tx.printf("DureeMatch=%f\r\n", m_duree);
//   _rs232_pc_tx.printf("MvtManuel=%f(%f, %f)\n\r", ModeleRobot_Y.OUT_DdeMvtManuel, ModeleRobot_Y.OUT_CommandeManuelleG, ModeleRobot_Y.OUT_CommandeManuelleD);
//   _rs232_pc_tx.printf("MvtDistAngle=%f(%f, %f)\n\r", ModeleRobot_Y.OUT_DdeMvtDistanceAngle, ModeleRobot_Y.OUT_ConsigneDistance, ModeleRobot_Y.OUT_ConsigneTeta);
//   _rs232_pc_tx.printf("MvtXY=%f(%f, %f)\n\r", ModeleRobot_Y.OUT_DdeMvtXY, ModeleRobot_Y.OUT_ConsigneX, ModeleRobot_Y.OUT_ConsigneY);
   _rs232_pc_tx.printf("CdeMotG=%f - CdeMotD=%f\n\r", Application.m_asservissement.cde_moteur_G, Application.m_asservissement.cde_moteur_D);
}

/*!
 * \brief CMatch::frontMontant fonction statique de détection de front montant
 * \param prec_value
 * \param value
 * \return
 */
bool CMatch::frontMontant(float prec_value, float value)
{
    bool b_Up=false;
    if(value>prec_value) b_Up=true;
    return b_Up;
}

/*!
 * \brief CMatch::isObstacle Stratégie de détection d'obstacle. Si la distance séparant le robot de l'objet détecté
 * est inférieure à  un seuil un flag est levé. TODO: rendre le seuil dépendant de la vitesse
 * \param x
 * \param y
 * \param teta
 * \param speed
 * \param sens
 * \return
 */
int CMatch::isObstacle(float x, float y, float teta, float speed, float sens)
{
 /*
    //calibration
    //TODO: a remplacer par une carto
    int detection=0;
    //int VIOLET=m_iaSCI->get_vIOLET();
    //int JAUNE=m_iaSCI->get_jAUNE();
    int Couleur=m_couleur_equipe;// m_iaSCI->get_couleur();
    //bool b_forceObstacle=m_iaSCI->get_forceObstacle();
    float f_x=Application.m_asservissement.X_robot;
                                    float f_y=Application.m_asservissement.Y_robot;
                                    float f_teta=Application.m_asservissement.angle_robot;


    if (   ((sens>0)&&(m_obstacle_detecte_AVD||m_obstacle_detecte_AVG)) //marche avant
        || ((sens<0)&&(m_obstacle_detecte_ARD||m_obstacle_detecte_ARG)) ) //marche arrière
    {
        if(Couleur==JAUNE)
        {
            if ((f_y>-69)&&(f_y<8)&&(x>35))
                detection=1;
            else
                detection=0;
        }
        if(Couleur==VIOLET)
        {
             if ((f_y<69)&&(f_y>-8)&&(x>35))
                detection=1;
            else
                detection=0;
        }

        if (b_forceObstacle==true)
            detection=1;
    }
    else
      detection=0;

    //à réactiver si on veut détecter à l'arrêt
    /*if (sens==0)
        ((m_telemetre_AVD<=seuilDistance)||(m_telemetre_AVG<=seuilDistance)||(m_telemetre_ARD<=seuilDistance)||(m_telemetre_ARG<=seuilDistance))? detection=1:detection=0;
    //on retire les alertes si détection trop proche de la bordure*/
    /*if ((((x>100)||(x<-100))||((y>300)||(y<-30)))&&(detection==1))
        detection=0;*/

    return 0;
    //return detection;
}


