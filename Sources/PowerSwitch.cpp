#include "RessourcesHardware.h"
#include "PowerSwitch.h"



PowerSwitch::PowerSwitch()
{
}

PowerSwitch::~PowerSwitch()
{
}

// ______________________________________________
void PowerSwitch::writeI2C(unsigned char addr, unsigned char *data, unsigned char len)
{
    _i2c.write(addr, (const char*)data, len);
}

// ______________________________________________
void PowerSwitch::readI2C(unsigned char addr, unsigned char *dest_data, unsigned char len)
{
    _i2c.read(addr, (char*)dest_data, len);
}

// ______________________________________________
void PowerSwitch::init(unsigned char i2c_address_8bits)
{
    setAddress(i2c_address_8bits);
    configDirections(0xFF, 0);  // Switchs connectés au port B : sorties / Port A inutilisé : entrées
    clearAll();
}

// ______________________________________________
void PowerSwitch::setOutput(unsigned char input, bool val)
{
    writeBitPortB(input, val);
}

// ______________________________________________
void PowerSwitch::setPort(unsigned char val)
{
    writePortB(val);
}

// ______________________________________________
void PowerSwitch::clearAll()
{
    writePorts(0, 0);
}
