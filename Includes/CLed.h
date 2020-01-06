/*! \file CLeds.h
	\brief Classe qui contient la gestion des LED
*/

#ifndef _LED_H_
#define _LED_H_

#include "CLedBase.h"
#include "RessourcesHardware.h"

// ============================================================
//        Gestion d'une LED
// ============================================================
//! Classe de gestion d'une LED
class CLed : public CLedBase
{
 public :
    CLed(DigitalOut *led);

private :
    DigitalOut *m_led;

protected :
    virtual void _write(bool val);
    virtual bool _read();
};
#endif


