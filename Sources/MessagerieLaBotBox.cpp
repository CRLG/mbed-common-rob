// FICHIER GENERE PAR L'OUTIL MESS2C_robot V1.0
// Date de génération : Tue May 05 22:19:15 2015
// PLATEFORME CIBLE : MINIBOT
/*! \file MessagerieLaBotBox.cpp
	\brief Fichier qui contient toutes les classes messageries heritees de la classe CTrameCAN
*/
#include "RessourcesHardware.h"
#include "MessagerieLaBotBox.h"
#include "data_encoder_decoder.h"


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_SD20::CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_SD20()
{
  m_ID = ID_ELECTROBOT_CDE_SERVOS_SD20;
  m_DLC = DLC_ELECTROBOT_CDE_SERVOS_SD20;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_CDE_SERVOS_SD20

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_SD20::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   valeur_commande_sd20 = ( ( ((unsigned short)(trameRecue->Data[4])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[3])) & 0xFF) << 8 );

   commande_sd20 = ( ( ((unsigned short)(trameRecue->Data[2])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[1])) & 0xFF) << 8 );

   num_servo_sd20 = ( ( ((unsigned char)(trameRecue->Data[0])) & 0xFF) );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_CDE_SERVOS_SD20
        - Renseigne les champs de la structure de donnee de la trame a transmettre
   \param trame pointeur sur une structure trame deja alloue
   \return le pointeur sur la trame a envoyer (renvoie le pointeur recu)
   */
tStructTrameLaBotBox* CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_SD20::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

  	// Encode chacun des signaux de la trame
    trame->Data[4] |= (unsigned char)( ( (valeur_commande_sd20) & 0xFF) );
    trame->Data[3] |= (unsigned char)( ( (valeur_commande_sd20 >> 8) & 0xFF) );

    trame->Data[2] |= (unsigned char)( ( (commande_sd20) & 0xFF) );
    trame->Data[1] |= (unsigned char)( ( (commande_sd20 >> 8) & 0xFF) );

    trame->Data[0] |= (unsigned char)( ( (num_servo_sd20) & 0xFF) );

    return(trame);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_AX::CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_AX()
{
  m_ID = ID_ELECTROBOT_CDE_SERVOS_AX;
  m_DLC = DLC_ELECTROBOT_CDE_SERVOS_AX;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_CDE_SERVOS_AX

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_ELECTROBOT_CDE_SERVOS_AX::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   valeur_commande_ax = ( ( ((unsigned short)(trameRecue->Data[4])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[3])) & 0xFF) << 8 );

   commande_ax = ( ( ((unsigned short)(trameRecue->Data[2])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[1])) & 0xFF) << 8 );

   num_servo_ax = ( ( ((unsigned char)(trameRecue->Data[0])) & 0xFF) );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_CDE_MOTEURS::CTrameLaBotBox_ELECTROBOT_CDE_MOTEURS()
{
  m_ID = ID_ELECTROBOT_CDE_MOTEURS;
  m_DLC = DLC_ELECTROBOT_CDE_MOTEURS;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_CDE_MOTEURS

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_ELECTROBOT_CDE_MOTEURS::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   cde_moteur_6 = ( ( ((char)(trameRecue->Data[5])) & 0xFF) );

   cde_moteur_5 = ( ( ((char)(trameRecue->Data[4])) & 0xFF) );

   cde_moteur_4 = ( ( ((char)(trameRecue->Data[3])) & 0xFF) );

   cde_moteur_3 = ( ( ((char)(trameRecue->Data[2])) & 0xFF) );

   cde_moteur_2 = ( ( ((char)(trameRecue->Data[1])) & 0xFF) );

   cde_moteur_1 = ( ( ((char)(trameRecue->Data[0])) & 0xFF) );


  m_new_trame = true;
  m_nombre_recue++;
}

//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_COMMANDE_POWER_ELECTROBOT::CTrameLaBotBox_COMMANDE_POWER_ELECTROBOT()
{
  m_ID = ID_COMMANDE_POWER_ELECTROBOT;
  m_DLC = DLC_COMMANDE_POWER_ELECTROBOT;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame COMMANDE_POWER_ELECTROBOT

        - Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_COMMANDE_POWER_ELECTROBOT::Decode(tStructTrameLaBotBox *trameRecue)
{
    // Decode les signaux de la trame
    commande = ((unsigned short)trameRecue->Data[0] << 8) + trameRecue->Data[1];
    val = ((unsigned short)trameRecue->Data[2] << 8) + trameRecue->Data[3];
    m_new_trame = true;
    m_nombre_recue++;
}

//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ETAT_POWER_ELECTROBOT::CTrameLaBotBox_ETAT_POWER_ELECTROBOT()
{
  m_ID = ID_ETAT_POWER_ELECTROBOT;
  m_DLC = DLC_ETAT_POWER_ELECTROBOT;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ETAT_POWER_ELECTROBOT
        - Renseigne les champs de la structure de donnee de la trame a transmettre
   \param trame pointeur sur une structure trame deja alloue
   \return le pointeur sur la trame a envoyer (renvoie le pointeur recu)
   */
tStructTrameLaBotBox* CTrameLaBotBox_ETAT_POWER_ELECTROBOT::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

    // Encode chacun des signaux de la trame
    trame->Data[0] |= (unsigned char)( ( (battery_voltage_mV >> 8) & 0xFF) );
    trame->Data[1] |= (unsigned char)( ( (battery_voltage_mV) & 0xFF) );

    trame->Data[2] |= (unsigned char)( ( (global_current_mA >> 8) & 0xFF) );
    trame->Data[3] |= (unsigned char)( ( (global_current_mA) & 0xFF) );

    trame->Data[4] |= (unsigned char)( ( (current_out1_mA >> 8) & 0xFF) );
    trame->Data[5] |= (unsigned char)( ( (current_out1_mA) & 0xFF) );

    trame->Data[6] |= (unsigned char)( ( (current_out2_mA >> 8) & 0xFF) );
    trame->Data[7] |= (unsigned char)( ( (current_out2_mA) & 0xFF) );

    return(trame);
}

//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_COMMANDE_MVT_XY::CTrameLaBotBox_COMMANDE_MVT_XY()
{
  m_ID = ID_COMMANDE_MVT_XY;
  m_DLC = DLC_COMMANDE_MVT_XY;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame COMMANDE_MVT_XY

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_COMMANDE_MVT_XY::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   Y_consigne = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

   X_consigne = ( ( ((short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[0])) & 0xFF) << 8 );

   Type_mouvement = ( ( ((unsigned char)(trameRecue->Data[4])) & 0xFF) );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ASSERV_RESET::CTrameLaBotBox_ASSERV_RESET()
{
  m_ID = ID_ASSERV_RESET;
  m_DLC = DLC_ASSERV_RESET;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ASSERV_RESET

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_ASSERV_RESET::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   SECURITE_RESET = ( ( ((unsigned char)(trameRecue->Data[0])) & 0xFF) );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_AUTOAPPRENTISSAGE_ASSERV::CTrameLaBotBox_AUTOAPPRENTISSAGE_ASSERV()
{
  m_ID = ID_AUTOAPPRENTISSAGE_ASSERV;
  m_DLC = DLC_AUTOAPPRENTISSAGE_ASSERV;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame AUTOAPPRENTISSAGE_ASSERV

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_AUTOAPPRENTISSAGE_ASSERV::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   Type_autoapprentissage = ( ( ((unsigned char)(trameRecue->Data[0])) & 0xFF) );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_COMMANDE_REINIT_XY_TETA::CTrameLaBotBox_COMMANDE_REINIT_XY_TETA()
{
  m_ID = ID_COMMANDE_REINIT_XY_TETA;
  m_DLC = DLC_COMMANDE_REINIT_XY_TETA;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame COMMANDE_REINIT_XY_TETA

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_COMMANDE_REINIT_XY_TETA::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   reinit_teta_pos = ( ( ((short)(trameRecue->Data[5])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[4])) & 0xFF) << 8 );

   reinit_y_pos = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

   reinit_x_pos = ( ( ((short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_COMMANDE_VITESSE_MVT::CTrameLaBotBox_COMMANDE_VITESSE_MVT()
{
  m_ID = ID_COMMANDE_VITESSE_MVT;
  m_DLC = DLC_COMMANDE_VITESSE_MVT;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame COMMANDE_VITESSE_MVT

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_COMMANDE_VITESSE_MVT::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   indice_sportivite_decel = ( ( ((unsigned char)(trameRecue->Data[5])) & 0xFF) );

   indice_sportivite_accel = ( ( ((unsigned char)(trameRecue->Data[4])) & 0xFF) );

   vitesse_rotation_max = ( ( ((unsigned short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[2])) & 0xFF) << 8 );

   vitesse_avance_max = ( ( ((unsigned short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_COMMANDE_REGUL_VITESSE::CTrameLaBotBox_COMMANDE_REGUL_VITESSE()
{
  m_ID = ID_COMMANDE_REGUL_VITESSE;
  m_DLC = DLC_COMMANDE_REGUL_VITESSE;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame COMMANDE_REGUL_VITESSE

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_COMMANDE_REGUL_VITESSE::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   consigne_vitesse_roue_D = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

   consigne_vitesse_roue_G = ( ( ((short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_COMMANDE_DISTANCE_ANGLE::CTrameLaBotBox_COMMANDE_DISTANCE_ANGLE()
{
  m_ID = ID_COMMANDE_DISTANCE_ANGLE;
  m_DLC = DLC_COMMANDE_DISTANCE_ANGLE;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame COMMANDE_DISTANCE_ANGLE

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_COMMANDE_DISTANCE_ANGLE::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   angle_consigne = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

   distance_consigne = ( ( ((short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[0])) & 0xFF) << 8 );

   priorite_mouvement = ( ( ((unsigned char)(trameRecue->Data[4])) & 0xFF) );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_COMMANDE_MVT_XY_TETA::CTrameLaBotBox_COMMANDE_MVT_XY_TETA()
{
  m_ID = ID_COMMANDE_MVT_XY_TETA;
  m_DLC = DLC_COMMANDE_MVT_XY_TETA;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame COMMANDE_MVT_XY_TETA

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_COMMANDE_MVT_XY_TETA::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   angle_consigne = ( ( ((short)(trameRecue->Data[5])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[4])) & 0xFF) << 8 );

   Y_consigne = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

   X_consigne = ( ( ((short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[0])) & 0xFF) << 8 );

   Type_mouvement = ( ( ((unsigned char)(trameRecue->Data[6])) & 0xFF) );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ASSERV_DIAG_WRITE_PARAM::CTrameLaBotBox_ASSERV_DIAG_WRITE_PARAM()
{
  m_ID = ID_ASSERV_DIAG_WRITE_PARAM;
  m_DLC = DLC_ASSERV_DIAG_WRITE_PARAM;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ASSERV_DIAG_WRITE_PARAM

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_ASSERV_DIAG_WRITE_PARAM::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   ASSERV_DIAG_WRITE_VALUE = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

   ASSERV_DIAG_WRITE_PARAM = ( ( ((unsigned short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_CDE_SERVOS::CTrameLaBotBox_ELECTROBOT_CDE_SERVOS()
{
  m_ID = ID_ELECTROBOT_CDE_SERVOS;
  m_DLC = DLC_ELECTROBOT_CDE_SERVOS;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_CDE_SERVOS

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_ELECTROBOT_CDE_SERVOS::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   PositionServoMoteur2 = ( ( ((unsigned short)(trameRecue->Data[7])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[6])) & 0xFF) << 8 );

   VitesseServoMoteur2 = ( ( ((unsigned char)(trameRecue->Data[5])) & 0xFF) );

   NumeroServoMoteur2 = ( ( ((unsigned char)(trameRecue->Data[4])) & 0xFF) );

   PositionServoMoteur1 = ( ( ((unsigned short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[2])) & 0xFF) << 8 );

   VitesseServoMoteur1 = ( ( ((unsigned char)(trameRecue->Data[1])) & 0xFF) );

   NumeroServoMoteur1 = ( ( ((unsigned char)(trameRecue->Data[0])) & 0xFF) );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_COMMANDE_MVT_MANUEL::CTrameLaBotBox_COMMANDE_MVT_MANUEL()
{
  m_ID = ID_COMMANDE_MVT_MANUEL;
  m_DLC = DLC_COMMANDE_MVT_MANUEL;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame COMMANDE_MVT_MANUEL

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_COMMANDE_MVT_MANUEL::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   PuissanceMotD = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

   PuissanceMotG = ( ( ((short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ETAT_PID_ASSERVISSEMENT::CTrameLaBotBox_ETAT_PID_ASSERVISSEMENT()
{
  m_ID = ID_ETAT_PID_ASSERVISSEMENT;
  m_DLC = DLC_ETAT_PID_ASSERVISSEMENT;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ETAT_PID_ASSERVISSEMENT
        - Renseigne les champs de la structure de donnee de la trame a transmettre
   \param trame pointeur sur une structure trame deja alloue
   \return le pointeur sur la trame a envoyer (renvoie le pointeur recu)
   */
tStructTrameLaBotBox* CTrameLaBotBox_ETAT_PID_ASSERVISSEMENT::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

  	// Encode chacun des signaux de la trame
    trame->Data[7] |= (unsigned char)( ( (consigne_vitesse_rotation_filt) & 0xFF) );
    trame->Data[6] |= (unsigned char)( ( (consigne_vitesse_rotation_filt >> 8) & 0xFF) );

    trame->Data[5] |= (unsigned char)( ( (vitesse_rotation_robot_filt) & 0xFF) );
    trame->Data[4] |= (unsigned char)( ( (vitesse_rotation_robot_filt >> 8) & 0xFF) );

    trame->Data[3] |= (unsigned char)( ( (consigne_vitesse_avance_filt) & 0xFF) );
    trame->Data[2] |= (unsigned char)( ( (consigne_vitesse_avance_filt >> 8) & 0xFF) );

    trame->Data[1] |= (unsigned char)( ( (vitesse_avance_robot_filt) & 0xFF) );
    trame->Data[0] |= (unsigned char)( ( (vitesse_avance_robot_filt >> 8) & 0xFF) );

    return(trame);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ETAT_ASSERVISSEMENT::CTrameLaBotBox_ETAT_ASSERVISSEMENT()
{
  m_ID = ID_ETAT_ASSERVISSEMENT;
  m_DLC = DLC_ETAT_ASSERVISSEMENT;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ETAT_ASSERVISSEMENT
        - Renseigne les champs de la structure de donnee de la trame a transmettre
   \param trame pointeur sur une structure trame deja alloue
   \return le pointeur sur la trame a envoyer (renvoie le pointeur recu)   */
tStructTrameLaBotBox* CTrameLaBotBox_ETAT_ASSERVISSEMENT::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

  	// Encode chacun des signaux de la trame
    trame->Data[7] |= (unsigned char)( ( (compteur_diag_blocage) & 0xFF) );
    trame->Data[6] |= (unsigned char)( ( (compteur_diag_blocage >> 8) & 0xFF) );

    trame->Data[5] |= (unsigned char)( ( (ModeAsservissement) & 0xFF) );

    trame->Data[3] |= (unsigned char)( ( (cde_moteur_D) & 0xFF) );
    trame->Data[2] |= (unsigned char)( ( (cde_moteur_D >> 8) & 0xFF) );

    trame->Data[1] |= (unsigned char)( ( (cde_moteur_G) & 0xFF) );
    trame->Data[0] |= (unsigned char)( ( (cde_moteur_G >> 8) & 0xFF) );

    trame->Data[4] |= (unsigned char)( ( (Convergence) & 0xFF) );

    return(trame);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_POSITION_CODEURS::CTrameLaBotBox_POSITION_CODEURS()
{
  m_ID = ID_POSITION_CODEURS;
  m_DLC = DLC_POSITION_CODEURS;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame POSITION_CODEURS
        - Renseigne les champs de la structure de donnee de la trame a transmettre
   \param trame pointeur sur une structure trame deja alloue
   \return le pointeur sur la trame a envoyer (renvoie le pointeur recu)   */
tStructTrameLaBotBox* CTrameLaBotBox_POSITION_CODEURS::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

  	// Encode chacun des signaux de la trame
    trame->Data[1] |= (unsigned char)( ( (PosCodeurG) & 0xFF) );
    trame->Data[0] |= (unsigned char)( ( (PosCodeurG >> 8) & 0xFF) );

    trame->Data[3] |= (unsigned char)( ( (PosCodeurD) & 0xFF) );
    trame->Data[2] |= (unsigned char)( ( (PosCodeurD >> 8) & 0xFF) );

    return(trame);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_POSITION_ABSOLUE_XY_TETA::CTrameLaBotBox_POSITION_ABSOLUE_XY_TETA()
{
  m_ID = ID_POSITION_ABSOLUE_XY_TETA;
  m_DLC = DLC_POSITION_ABSOLUE_XY_TETA;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame POSITION_ABSOLUE_XY_TETA
        - Renseigne les champs de la structure de donnee de la trame a transmettre
   \param trame pointeur sur une structure trame deja alloue
   \return le pointeur sur la trame a envoyer (renvoie le pointeur recu)   */
tStructTrameLaBotBox* CTrameLaBotBox_POSITION_ABSOLUE_XY_TETA::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

  	// Encode chacun des signaux de la trame
    trame->Data[5] |= (unsigned char)( ( (teta_pos) & 0xFF) );
    trame->Data[4] |= (unsigned char)( ( (teta_pos >> 8) & 0xFF) );

    trame->Data[3] |= (unsigned char)( ( (y_pos) & 0xFF) );
    trame->Data[2] |= (unsigned char)( ( (y_pos >> 8) & 0xFF) );

    trame->Data[1] |= (unsigned char)( ( (x_pos) & 0xFF) );
    trame->Data[0] |= (unsigned char)( ( (x_pos >> 8) & 0xFF) );

    return(trame);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_ETAT_CODEURS_1_2::CTrameLaBotBox_ELECTROBOT_ETAT_CODEURS_1_2()
{
  m_ID = ID_ELECTROBOT_ETAT_CODEURS_1_2;
  m_DLC = DLC_ELECTROBOT_ETAT_CODEURS_1_2;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_ETAT_CODEURS_1_2
        - Renseigne les champs de la structure de donnee de la trame a transmettre
   \param trame pointeur sur une structure trame deja alloue
   \return le pointeur sur la trame a envoyer (renvoie le pointeur recu)   */
tStructTrameLaBotBox* CTrameLaBotBox_ELECTROBOT_ETAT_CODEURS_1_2::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

  	// Encode chacun des signaux de la trame
    trame->Data[7] |= (unsigned char)( ( (Codeur_2) & 0xFF) );
    trame->Data[6] |= (unsigned char)( ( (Codeur_2 >> 8) & 0xFF) );
    trame->Data[5] |= (unsigned char)( ( (Codeur_2 >> 16) & 0xFF) );
    trame->Data[4] |= (unsigned char)( ( (Codeur_2 >> 24) & 0xFF) );

    trame->Data[3] |= (unsigned char)( ( (Codeur_1) & 0xFF) );
    trame->Data[2] |= (unsigned char)( ( (Codeur_1 >> 8) & 0xFF) );
    trame->Data[1] |= (unsigned char)( ( (Codeur_1 >> 16) & 0xFF) );
    trame->Data[0] |= (unsigned char)( ( (Codeur_1 >> 24) & 0xFF) );

    return(trame);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_ETAT_TELEMETRES::CTrameLaBotBox_ELECTROBOT_ETAT_TELEMETRES()
{
  m_ID = ID_ELECTROBOT_ETAT_TELEMETRES;
  m_DLC = DLC_ELECTROBOT_ETAT_TELEMETRES;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_ETAT_TELEMETRES
        - Renseigne les champs de la structure de donnee de la trame a transmettre
   \param trame pointeur sur une structure trame deja alloue
   \return le pointeur sur la trame a envoyer (renvoie le pointeur recu)   */
tStructTrameLaBotBox* CTrameLaBotBox_ELECTROBOT_ETAT_TELEMETRES::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

  	// Encode chacun des signaux de la trame
    trame->Data[5] |= (unsigned char)( ( (Telemetre6) & 0xFF) );

    trame->Data[4] |= (unsigned char)( ( (Telemetre5) & 0xFF) );

    trame->Data[3] |= (unsigned char)( ( (Telemetre4) & 0xFF) );

    trame->Data[2] |= (unsigned char)( ( (Telemetre3) & 0xFF) );

    trame->Data[1] |= (unsigned char)( ( (Telemetre2) & 0xFF) );

    trame->Data[0] |= (unsigned char)( ( (Telemetre1) & 0xFF) );

    return(trame);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_ETAT_CODEURS_3_4::CTrameLaBotBox_ELECTROBOT_ETAT_CODEURS_3_4()
{
  m_ID = ID_ELECTROBOT_ETAT_CODEURS_3_4;
  m_DLC = DLC_ELECTROBOT_ETAT_CODEURS_3_4;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_ETAT_CODEURS_3_4
        - Renseigne les champs de la structure de donnee de la trame a transmettre
   \param trame pointeur sur une structure trame deja alloue
   \return le pointeur sur la trame a envoyer (renvoie le pointeur recu)   */
tStructTrameLaBotBox* CTrameLaBotBox_ELECTROBOT_ETAT_CODEURS_3_4::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

  	// Encode chacun des signaux de la trame
    trame->Data[7] |= (unsigned char)( ( (Codeur_4) & 0xFF) );
    trame->Data[6] |= (unsigned char)( ( (Codeur_4 >> 8) & 0xFF) );
    trame->Data[5] |= (unsigned char)( ( (Codeur_4 >> 16) & 0xFF) );
    trame->Data[4] |= (unsigned char)( ( (Codeur_4 >> 24) & 0xFF) );

    trame->Data[3] |= (unsigned char)( ( (Codeur_3) & 0xFF) );
    trame->Data[2] |= (unsigned char)( ( (Codeur_3 >> 8) & 0xFF) );
    trame->Data[1] |= (unsigned char)( ( (Codeur_3 >> 16) & 0xFF) );
    trame->Data[0] |= (unsigned char)( ( (Codeur_3 >> 24) & 0xFF) );

    return(trame);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_ETAT_CAPTEURS_2::CTrameLaBotBox_ELECTROBOT_ETAT_CAPTEURS_2()
{
  m_ID = ID_ELECTROBOT_ETAT_CAPTEURS_2;
  m_DLC = DLC_ELECTROBOT_ETAT_CAPTEURS_2;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_ETAT_CAPTEURS_2
        - Renseigne les champs de la structure de donnee de la trame a transmettre
   \param trame pointeur sur une structure trame deja alloue
   \return le pointeur sur la trame a envoyer (renvoie le pointeur recu)
   */
tStructTrameLaBotBox* CTrameLaBotBox_ELECTROBOT_ETAT_CAPTEURS_2::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

  	// Encode chacun des signaux de la trame
    trame->Data[7] |= (unsigned char)( ( (Etor_PGED1_dsPIC2) & 0x1) << 7 );

    trame->Data[7] |= (unsigned char)( ( (Etor_PGED1_dsPIC1) & 0x1) << 6 );

    trame->Data[7] |= (unsigned char)( ( (Etor_PGEC1_dsPIC2) & 0x1) << 5 );

    trame->Data[7] |= (unsigned char)( ( (Etor_PGEC1_dsPIC1) & 0x1) << 4 );

    trame->Data[7] |= (unsigned char)( ( (Etor_Codeur4_B) & 0x1) << 3 );

    trame->Data[7] |= (unsigned char)( ( (Etor_Codeur4_A) & 0x1) << 2 );

    trame->Data[7] |= (unsigned char)( ( (Etor_Codeur3_B) & 0x1) << 1 );

    trame->Data[7] |= (unsigned char)( ( (Etor_Codeur3_A) & 0x1) );

    trame->Data[6] |= (unsigned char)( ( (Etor_CAN_TX) & 0x1) << 7 );

    trame->Data[6] |= (unsigned char)( ( (Etor_CAN_RX) & 0x1) << 6 );

    trame->Data[6] |= (unsigned char)( ( (Etor6) & 0x1) << 5 );

    trame->Data[6] |= (unsigned char)( ( (Etor5) & 0x1) << 4 );

    trame->Data[6] |= (unsigned char)( ( (Etor4) & 0x1) << 3 );

    trame->Data[6] |= (unsigned char)( ( (Etor3) & 0x1) << 2 );

    trame->Data[6] |= (unsigned char)( ( (Etor2) & 0x1) << 1 );

    trame->Data[6] |= (unsigned char)( ( (Etor1) & 0x1) );

    trame->Data[5] |= (unsigned char)( ( (Vbat) & 0xFF) );

    trame->Data[4] |= (unsigned char)( ( (Eana13) & 0xFF) );

    trame->Data[3] |= (unsigned char)( ( (Eana12) & 0xFF) );

    trame->Data[2] |= (unsigned char)( ( (Eana11) & 0xFF) );

    trame->Data[1] |= (unsigned char)( ( (Eana10) & 0xFF) );

    trame->Data[0] |= (unsigned char)( ( (Eana9) & 0xFF) );

    return(trame);
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_ETAT_CAPTEURS_1::CTrameLaBotBox_ELECTROBOT_ETAT_CAPTEURS_1()
{
  m_ID = ID_ELECTROBOT_ETAT_CAPTEURS_1;
  m_DLC = DLC_ELECTROBOT_ETAT_CAPTEURS_1;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_ETAT_CAPTEURS_1
        - Renseigne les champs de la structure de donnee de la trame a transmettre
   \param trame pointeur sur une structure trame deja alloue
   \return le pointeur sur la trame a envoyer (renvoie le pointeur recu)
   */
tStructTrameLaBotBox* CTrameLaBotBox_ELECTROBOT_ETAT_CAPTEURS_1::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

  	// Encode chacun des signaux de la trame
    trame->Data[7] |= (unsigned char)( ( (Eana8) & 0xFF) );

    trame->Data[6] |= (unsigned char)( ( (Eana7) & 0xFF) );

    trame->Data[5] |= (unsigned char)( ( (Eana6) & 0xFF) );

    trame->Data[4] |= (unsigned char)( ( (Eana5) & 0xFF) );

    trame->Data[3] |= (unsigned char)( ( (Eana4) & 0xFF) );

    trame->Data[2] |= (unsigned char)( ( (Eana3) & 0xFF) );

    trame->Data[1] |= (unsigned char)( ( (Eana2) & 0xFF) );

    trame->Data[0] |= (unsigned char)( ( (Eana1) & 0xFF) );

    return(trame);
}



//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ECRAN_ETAT_ECRAN::CTrameLaBotBox_ECRAN_ETAT_ECRAN()
{
  m_ID = ID_ETAT_ECRAN;
  m_DLC = DLC_ETAT_ECRAN;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ECRAN_ETAT_ECRAN

		- Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_ECRAN_ETAT_ECRAN::Decode(tStructTrameLaBotBox *trameRecue)
{
  //long lDonnee_temp = 0; // utilisé si besoin pour le décodage des données en flottant

   // Decode les signaux de la trame
   Valeur = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

   CodeCommande = ( ( ((unsigned short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}


//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ECRAN_ETAT_MATCH::CTrameLaBotBox_ECRAN_ETAT_MATCH()
{
  m_ID = ID_ETAT_MATCH;
  m_DLC = DLC_ETAT_MATCH;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ECRAN_ETAT_MATCH
        - Renseigne les champs de la structure de donnee de la trame a transmettre
   \param trame pointeur sur une structure trame deja alloue
   \return le pointeur sur la trame a envoyer (renvoie le pointeur recu)
   */
tStructTrameLaBotBox* CTrameLaBotBox_ECRAN_ETAT_MATCH::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

    // Encode chacun des signaux de la trame
    trame->Data[5] |= (unsigned char)( ( (ChoixStrategie) & 0xFF) );

    trame->Data[4] |= (unsigned char)( ( (Score) & 0xFF) );
    trame->Data[3] |= (unsigned char)( ( (Score >> 8) & 0xFF) );

    trame->Data[2] |= (unsigned char)( ( (OrigineDetectionObstacle) & 0x1) << 7 );

    trame->Data[2] |= (unsigned char)( ( (ObstacleDetecte) & 0x1) << 6 );

    trame->Data[2] |= (unsigned char)( ( (DiagBlocage) & 0x1) << 5 );

    trame->Data[2] |= (unsigned char)( ( (ConvergenceAsserv) & 0x1) << 4 );

    trame->Data[2] |= (unsigned char)( ( (ModeFonctionnement) & 0xF) );

    trame->Data[1] |= (unsigned char)( ( (CouleurEquipe) & 0xFF) );

    trame->Data[0] |= (unsigned char)( ( (TempsMatch) & 0xFF) );

    return(trame);
}

//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ETAT_EVITEMENT_OBSTACLE::CTrameLaBotBox_ETAT_EVITEMENT_OBSTACLE()
{
  m_ID = ID_ETAT_EVITEMENT_OBSTACLE;
  m_DLC = DLC_ETAT_EVITEMENT_OBSTACLE;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ETAT_EVITEMENT_OBSTACLE
        - Renseigne les champs de la structure de donnee de la trame a transmettre
   \param trame pointeur sur une structure trame deja alloue
   \return le pointeur sur la trame a envoyer (renvoie le pointeur recu)
   */
tStructTrameLaBotBox* CTrameLaBotBox_ETAT_EVITEMENT_OBSTACLE::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

    // Encode chacun des signaux de la trame
    trame->Data[5] |= (unsigned char)( ( (ChoixStrategieEvitement) & 0xFF) );

    trame->Data[4] |= (unsigned char)( ( (NombreTentatives) & 0xFF) );

    trame->Data[3] |= (unsigned char)( ( (NumeroEtape) & 0xFF) );

    trame->Data[2] |= (unsigned char)( ( (ObstacleBitfield) & 0xFF) );

    trame->Data[1] |= (unsigned char)( ( (SensDeplacement) & 0xFF) );

    trame->Data[0] |= (unsigned char)( ( (ForcageDetectObstacleSansPosition) & 0x1) << 3 );
    trame->Data[0] |= (unsigned char)( ( (ObstacleInhibe) & 0x1) << 2 );
    trame->Data[0] |= (unsigned char)( ( (EvitementEnCours) & 0x1) << 1 );
    trame->Data[0] |= (unsigned char)( ( (ObstacleDetecte) & 0x1) << 0 );

    return(trame);
}

//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ETAT_RACK::CTrameLaBotBox_ETAT_RACK()
{
  m_ID = ID_ETAT_RACK;
  m_DLC = DLC_ETAT_RACK;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ETAT_RACK
        - Renseigne les champs de la structure de donnee de la trame a transmettre
   \param trame pointeur sur une structure trame deja alloue
   \return le pointeur sur la trame a envoyer (renvoie le pointeur recu)
   */
tStructTrameLaBotBox* CTrameLaBotBox_ETAT_RACK::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

  	// Encode chacun des signaux de la trame
    trame->Data[7] |= (unsigned char)( ( (rack_reserve) & 0xFF) );
    trame->Data[6] |= (unsigned char)( ( (rack_reserve >> 8) & 0xFF) );

    trame->Data[5] |= (unsigned char)( ( (rack_modeAsservissement) & 0xFF) );

    trame->Data[3] |= (unsigned char)( ( (rack_cde_moteur) & 0xFF) );
    trame->Data[2] |= (unsigned char)( ( (rack_cde_moteur >> 8) & 0xFF) );

    trame->Data[1] |= (unsigned char)( ( (rack_consigne_moteur) & 0xFF) );
    trame->Data[0] |= (unsigned char)( ( (rack_consigne_moteur >> 8) & 0xFF) );

    trame->Data[4] |= (unsigned char)( ( (rack_convergence) & 0xFF) );

    return(trame);
}

//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_ELECTROBOT_COLOR_SENSOR::CTrameLaBotBox_ELECTROBOT_COLOR_SENSOR()
{
  m_ID = ID_ELECTROBOT_COLOR_SENSOR;
  m_DLC = DLC_ELECTROBOT_COLOR_SENSOR;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_COLOR_SENSOR
        - Renseigne les champs de la structure de donnee de la trame a transmettre
   \param trame pointeur sur une structure trame deja alloue
   \return le pointeur sur la trame a envoyer (renvoie le pointeur recu)
   */
tStructTrameLaBotBox* CTrameLaBotBox_ELECTROBOT_COLOR_SENSOR::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

    trame->Data[1] |= (unsigned char)( ( (R) & 0xFF) );
    trame->Data[0] |= (unsigned char)( ( (R >> 8) & 0xFF) );

    trame->Data[3] |= (unsigned char)( ( (G) & 0xFF) );
    trame->Data[2] |= (unsigned char)( ( (G >> 8) & 0xFF) );

    trame->Data[5] |= (unsigned char)( ( (B) & 0xFF) );
    trame->Data[4] |= (unsigned char)( ( (B >> 8) & 0xFF) );

    return(trame);
}

//___________________________________________________________________________
 /*!
   \brief Constructeur
   \param --
   \return --
   */
CTrameLaBotBox_CONFIG_PERIODE_TRAME::CTrameLaBotBox_CONFIG_PERIODE_TRAME()
{
  m_ID = ID_CONFIG_PERIODE_TRAME;
  m_DLC = DLC_CONFIG_PERIODE_TRAME;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame CONFIG_PERIODE_TRAME

        - Renseigne les champs de la structure de donnee de la trame
   \param bufBrut le buffer des octets de la trames a decoder
   \return --
   */
void CTrameLaBotBox_CONFIG_PERIODE_TRAME::Decode(tStructTrameLaBotBox *trameRecue)
{
   // Decode les signaux de la trame
   Periode = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

   ID = ( ( ((unsigned short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[0])) & 0xFF) << 8 );


  m_new_trame = true;
  m_nombre_recue++;
}

// ========================================================
//             TRAME MBED_CMDE
// ========================================================
CTrameLaBotBox_MBED_CMDE::CTrameLaBotBox_MBED_CMDE()
{
    m_ID = ID_MBED_CMDE;
    m_DLC = DLC_MBED_CMDE;
}

//___________________________________________________________________________
/*!
  \brief Encode et envoie la trame
*/
void CTrameLaBotBox_MBED_CMDE::Decode(tStructTrameLaBotBox *trameRecue)
{
    Valeur_04 = ( ((short)(trameRecue->Data[7])) & 0xFF);
    Valeur_03 = ( ((short)(trameRecue->Data[6])) & 0xFF) ;

    Valeur_02 = ( ( ((short)(trameRecue->Data[5])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[4])) & 0xFF) << 8 );

    Valeur_01 = ( ( ((short)(trameRecue->Data[3])) & 0xFF) )  |  ( ( ((short)(trameRecue->Data[2])) & 0xFF) << 8 );

    CodeCommande = ( ( ((unsigned short)(trameRecue->Data[1])) & 0xFF) )  |  ( ( ((unsigned short)(trameRecue->Data[0])) & 0xFF) << 8 );

    m_new_trame = true;
    m_nombre_recue++;
}

// ========================================================
//             TRAME MBED_ETAT
// ========================================================
CTrameLaBotBox_MBED_ETAT::CTrameLaBotBox_MBED_ETAT()
{
    m_ID = ID_MBED_ETAT;
    m_DLC = DLC_MBED_ETAT;
}
//___________________________________________________________________________
/*!
  \brief Decode les signaux de la trame
  \param trameRecue la trame brute recue a decoder
*/
tStructTrameLaBotBox* CTrameLaBotBox_MBED_ETAT::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

    // Encode chacun des signaux de la trame
    trame->Data[7] |= (unsigned char)( ( (Valeur_mbed_etat_04) & 0xFF) );
    trame->Data[6] |= (unsigned char)( ( (Valeur_mbed_etat_03) & 0xFF) );

    trame->Data[5] |= (unsigned char)( ( (Valeur_mbed_etat_02) & 0xFF) );
    trame->Data[4] |= (unsigned char)( ( (Valeur_mbed_etat_02 >> 8) & 0xFF) );

    trame->Data[3] |= (unsigned char)( ( (Valeur_mbed_etat_01) & 0xFF) );
    trame->Data[2] |= (unsigned char)( ( (Valeur_mbed_etat_01 >> 8) & 0xFF) );

    trame->Data[1] |= (unsigned char)( ( (Cde_mbed_etat) & 0xFF) );
    trame->Data[0] |= (unsigned char)( ( (Cde_mbed_etat >> 8) & 0xFF) );

    return(trame);
}

// ========================================================
//             TRAME ETAT_SERVO_AX
// ========================================================
CTrameLaBotBox_ETAT_SERVO_AX::CTrameLaBotBox_ETAT_SERVO_AX()
{
    m_ID = ID_ETAT_SERVO_AX;
    m_DLC = DLC_ETAT_SERVO_AX;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_ETAT_CAPTEURS_1
        - Renseigne les champs de la structure de donnee de la trame a transmettre
   \param trame pointeur sur une structure trame deja alloue
   \return le pointeur sur la trame a envoyer (renvoie le pointeur recu)
   */
tStructTrameLaBotBox* CTrameLaBotBox_ETAT_SERVO_AX::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

    // Encode chacun des signaux de la trame
    CDataEncoderDecoder::encode_int8(trame->Data,     0,  num_servo_ax);
    CDataEncoderDecoder::encode_int16(trame->Data,    1,  position);
    CDataEncoderDecoder::encode_int8(trame->Data,     3,  temperature);
    CDataEncoderDecoder::encode_int16(trame->Data,    4,  couple);
    CDataEncoderDecoder::encode_int8(trame->Data,     6,  mouvement_en_cours);

    return(trame);
}

// ========================================================
//             TRAME COMMANDE_KMAR
// ========================================================
CTrameLaBotBox_COMMANDE_KMAR::CTrameLaBotBox_COMMANDE_KMAR()
{
    m_ID = ID_COMMANDE_KMAR;
    m_DLC = DLC_COMMANDE_KMAR;
}

//___________________________________________________________________________
/*!
  \brief Encode et envoie la trame
*/
void CTrameLaBotBox_COMMANDE_KMAR::Decode(tStructTrameLaBotBox *trameRecue)
{

    num_kmar = CDataEncoderDecoder::decode_int8(trameRecue->Data, 0);
    cmd_kmar = CDataEncoderDecoder::decode_int16(trameRecue->Data, 1);
    value_cmd_kmar = CDataEncoderDecoder::decode_int16(trameRecue->Data, 3);

    m_new_trame = true;
    m_nombre_recue++;
}

// ========================================================
//             TRAME ETAT_KMAR_GENERAL
// ========================================================
CTrameLaBotBox_ETAT_KMAR_GENERAL::CTrameLaBotBox_ETAT_KMAR_GENERAL()
{
    m_ID = ID_ETAT_KMAR_GENERAL;
    m_DLC = DLC_ETAT_KMAR_GENERAL;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame ELECTROBOT_ETAT_CAPTEURS_1
        - Renseigne les champs de la structure de donnee de la trame a transmettre
   \param trame pointeur sur une structure trame deja alloue
   \return le pointeur sur la trame a envoyer (renvoie le pointeur recu)
   */
tStructTrameLaBotBox* CTrameLaBotBox_ETAT_KMAR_GENERAL::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

    // Encode chacun des signaux de la trame
    CDataEncoderDecoder::encode_int8(trame->Data,     0,  num_kmar);
    CDataEncoderDecoder::encode_int8(trame->Data,     1,  status);
    CDataEncoderDecoder::encode_int8(trame->Data,     2,  num_mouvement_en_cours);
    CDataEncoderDecoder::encode_bit(trame->Data, 3, 0, moving);
    CDataEncoderDecoder::encode_bit(trame->Data, 3, 1, axis1_moving);
    CDataEncoderDecoder::encode_bit(trame->Data, 3, 2, axis2_moving);
    CDataEncoderDecoder::encode_bit(trame->Data, 3, 3, axis3_moving);
    CDataEncoderDecoder::encode_bit(trame->Data, 3, 4, axis4_moving);
    CDataEncoderDecoder::encode_bit(trame->Data, 3, 5, object_catched);
    CDataEncoderDecoder::encode_int16(trame->Data,  4,  axis1_position);
    CDataEncoderDecoder::encode_int16(trame->Data,  6,  axis2_position);
    CDataEncoderDecoder::encode_int16(trame->Data,  8,  axis3_position);
    CDataEncoderDecoder::encode_int16(trame->Data,  10, axis4_position);

    return(trame);
}


// ========================================================
//             TRAME ETAT_LIDAR
// ========================================================
CTrameLaBotBox_ETAT_LIDAR::CTrameLaBotBox_ETAT_LIDAR()
{
    m_ID = ID_ETAT_LIDAR;
    m_DLC = DLC_ETAT_LIDAR;
    m_last_time_rx = 0;
}

//___________________________________________________________________________
/*!
  \brief Encode et envoie la trame
*/
void CTrameLaBotBox_ETAT_LIDAR::Decode(tStructTrameLaBotBox *trameRecue)
{
    m_status = CDataEncoderDecoder::decode_int8(trameRecue->Data, 0);

    //  Recupere les infos des 20 obstacles :
    // 24 bits pour vehiculer angle (non signe [0;360deg] sur 12 bits) et distance (sur 12 bits)
    // 12 bits MSB : angle / 12 bits LSB : distance
    //   octet 1 |  octet2  |  octet3 |       octet4 |  octet5  |  octet6     ...
    //  xxxx xxxx xxxx  xxxx xxxx xxxx       xxxx xxxx xxxx  xxxx xxxx xxxx    ...
    // <     ANGLE1   ><   DISTANCE1  >     <     ANGLE2   ><   DISTANCE2  >   ...
    int _byte_num = 1;
    for (int i=0; i<LidarUtils::NBRE_MAX_OBSTACLES; i++) {
        unsigned long ulval_24bits = CDataEncoderDecoder::decode_uint24(trameRecue->Data, _byte_num);
        m_obstacles[i].angle = ((ulval_24bits >> 12)&0xFFF) - 180; // ramene l'angle de [0;360] a [-180;+180]
        m_obstacles[i].distance = ulval_24bits & 0xFFF;
        _byte_num+=3;
    }

    m_new_trame = true;
    m_nombre_recue++;
    m_last_time_rx = _Global_Timer.read_ms();  // note l'heure de la derniere reception pour la detection de perte de communication
}

// ========================================================
//             TRAME FREE_STRING
// ========================================================
CTrameLaBotBox_FREE_STRING::CTrameLaBotBox_FREE_STRING()
{
    m_ID = ID_FREE_STRING;
    m_DLC = DLC_FREE_STRING;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame
        - Renseigne les champs de la structure de donnee de la trame a transmettre
   \param trame pointeur sur une structure trame deja alloue
   \return le pointeur sur la trame a envoyer (renvoie le pointeur recu)
   */
tStructTrameLaBotBox* CTrameLaBotBox_FREE_STRING::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

    // Encode chacun des signaux de la trame
    for (int i=0; i<m_DLC; i++) {
        trame->Data[i] = m_str[i];
    }

    return(trame);
}

// ========================================================
//             TRAME ETAT_KMAR_GENERAL
// ========================================================
CTrameLaBotBox_ETAT_CHARGE_CPU::CTrameLaBotBox_ETAT_CHARGE_CPU()
{
    m_ID = ID_ETAT_CHARGE_CPU;
    m_DLC = DLC_ETAT_CHARGE_CPU;
}
//___________________________________________________________________________
 /*!
   \brief Decode les signaux de la trame
        - Renseigne les champs de la structure de donnee de la trame a transmettre
   \param trame pointeur sur une structure trame deja alloue
   \return le pointeur sur la trame a envoyer (renvoie le pointeur recu)
   */
tStructTrameLaBotBox* CTrameLaBotBox_ETAT_CHARGE_CPU::Encode(tStructTrameLaBotBox* trame)
{
    initTrame(trame);

    // Encode chacun des signaux de la trame
    CDataEncoderDecoder::encode_uint32(trame->Data,    0,  cpu_overload_counter);
    CDataEncoderDecoder::encode_uint32(trame->Data,    4,  task_real_period_usec);

    return(trame);
}

/*! @} */

