/*! \file CLed.cpp
	\brief Classe qui contient toute l'application
*/
#include "CLed.h"

//___________________________________________________________________________
CLed::CLed(DigitalOut *led)
{
    m_led = led;
    m_mode = LEDMODE_MANUAL;
}

//___________________________________________________________________________
bool CLed::_read()
{
    return m_led->read();
}

//___________________________________________________________________________
void CLed::_write(bool val)
{
    return m_led->write(val);
}
