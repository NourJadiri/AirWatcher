
//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Sensor.h"

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
Sensor::Sensor ( const Sensor & aSensor )
{
  id = aSensor.id;
  coord = aSensor.coord;
  reliable= aSensor.reliable;
} //----- Fin de Sensor (constructeur de copie)

Sensor::Sensor()
{

}

const string &Sensor::getId() const {
    return id;
}

void Sensor::setId(const string &id) {
    Sensor::id = id;
}

const Coordinates &Sensor::getCoord() const {
    return coord;
}

void Sensor::setCoord(const Coordinates &coord) {
    Sensor::coord = coord;
}

bool Sensor::isReliable() const {
    return reliable;
}

void Sensor::setReliable(bool reliable) {
    Sensor::reliable = reliable;
}

Sensor::Sensor( string idInput, const Coordinates& coordInput) : id(idInput), coord(coordInput), reliable(true){}
//Constructeur qui set relaible a true


Sensor::Sensor(string aId, const Coordinates& someCoord, bool reliable)
{
  this->id = aId;
  coord = someCoord;
  this->reliable = reliable;
}//----- Fin de Sensor(constructeur)

Sensor :: ~Sensor()
{
  
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;
#endif
} //------- Fin de ~Sensor (destructeur)


