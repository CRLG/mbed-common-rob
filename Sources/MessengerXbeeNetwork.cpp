#include "MessengerXbeeNetwork.h"
#include "messagebase.h"
#include "CGlobale.h"

MessengerXbeeNetwork::MessengerXbeeNetwork()
{
    init(&m_transporter, &m_database);
    m_database.m_TimestampMatch.setDestinationAddress(0xFFFF);
    m_database.m_TimestampMatch.setTransmitPeriod(1000);

    m_robot_partner_last_rx_time = 0;
    m_experience_last_rx_time = 0;
    m_balise_last_rx_time = 0;
    m_robot_partner_present = false;
    m_experience_present = false;
    m_balise_present = false;
}

MessengerXbeeNetwork::~MessengerXbeeNetwork()
{
}

// ______________________________________________
void MessengerXbeeNetwork::IRQ_ReceiveRS232()
{
    char rxData;
    rxData = _rs232_xbee_network_rx.getc();
    _rs232_pc_tx.putc(rxData);
    _led3 = !_led3;
    m_xbee.decode(rxData);
}

// ______________________________________________
void MessengerXbeeNetwork::readEEPROM()
{
    Application.m_eeprom.getValue("XBEE.PANID", (char*)&m_xbee_settings.PANID[0]);
    Application.m_eeprom.getValue("XBEE.CHANNEL", &m_xbee_settings.CHANNEL[0]);
    Application.m_eeprom.getValue("XBEE.ID", (char*)&m_xbee_settings.ID);
    Application.m_eeprom.getValue("XBEE.APIMODE", (char*)&m_xbee_settings.APIMODE);
    Application.m_eeprom.getValue("XBEE.SECURITY", (char*)&m_xbee_settings.SECURITY);
    Application.m_eeprom.getValue("XBEE.KEY", &m_xbee_settings.KEY[0]);
    Application.m_eeprom.getValue("XBEE.COORDINATOR", (char*)&m_xbee_settings.COORDINATOR);
    Application.m_eeprom.getValue("XBEE.COORDINATOR_OPTION", (char*)&m_xbee_settings.COORDINATOR_OPTION);

    debug_settings();
}

// ______________________________________________
void MessengerXbeeNetwork::start()
{
    readEEPROM();

    _rs232_xbee_network_tx.baud(9600);
    _rs232_xbee_network_tx.format(8, Serial::None, 1);   	// 8 bits de données / Pas de parité / 1 bit de stop
    _rs232_xbee_network_rx.baud(9600);
    _rs232_xbee_network_rx.format(8, Serial::None, 1);   	// 8 bits de données / Pas de parité / 1 bit de stop

    m_database.restart();
    while (_rs232_xbee_network_rx.readable()) _rs232_xbee_network_rx.getc(); // Nettoie tout octet en attente dans le buffer
    _rs232_xbee_network_rx.attach(this, &MessengerXbeeNetwork::IRQ_ReceiveRS232);  	// Callback sur réception d'une donnée sur la RS232

    m_xbee.init(m_xbee_settings);
    m_xbee.setMessengerInterface(this);
}
// ______________________________________________
void MessengerXbeeNetwork::stop()
{
    _rs232_xbee_network_rx.attach(NULL); // Supprime l'IRQ sur réception RS232
}

// ______________________________________________
void MessengerXbeeNetwork::execute()
{
    int current_time = _Global_Timer.read_ms();
    m_database.checkAndSendPeriodicMessages(current_time);
    diag_robot_partener(current_time);
    diag_experience(current_time);
    diag_balise(current_time);
}

// ===================================================
//          COMMUNICATION DIAGNOSTIC
// ===================================================
// ______________________________________________
void MessengerXbeeNetwork::diag_robot_partener(long current_time)
{
    if (m_database.m_RobotLego2019.isNewMessage()) {
        m_robot_partner_last_rx_time = current_time;
    }
    m_robot_partner_present = (current_time - m_robot_partner_last_rx_time) <= 3000;
}

// ______________________________________________
void MessengerXbeeNetwork::diag_experience(long current_time)
{
    if (m_database.m_ExperienceStatus.isNewMessage()) {
        m_experience_last_rx_time = current_time;
    }
    m_experience_present = (current_time - m_experience_last_rx_time) <= 3000;
}

// ______________________________________________
void MessengerXbeeNetwork::diag_balise(long current_time)
{
    if (m_database.m_BalisePositions.isNewMessage()) {
        m_balise_last_rx_time = current_time;
    }
    m_balise_present = (current_time - m_balise_last_rx_time) <= 3000;
}

// ______________________________________________
bool MessengerXbeeNetwork::isRobotPartnerPresent()
{
    return m_robot_partner_present;
}
// ______________________________________________
bool MessengerXbeeNetwork::isExperiencePresent()
{
    return m_experience_present;
}
// ______________________________________________
bool MessengerXbeeNetwork::isBalisePresent()
{
    return m_balise_present;
}


// ===================================================
//              MESSENGER OUTPUT
// ===================================================
// ______________________________________________
void MessengerXbeeNetwork::encode(unsigned char *buff_data, unsigned short buff_size, unsigned short dest_address)
{
    m_xbee.encode(buff_data, buff_size, dest_address);
}

// ===================================================
//                  MESSENGER EVENTS
// ===================================================
// ______________________________________________
void MessengerXbeeNetwork::newFrameReceived(tMessengerFrame *frame)
{
    (void)frame;
}

// ______________________________________________
void MessengerXbeeNetwork::newMessageReceived(MessageBase *msg)
{
    (void)msg;
}

// ______________________________________________
void MessengerXbeeNetwork::frameTransmited(tMessengerFrame *frame)
{
    (void)frame;
}

// ______________________________________________
void MessengerXbeeNetwork::messageTransmited(MessageBase *msg)
{
    (void)msg;
}

// ______________________________________________
void MessengerXbeeNetwork::dataUpdated(char *name, char *val_str)
{
    (void)name;
    (void)val_str;
}

// ______________________________________________
void MessengerXbeeNetwork::dataChanged(char *name, char *val_str)
{
    (void)name;
    (void)val_str;
}


// ===================================================
//                  LOCAL METHODS
// ===================================================

// ______________________________________________
void MessengerXbeeNetwork::debug_settings()
{
    _rs232_pc_tx.printf("\n\rXBEE SETTINGS\r\n");
    _rs232_pc_tx.printf("  >APIMODE=%c\r\n", m_xbee_settings.APIMODE);
    _rs232_pc_tx.printf("  >XBEE.CHANNEL=%c%c\r\n", m_xbee_settings.CHANNEL[0], m_xbee_settings.CHANNEL[1]);
    _rs232_pc_tx.printf("  >XBEE.COORDINATOR=%c\r\n", m_xbee_settings.COORDINATOR);
    _rs232_pc_tx.printf("  >COORDINATOR_OPTION=%c\r\n", m_xbee_settings.COORDINATOR_OPTION);
    _rs232_pc_tx.printf("  >PANID=%c%c%c%c\r\n", m_xbee_settings.PANID[0], m_xbee_settings.PANID[1], m_xbee_settings.PANID[2], m_xbee_settings.PANID[3]);
    _rs232_pc_tx.printf("  >KEY=");
    for (unsigned int i=0; i<sizeof(m_xbee_settings.KEY); i++) {
        printf("%c", m_xbee_settings.KEY[i]);
    }
    printf("\r\n");
    _rs232_pc_tx.printf("  >ID=%c\r\n", m_xbee_settings.ID);
    _rs232_pc_tx.printf("  >SECURITY=%c\r\n", m_xbee_settings.SECURITY);

}
