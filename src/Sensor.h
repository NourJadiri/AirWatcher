/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/


//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
#if ! defined ( SENSOR_H)
#define SENSOR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include "Coordinates.h"
using namespace std;

//------------------------------------------------------ Include personnel
#include "Coordinates.h"

//------------------------------------------------------------------------
// Rôle de la classe <Sensor>
//------------------------------------------------------------------------

class Sensor 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


//-----------------------------------------------------------------Getters et Setters

    const string &getId() const;

    void setId(const string &id);

    const Coordinates &getCoord() const;

    void setCoord(const Coordinates &coord);

    bool isReliable() const;

    void setReliable(bool reliable);

//------------------------------------------------- Surchge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
 Sensor ( const Sensor & aSensor );
  // Mode d'emploi (constructeur de copie) :

  Sensor ( );
  // Mode d'emploi (constructeur par défaut):

  Sensor ( string id, const Coordinates& coord);

  Sensor(string id, const Coordinates& coord, bool reliable);
  // Mode d'emploi (Constructeur):
  // Construit un capteur en attribuant à ses paramètres la valeur des paramètres en entrée. 

  virtual ~Sensor ( );
    //Destructeur de la class sensor.

//------------------------------------------------------------------ PRIVE

protected:

    //----------------------------------------------------- Attributs protégés
    string id;
    Coordinates coord = Coordinates(.0, .0);
    bool reliable{};

};


//-------------------------------- Autres définitions dépendantes de <Sensor>

#endif // SENSOR_H
