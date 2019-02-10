/*! \file CEEPROM.cpp
	\brief Classe qui contient les méthoes pour la simulation EEPROM
*/
#include "mbed.h"
#include "RessourcesHardware.h"
#include "CEEPROM.h"



//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CEEPROM::CEEPROM() 
    :m_initialized(false)
{
}

//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CEEPROM::~CEEPROM() 
{
}

//___________________________________________________________________________
 /*!
   \brief Ouvre le fichier EEPROM
*/
void CEEPROM::_init()
{
    if (!m_initialized) {
        m_initialized = m_configFile.read((char*)EEPROM_FILE);
    }
}

//___________________________________________________________________________
 /*!
   \brief Recupere la valeur de la donnee dont le nom (la cle) est passe en argument
   \param key la cle
   \param val la valeur retournee
   \return true si la cle existe / false sinon
*/
bool CEEPROM::getValue(char *key, float *val)
{
  bool ret = false;
   
  _init();  // ouvre le fichier s'il ne l'est pas déjà
  if (m_configFile.getValue(key, &value[0], sizeof(value))) {
	sscanf(value, "%f", val);
	ret= true;  // La donnée existe
  }
  return(ret);
}


//___________________________________________________________________________
 /*!
   \brief Recupere la valeur de la donnee dont le nom (la cle) est passe en argument
   \param key la cle
   \param val la valeur retournee
   \return true si la cle existe / false sinon
*/
bool CEEPROM::getValue(char *key, long *val)
{
   bool ret = false;

   _init();  // ouvre le fichier s'il ne l'est pas déjà
   if (m_configFile.getValue(key, &value[0], sizeof(value))) {
    sscanf(value, "%ld", val);
	ret= true;  // La donnée existe
  }
  return(ret);
}


//___________________________________________________________________________
 /*!
   \brief Recupere la valeur de la donnee dont le nom (la cle) est passe en argument
   \param key la cle
   \param val la valeur retournee
   \return true si la cle existe / false sinon
*/
bool CEEPROM::getValue(char *key, unsigned int *val)
{
  bool ret = false;
  			 
  _init();  // ouvre le fichier s'il ne l'est pas déjà
  if (m_configFile.getValue(key, &value[0], sizeof(value))) {
    sscanf(value, "%d", val);
	ret= true;  // La donnée existe
  }
  return(ret);
}

//___________________________________________________________________________
 /*!
   \brief Recupere la valeur de la donnee dont le nom (la cle) est passe en argument
   \param key la cle
   \param val la valeur retournee
   \return true si la cle existe / false sinon
*/
bool CEEPROM::getValue(char *key, int *val)
{
  bool ret = false;
				 
  _init();  // ouvre le fichier s'il ne l'est pas déjà
  if (m_configFile.getValue(key, &value[0], sizeof(value))) {
	sscanf(value, "%d", val);
	ret= true;  // La donnée existe
  }
  return(ret);
}


//___________________________________________________________________________
 /*!
   \brief Recupere la valeur de la donnee dont le nom (la cle) est passe en argument
   \param key la cle
   \param val la valeur retournee
   \return true si la cle existe / false sinon
*/
bool CEEPROM::getValue(char *key, char *val)
{
  bool ret = false;

  _init();  // ouvre le fichier s'il ne l'est pas déjà
  if (m_configFile.getValue(key, &val[0], sizeof(value))) {
	// pas de recopie, la valeur est rangée directement dans val
	ret= true;  // La donnée existe
  }
  return(ret);
}

bool CEEPROM::setValue(char *key, float val)
{
  bool ret = false;
  char tampon[10];
   sprintf(tampon,"%f",val);
   //todo mettre le flottant dans la chaine de caractere
   
	if (m_configFile.setValue(key, tampon)){
        if (m_configFile.write((char*)EEPROM_FILE))
			ret= true;  // La donnee a ete ecrite
		else
			ret=false;
	}
  
  return(ret);
}
bool CEEPROM::setValue(char *key, short val)
{
  bool ret = false;
  char tampon[10];
   sprintf(tampon,"%hd",val);
   //todo mettre le flottant dans la chaine de caractere
   
	if (m_configFile.setValue(key, tampon)){
        if (m_configFile.write((char*)EEPROM_FILE))
			ret= true;  // La donnee a ete ecrite
		else
			ret=false;
	}
  
  return(ret);
}
bool CEEPROM::setValue(char *key, unsigned short val)
{
  bool ret = false;
  char tampon[10];
   sprintf(tampon,"%hu",val);
   //todo mettre le flottant dans la chaine de caractere
   
	if (m_configFile.setValue(key, tampon)){
        if (m_configFile.write((char*)EEPROM_FILE))
			ret= true;  // La donnee a ete ecrite
		else
			ret=false;
	}
  
  return(ret);
}
//todo: ecriture en eeprom en fin de programme et les fonctions d'ecriture pour les autres types de donnees
 

