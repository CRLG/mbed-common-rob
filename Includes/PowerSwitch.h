#ifndef _POWER_SWITCH_H_
#define _POWER_SWITCH_H_

#include "mcp23017base.h"


// ====================================================
//
// ====================================================
class PowerSwitch : public MCP23017Base
{
public:

typedef enum {
    XT1_OUTPUT = 0, // PORTB.0
    XT2_OUTPUT = 1, // PORTB.1
    XT3_OUTPUT = 2, // PORTB.2
    XT4_OUTPUT = 3, // PORTB.3
    XT5_OUTPUT = 4, // PORTB.4
    XT6_OUTPUT = 5, // PORTB.5
    XT7_OUTPUT = 6, // PORTB.6
    XT8_OUTPUT = 7, // PORTB.7
}tPowerSwitchOutput;

    PowerSwitch();
    virtual ~PowerSwitch();

    // =============================================
    //    Reimplement MessengerInterfaceBase virual
    virtual void writeI2C(unsigned char addr, unsigned char *data, unsigned char len);
    virtual void readI2C(unsigned char addr, unsigned char *dest_data, unsigned char len);

    void init(unsigned char i2c_address_8bits);
    void setOutput(unsigned char input, bool val);
    void clearAll();
};

#endif // _POWER_SWITCH_H_
