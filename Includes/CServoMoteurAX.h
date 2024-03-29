#ifndef CServoMoteurAX_H
#define CServoMoteurAX_H

#include "servoaxbase.h"

#define NBRE_SERVOS_AX      (253)

class CServoMoteurAX : public ServoAXBase
{
public:
    CServoMoteurAX();
    ~CServoMoteurAX();

    // pure virtual methods to abstract hardware.
    // to be implemented on specific hardware.
    virtual tAxErr read(unsigned char *buff_data, unsigned char size);
    virtual tAxErr write(unsigned char *buff_data, unsigned char size);
    virtual tAxErr flushSerialInput();
    virtual tAxErr waitTransmitComplete();
    virtual tAxErr setTxEnable(bool state);
    virtual void delay_us(unsigned long delay);

    virtual bool isPresent(unsigned char id);
    virtual tAxErr setPosition(unsigned char id, unsigned short position);
    virtual unsigned short getPosition(unsigned char id, tAxErr *err_status=nullptr);
    virtual tAxErr setSpeed(unsigned char id, unsigned short speed);
    virtual tAxErr setPositionSpeed(unsigned char id, unsigned short position, unsigned short speed);
    virtual bool isMoving(unsigned char id, tAxErr *err_status=nullptr);
    virtual tAxErr changeID(unsigned char old_id, unsigned char new_id);
    virtual tAxErr enableTorque(unsigned char id, bool on_off=true);
    virtual tAxErr setMode(unsigned char id, unsigned char mode);
    virtual tAxErr setLimitPositionMin(unsigned char id, unsigned short pos);
    virtual tAxErr setLimitPositionMax(unsigned char id, unsigned short pos);

    virtual tAxErr checkPresents(unsigned char max_id=NBRE_SERVOS_AX);

    tAxErr Init();

    // a appeler périodiquement pour la lecture des états servos
    tAxErr compute();

    int servo_id_to_index_present(unsigned char servo_id);

    int m_presents_list[NBRE_SERVOS_AX];    // list all AX detected when checkPresents() called
    int m_positions[NBRE_SERVOS_AX];
    int m_moving[NBRE_SERVOS_AX];
    unsigned char m_present_count;

private :
    tAxErr readEEPROM();
};

#endif // CServoMoteurAX_H
