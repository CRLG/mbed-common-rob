/*! \file CGlobale.cpp
    \brief Classe qui contient toute l'application
*/
#include "mbed.h"
#include "RessourcesHardware.h"
#include "CGlobale.h"

//___________________________________________________________________________
/*!
   \brief Constructeur

   \param --
   \return --
*/
CGlobale::CGlobale()
    : m_led1(&_led1),
      m_led2(&_led2),
      m_led3(&_led3),
      m_led4(&_led4),
      m_leds(&m_led1, &m_led2, &m_led3, &m_led4)
{
    ModeFonctionnement = MODE_AUTONOME;
    m_distance_camera=0;
    m_cpu_overload_counter=0;
    m_cpu_load_last_time_us=0;
}

//___________________________________________________________________________
/*!
   \brief Destructeur

   \param --
   \return --
*/
CGlobale::~CGlobale() 
{

}

//___________________________________________________________________________
/*!
   \brief Point d'entrée pour l'execution de toute l'application

   \param --
   \return --
*/
void CGlobale::Run(void)
{
    // Initialise la vitesse de transmission avec le PC
    _rs232_pc_tx.baud(115200);
    _rs232_pc_tx.format(8, Serial::None, 1);   	// 8 bits de données / Pas de parité / 1 bit de stop
    _rs232_pc_rx.baud(115200);
    _rs232_pc_rx.format(8, Serial::None, 1);   	// 8 bits de données / Pas de parité / 1 bit de stop

    _rs232_pc_tx.printf("\n\rHello\n\r");

    //initialise la vitesse i2c
    //_i2c.frequency(200000);

    // Lecture des paramètres EEPROM
    readEEPROM();

    // Attends la montée de toutes les alimentation et l'initialisation de l'écran
    // Temps nécessaire en pratique pour que l'écran tactile ai fini de démarrer
    // avant de commencer à  lui en envoyer des messages (et d'en recevoir)
    wait_ms(3000);

    // Active les pull up sur les entrées
    //_Etor1.mode(PullUp);
    //_Etor2.mode(PullUp);
    m_electrobot.Init();

    //Init de l'asservissement chariot
#ifdef UTILISATION_CHARIOT
    m_asservissement_chariot.Init();
#endif

    // Initialisation des servos moteurs
    m_servos_sd20.Init();

#ifdef UTILSATION_SERVOS_AX
    m_servos_ax.Init();
#endif

#ifdef UTILISATION_XBEE
    m_messenger_xbee_ntw.start();
#endif

    // Carte PowerElectrobot
    m_power_electrobot.init(POWER_ELECTROBOT_I2C_ADDR);

#ifdef UTILISATION_CHARIOT
    //Init de l'asservissement chariot en cas de plantage de l'eeprom
    if ((Application.m_asservissement_chariot.commande_chariot_max_C==0) ||
            (Application.m_asservissement_chariot.compensation_zone_morte_dw_C==0) ||
            (Application.m_asservissement_chariot.compensation_zone_morte_up_C==0))
        m_asservissement_chariot.Init();
#endif
    _rs232_pc_tx.printf("ki_angle = %f\n\r", Application.m_asservissement.ki_angle);
    _rs232_pc_tx.printf("cde_max = %d\n\r", Application.m_asservissement.cde_max);
    _rs232_pc_tx.printf("cde_min = %d\n\r", Application.m_asservissement.cde_min);

    switch(ModeFonctionnement) {
    case MODE_AUTONOME : 			ModeAutonome();			break;
    case MODE_PILOTE_LABOTBOX : 	ModePiloteLaBotBox();	break;
    case MODE_PILOTE_TERMINAL : 	ModePiloteTerminal();	break;
    default : 						ModeAutonome();			break;
    }

    while(1) {
        // Ce code ne devrait jamais être atteint
    }
}


//___________________________________________________________________________
/*!
   \brief Lecture des paramètre de l'EEPROM

   \param --
   \return --
*/
void CGlobale::readEEPROM()
{
    m_eeprom.getValue("ModeFonctionnement", &ModeFonctionnement);

    // valeurs pour le module Asservissement
    m_eeprom.getValue("cde_max", &(m_asservissement.cde_max));
    m_eeprom.getValue("cde_min", &(m_asservissement.cde_min));
    m_eeprom.getValue("kp_distance", &(m_asservissement.kp_distance));
    m_eeprom.getValue("ki_distance", &(m_asservissement.ki_distance));
    m_eeprom.getValue("kp_angle", &(m_asservissement.kp_angle));
    m_eeprom.getValue("ki_angle", &(m_asservissement.ki_angle));
    m_eeprom.getValue("k_angle", &(m_asservissement.k_angle));
    m_eeprom.getValue("seuil_conv_distance", &(m_asservissement.seuil_conv_distance));
    m_eeprom.getValue("seuil_conv_angle", &(m_asservissement.seuil_conv_angle));
    m_eeprom.getValue("compteur_max", &(m_asservissement.compteur_max));
    m_eeprom.getValue("zone_morte_D", &(m_asservissement.zone_morte_D));
    m_eeprom.getValue("zone_morte_G", &(m_asservissement.zone_morte_G));
    m_eeprom.getValue("id_perf", &(m_asservissement.Ind_perfo));

    m_eeprom.getValue("rackCommandeMax", &(m_asservissement_chariot.commande_chariot_max_C));
    m_eeprom.getValue("rackGainPosVit", &(m_asservissement_chariot.gain_position_vitesse_C));
    m_eeprom.getValue("rackGainP", &(m_asservissement_chariot.gain_prop_C));
    m_eeprom.getValue("rackGainI", &(m_asservissement_chariot.gain_int_C));
    m_eeprom.getValue("rackSeuilConv", &(m_asservissement_chariot.seuil_conv_C));
    m_eeprom.getValue("rackZMdw", &(m_asservissement_chariot.compensation_zone_morte_dw_C));
    m_eeprom.getValue("rackZMup", &(m_asservissement_chariot.compensation_zone_morte_up_C));
    m_eeprom.getValue("rackGradVit", &(m_asservissement_chariot.offset_vitesse_max_C));
}

//___________________________________________________________________________
/*!
 * \brief Met a jour l'indicateur de surcharge CPU base sur le principe suivant
 *     Si le delai calcule entre 2 appels est superieur a un certain seuil -> incremente l'indicateur de surcharge CPU
 *     Sinon, RAZ du compteur
 */
const int PERIOD_REFRESH_INDICATEUR_CPU_USEC = (20000); // usec (periode d'appel de la fonction de calcul de la surcharge CPU)
const int TOLERANCE_SURCHARGE_CPU_USEC = 10; // usec
const int SEUIL_SURCHARGE_CPU_USEC  = (PERIOD_REFRESH_INDICATEUR_CPU_USEC+TOLERANCE_SURCHARGE_CPU_USEC);
void CGlobale::RefreshIndicateurSurchargeCPU()
{
    int _current_time_us = _Global_Timer.read_us();
    m_cpu_load_delta_t = _current_time_us - m_cpu_load_last_time_us;

    int _diff = abs((long)m_cpu_load_delta_t - PERIOD_REFRESH_INDICATEUR_CPU_USEC);

    if ( _diff  > TOLERANCE_SURCHARGE_CPU_USEC) {
        m_cpu_overload_counter += 1;
    }
    else {
        if (m_cpu_overload_counter>0) m_cpu_overload_counter -=1;
    }

    m_cpu_load_last_time_us = _current_time_us;
}

