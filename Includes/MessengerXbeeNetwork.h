#ifndef _XBEE_NETWORK_MESSENGER_H_
#define _XBEE_NETWORK_MESSENGER_H_

#include "databasexbeenetwork2019.h"
#include "transportergeneric.h"
#include "messengerinterfacebase.h"
#include "xbeedriver.h"


// ====================================================
//
// ====================================================
class MessengerXbeeNetwork : public MessengerInterfaceBase
{
public:
    MessengerXbeeNetwork();
    virtual ~MessengerXbeeNetwork();

    void start();
    void stop();
    void execute();
    void IRQ_ReceiveRS232();

    void readEEPROM();

    // =============================================
    //    Reimplement MessengerInterfaceBase virual
    virtual void encode(unsigned char *buff_data, unsigned short buff_size, unsigned short dest_address=0);

    // Events
    // This method is called by messenger (transporter) to inform a valid frame was received
    virtual void newFrameReceived(tMessengerFrame *frame);
    // This method is called by messenger (transporter) to inform a frame was transmited
    virtual void frameTransmited(tMessengerFrame *frame);
    // This method is called by messenger (database) to inform a known message was received
    virtual void newMessageReceived(MessageBase *msg);
    // This method is called by messenger (database) to inform a message was transmited
    virtual void messageTransmited(MessageBase *msg);
    // This method is called by messenger (message) to inform a data in a message was updated
    virtual void dataUpdated(char *name, char *val_str);
    // This method is called by messenger (message) to inform a data in a message changed value
    virtual void dataChanged(char *name, char *val_str);

    bool isRobotPartnerPresent();
    bool isExperiencePresent();
    bool isBalisePresent();

    DatabaseXbeeNetwork2019 m_database;
    TransporterGeneric m_transporter;

    //! Xbee driver
    XbeeDriver m_xbee;
    //! Xbee settings
    tXbeeSettings m_xbee_settings;

    void debug_settings();

private :
    long m_robot_partner_last_rx_time;
    long m_experience_last_rx_time;
    long m_balise_last_rx_time;
    bool m_robot_partner_present;
    bool m_experience_present;
    bool m_balise_present;

    void diag_robot_partener(long current_time);
    void diag_experience(long current_time);
    void diag_balise(long current_time);
};

#endif // _XBEE_NETWORK_MESSENGER_H_
