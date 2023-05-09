
//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Sensor.h"

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
Sensor::Sensor ( const Sensor & aSensor )
{
  id = aSensor.id;
  coordinates= aSensor.coord;
  reliable= aSensor.reliable;

#ifdef MAP
    cout << "Appel au constructeur de copie de <Sensor>" << endl;
#endif
} //----- Fin de Sensor (constructeur de copie)


Sensor::Sensor ( )
{
#ifdef MAP
    cout << "Appel au constructeur par defaut de <Sensor>" << endl;
#endif
} //----- Fin de Sensor(constructeur par defaut)


Sensor::Sensor(string id, Coordinates coord, bool reliable)
{
  this->id = id;
  coordinates = coord;
  reliable = reliable;

#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif
}//----- Fin de Sensor(constructeur)

Sensor :: ~Sensor()
{
  
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;
#endif
} //------- Fin de ~Sensor (destructeur)


