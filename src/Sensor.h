/*************************************************************************
                           Sensor  -  object of a sensor
                             -------------------
    beginning            : 09/05/2023
    copyright            : (C) 2023 by Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
#if ! defined ( SENSOR_H)
#define SENSOR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>

//------------------------------------------------------ Include personnel
#include "Coordinates.h"
using namespace std;
//------------------------------------------------------------------------
// Rôle de la classe <Sensor>
//
//
//------------------------------------------------------------------------

class Sensor 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    const string &getId() const;

    const Coordinates &getCoord() const;

    bool isReliable() const;

    void setCoord(const Coordinates &coord);

    void setId(const string &id);

    void setReliable(bool reliable);

//-------------------------------------------- Constructeurs - destructeur
  Sensor ( const Sensor & aSensor );

  Sensor ( );

  Sensor (string id, const Coordinates& coord);

  Sensor(string id, const Coordinates& coord, bool reliable);

  virtual ~Sensor ( );

//------------------------------------------------------------------ PRIVE

protected:

    //----------------------------------------------------- Attributs protégés
    string id;

    Coordinates coord = Coordinates(.0, .0);

    bool reliable{};

};

#endif // SENSOR_H
