#include "RessourcesHardware.h"
#include "ConfigSpecifiqueCoupe.h"
#include "CGlobale.h"  // pour l'accès au module EEPROM
#include "CServoMoteurAX.h"

CServoMoteurAX::CServoMoteurAX()
{
    m_present_count = 0;
}

CServoMoteurAX::~CServoMoteurAX()
{
}

// ============================================================
//         IMPLEMENTATION DES METHODES VIRTUELLES PURES
//                  (en lien avec le hardware)
// ============================================================
// ______________________________________________________________
tAxErr CServoMoteurAX::read(unsigned char *buff_data, unsigned char size)
{
    unsigned long _timeout=0;
    unsigned char index=0;

    for (_timeout=0; _timeout<0xFFFF; _timeout++) {
        if (_ax12_serial.readable()) {
            buff_data[index++] = _ax12_serial.getc();
            _timeout = 0;
        }
        if (index == size) return AX_OK;
    }
    return AX_TIMEOUT;
}

// ______________________________________________________________
tAxErr CServoMoteurAX::write(unsigned char *buff_data, unsigned char size)
{
    for (unsigned char i=0; i<size; i++) {
        _ax12_serial.putc(buff_data[i]);
    }
    return AX_OK;
}

// ______________________________________________________________
tAxErr CServoMoteurAX::flushSerialInput()
{
    while (_ax12_serial.readable()) _ax12_serial.getc();  // flush serial input
    return AX_OK;
}

// ______________________________________________________________
tAxErr CServoMoteurAX::waitTransmitComplete()
{
    //! warning : LPC_UART2 correspond to p27 / p28 MBED UART pins
    while((LPC_UART2->LSR & 0x00000040) == 0){}  // wait for serial tx fifo empty
    return AX_OK;
}

// ______________________________________________________________
tAxErr CServoMoteurAX::setTxEnable(bool state)
{
    _STOR_AX_TX_ENABLE = state;
    return AX_OK;
}

// ______________________________________________________________
void CServoMoteurAX::delay_us(unsigned long delay)
{
    wait_us(delay);
}

// ============================================================
//           REDIRECTION DES FONCTIONS POUR YAKINDU
//              (Ticket Itemis 2018102237000178)
// Problème :
//   Les méthodes de la classe de base ne sont pas accessibles
//    depuis le modèle Yakindu.
// Solution :
//  Rediriger les fonctions accessibles depuis le modèle vers la
//    classe de base.
// ============================================================
// ____________________________________________________________
bool CServoMoteurAX::isPresent(unsigned char id)
{
    return ServoAXBase::isPresent(id);
}

// ____________________________________________________________
tAxErr CServoMoteurAX::setPosition(unsigned char id, unsigned short position)
{
    return ServoAXBase::setPosition(id, position);
}

// ____________________________________________________________
tAxErr CServoMoteurAX::setSpeed(unsigned char id, unsigned short speed)
{
   return ServoAXBase::setSpeed(id, speed);
}

// ____________________________________________________________
tAxErr CServoMoteurAX::setPositionSpeed(unsigned char id, unsigned short position, unsigned short speed)
{
    return ServoAXBase::setPositionSpeed(id, position, speed);
}

// ____________________________________________________________
unsigned short CServoMoteurAX::getPosition(unsigned char id, tAxErr *err_status)
{
    return ServoAXBase::getPosition(id, err_status);
}

// ____________________________________________________________
bool CServoMoteurAX::isMoving(unsigned char id, tAxErr *err_status)
{
    return ServoAXBase::isMoving(id, err_status);
}

// ____________________________________________________________
tAxErr CServoMoteurAX::changeID(unsigned char old_id, unsigned char new_id)
{
    return ServoAXBase::changeID(old_id, new_id);
}

// ____________________________________________________________
tAxErr CServoMoteurAX::enableTorque(unsigned char id, bool on_off)
{
    return ServoAXBase::enableTorque(id, on_off);
}

// ____________________________________________________________
tAxErr CServoMoteurAX::setMode(unsigned char id, unsigned char mode)
{
    return ServoAXBase::setMode(id, mode);
}

// ____________________________________________________________
tAxErr CServoMoteurAX::setLimitPositionMin(unsigned char id, unsigned short pos)
{
    return ServoAXBase::setLimitPositionMin(id, pos);
}

// ____________________________________________________________
tAxErr CServoMoteurAX::setLimitPositionMax(unsigned char id, unsigned short pos)
{
    return ServoAXBase::setLimitPositionMax(id, pos);
}




// ____________________________________________________________
// Detect all AX servo present
tAxErr CServoMoteurAX::checkPresents(unsigned char max_id)
{
    m_present_count = 0;
    for (unsigned char i=0; i<=max_id; i++)
    {
        if (isPresent(i)) m_presents_list[m_present_count++] = i;
        delay_us(5000);
    }
    return AX_OK;
}

// ______________________________________________________________
tAxErr CServoMoteurAX::Init(void)
{
    tAxErr err;
    err = readEEPROM(); // Lit l'EEPROM et configure le module

    setTxEnable(false);
    _ax12_serial.baud(1000000);

    for (unsigned char i=0; i<NBRE_SERVOS_AX; i++) m_presents_list[i] = -1;  // par défaut, aucun n'est détecté
    m_present_count = 0;
    checkPresents(20); // limite la recherche aux 20 premiers ID

    return err;
}

// ______________________________________________________________
// Point d'entrée à appeler périodiquement pour la lecture des positions
//  et autres infos sur le servo
// Ne nécessite pas d'être appelé si le servo AX est utilisé en TX uniquement (les infos du servo AX ne sont pas lues)
tAxErr CServoMoteurAX::compute()
{
    tAxErr err;
    int count_error =0;

    for (int i=0; i<m_present_count;i++)
    {
        int position = getPosition(m_presents_list[i], &err);
        if (err == AX_OK)   m_positions[i] = position;
        else {
            m_positions[i] = 0xFFFF;
            count_error++;
        }
    }
    for (int i=0; i<m_present_count;i++)
    {
        bool ismoving= isMoving(m_presents_list[i], &err);
        if (err == AX_OK)   m_moving[i] = ismoving;
        else {
            m_moving[i] = 1;  // par défaut, si la lecture n'est pas possible, on considère que le servo est en mouvement
            count_error++;
        }
    }
    return count_error==0?AX_OK:AX_INVALID_VALUE;
}


// ______________________________________________________________
// Recherche dans la liste des présents, l'ID
int CServoMoteurAX::servo_id_to_index_present(unsigned char servo_id)
{
    int index = -1;
    for (int i=0; i<NBRE_SERVOS_AX; i++) {
        if(m_presents_list[i] == servo_id) {
            index = i;
            break; // pas la peine de rechercher plus loin, on a trouvé
        }
    }
    return index;
}

// ______________________________________________________________
tAxErr CServoMoteurAX::readEEPROM(void)
{
    tAxErr err;
    // _________________________
    // Lecture des parmaètres de configuration des servos dans l'EEPROM :
    //    - Butée min
    //    - Butée max
    //    - Position initiale à la mise sous tension
    char sBuff[64]="\0";
    unsigned int servo_val;
    for (unsigned int i=0; i<NBRE_SERVOS_AX; i++) {
        sprintf(sBuff, "butee_min_servo_ax_%d", i);
        if (Application.m_eeprom.getValue(sBuff, &servo_val)) {
            err = setLimitPositionMin(i, servo_val);
            if (err != AX_OK) return err;
        }

        sprintf(sBuff, "butee_max_servo_ax_%d", i);
        if (Application.m_eeprom.getValue(sBuff, &servo_val)) {
            err = setLimitPositionMax(i, servo_val);
            if (err != AX_OK) return err;
        }

        sprintf(sBuff, "position_initiale_servo_ax_%d", i);
        if (Application.m_eeprom.getValue(sBuff, &servo_val)) {
            err = setPosition(i, servo_val);
            if (err != AX_OK) return err;
            wait (0.4); // Tempo pour être certain que tous les servos ne bougent pas en même temps (surconsommation)
        }
    }
    return AX_OK;
}
