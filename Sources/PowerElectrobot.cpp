#include "RessourcesHardware.h"
#include "PowerElectrobot.h"

PowerElectrobot::PowerElectrobot()
{
}

PowerElectrobot::~PowerElectrobot()
{
}

// ______________________________________________
void PowerElectrobot::writeI2C(unsigned char *buff, unsigned short size)
{
    _i2c.write(m_address, (const char*)buff, size);
}

// ______________________________________________
void PowerElectrobot::readI2C(unsigned char *dest_buff, unsigned short size)
{
    _i2c.read(m_address, (char*)dest_buff, size);
}
