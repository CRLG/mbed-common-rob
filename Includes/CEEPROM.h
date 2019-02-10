/*! \file CEEPROM.h
	\brief Classe qui contient la gestion des roues motrices gauche et droite
*/

#ifndef _EEPROM_H_
#define _EEPROM_H_

#include "ConfigFile.h"

// -----------------------------
//! Classe de gestion des options d'exécution passees en ligne de commande
class CEEPROM {
public :
	CEEPROM();
	~CEEPROM();

	//! Lit le fichier
        virtual void Read(void) { } // L'applicatif peut hériter de la classe et ré-implémenter la méthode Read pour réaliser toutes la lecture EEPROM d'un seul coup dans cette méthode.
	//! Ecrit une donnee de type float dont le nom (la cle) est passee en parametre
	bool setValue(char *key, float val);
	//! Ecrit une donnee de type short dont le nom (la cle) est passee en parametre
	bool setValue(char *key, short val);
	//! Ecrit une donnee de type unsigned short dont le nom (la cle) est passee en parametre
	bool setValue(char *key, unsigned short val);
	
	//! Lit une donnée de type flottant dont le nom (la cle) est passee en parametre
	bool getValue(char *key, float *val);
	//! Lit une donnée de type long dont le nom (la cle) est passee en parametre
	bool getValue(char *key, long *val);
	//! Lit une donnée de type uint dont le nom (la cle) est passee en parametre
	bool getValue(char *key, unsigned int *val);
	//! Lit une donnée de type uint dont le nom (la cle) est passee en parametre
	bool getValue(char *key, int *val);
	//! Lit une donnée de type string dont le nom (la cle) est passee en parametre
	bool getValue(char *key, char *val);

private : 
        const char *EEPROM_FILE="/local/eeprom.ini";

        //! Buffer de recuperation d'une valeur
        char value[BUFSIZ];

        //! Point d'entree pour la gestion
        ConfigFile m_configFile;

        bool m_initialized;

        void _init();
};


#endif


