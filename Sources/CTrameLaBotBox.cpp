/*! \file CTrameLaBotBox.cpp
	\brief Classe qui contient les méthodes pour le dialogue avec ANACONBOT
*/
#include "mbed.h"
#include "RessourcesHardware.h"
#include "CTrameLaBotBox.h"

//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CTrameLaBotBox::CTrameLaBotBox() 
{
  m_nombre_recue = 0;
  m_new_trame = false;
  m_tx_periode = NO_PERIODIC;
  m_last_time_tx = 0;
}

//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CTrameLaBotBox::~CTrameLaBotBox() 
{

}

//___________________________________________________________________________
 /*!
   \brief Decodage d'une trame brute reçue
   \param trameRecue la trame brute à décoder
   \return --
   \remark Méthode de la classe mère jamais appelée
*/
void CTrameLaBotBox::Decode(tStructTrameLaBotBox *trameRecue)
{
}

//___________________________________________________________________________
 /*!
   \brief Encodage de la trame pour envoie
   \param --
   \return la trame à envoyer
   \remark Méthode de la classe mère jamais appelée
*/
tStructTrameLaBotBox* CTrameLaBotBox::Encode(void)
{
    return nullptr;
}

//___________________________________________________________________________
 /*!
   \brief Indique si une nouvelle trame a ete recue
   \param --
   \return true si une trame a ete recue / false sinon
*/
bool CTrameLaBotBox::isNewTrame(void)
{
  if (m_new_trame) { 
  		m_new_trame = false; 
		return(true); 
  }
  return(false);
}

//___________________________________________________________________________
 /*!
   \brief Fixe la période d'émission de la trame
   \param period_msec la période souhaitée en msec
   \return --
*/
void CTrameLaBotBox::setTransmitPeriod(short period_msec)
{
    m_tx_periode = period_msec;
}

//___________________________________________________________________________
 /*!
   \brief Encode une donnée 8 bits dans le buffer
   \param buff : le buffer de destination
   \param position : position de la data dans le buffer
   \param data : la valeur à encoder
   \return --
*/
void CTrameLaBotBox::encode_int8(unsigned char *buff, unsigned char position, unsigned char data)
{
    buff[position] = data;
}

//___________________________________________________________________________
 /*!
   \brief Encode une donnée 16 bits dans le buffer (MSB first)
   \param buff : le buffer de destination
   \param position : position de la data dans le buffer
   \param data : la valeur à encoder
   \return --
*/
void CTrameLaBotBox::encode_int16(unsigned char *buff, unsigned char position, unsigned short data)
{
    buff[position]      = (data >> 8)&0xFF;
    buff[position+1]    = (data&0xFF);
}
//___________________________________________________________________________
 /*!
   \brief Encode une donnée 32 bits dans le buffer (MSB first)
   \param buff : le buffer de destination
   \param position : position de la data dans le buffer
   \param data : la valeur à encoder
   \return --
*/
void CTrameLaBotBox::encode_int32(unsigned char *buff, unsigned char position, unsigned long data)
{
    buff[position]      = (data >> 24)&0xFF;
    buff[position+1]    = (data >> 16)&0xFF;
    buff[position+2]    = (data >> 8)&0xFF;
    buff[position+3]    = (data&0xFF);
}

//___________________________________________________________________________
 /*!
   \brief Décode une donnée 8 bits du buffer
   \param buff : le buffer de destination
   \param position : position de la data dans le buffer
   \return la data sur 8 bits
*/
unsigned char CTrameLaBotBox::decode_int8(unsigned char *buff, unsigned char position)
{
    return buff[position];
}

//___________________________________________________________________________
 /*!
   \brief Décode une donnée 16 bits du buffer (MSB first)
   \param buff : le buffer de destination
   \param position : position de la data dans le buffer
   \return la data sur 16 bits
*/
unsigned short CTrameLaBotBox::decode_int16(unsigned char *buff, unsigned char position)
{
    return ( ( ((unsigned short)(buff[position+1])) & 0xFF) )  |  ( ( ((unsigned short)(buff[position])) & 0xFF) << 8 ) ;
}

//___________________________________________________________________________
 /*!
   \brief Décode une donnée 32 bits du buffer (MSB first)
   \param buff : le buffer de destination
   \param position : position de la data dans le buffer
   \return la data sur 32 bits
*/
unsigned long CTrameLaBotBox::decode_int32(unsigned char *buff, unsigned char position)
{
    return ( ( ((unsigned long)(buff[position+3])) & 0xFF) )  |
            ( ( ((unsigned long)(buff[position+2])) & 0xFF) << 8 ) |
            ( ( ((unsigned long)(buff[position+1])) & 0xFF) << 16 ) |
            ( ( ((unsigned long)(buff[position])) & 0xFF) << 24 );
}


//___________________________________________________________________________
 /*!
   \brief Vérifie s'il est l'heure d'émettre la trame périodique
   \param --
   \return true si l'heure est venue d'émettre la trame / false sinon
*/
bool CTrameLaBotBox::isTimeToSend()
{
    if (m_tx_periode == NO_PERIODIC) return false;

    int current_time = _Global_Timer.read_ms();
    int diff = current_time - m_last_time_tx;
    if ( (diff >= m_tx_periode) || (diff < 0) )  // test sur diff<0 : prend en compte le cas du débordement du  GLobal_Timer au bout de 30minutes après le boot
    {
        m_last_time_tx = current_time;
        return true;
    }
    return false;
}







