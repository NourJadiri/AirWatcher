
//---------- Réalisation de la classe <Coordinates> (fichier Coordinates.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Coordinates.h"


//----------------------------------------------------- Méthodes publiques

double Coordinates::Distance(Coordinates point) {
    return (sqrt((point.latitude-this->latitude)*(point.latitude-this->latitude)+(point.longitude-this->longitude)*(point.longitude-this->longitude)));
}

//-------------------------------------------- Constructeurs - destructeur

Coordinates::Coordinates() {
    longitude=0;
    latitude=0;
}

Coordinates::Coordinates (double longInput, double latInput)
{
    longitude = longInput;
    latitude = latInput;
#ifdef MAP
    cout << "Appel au constructeur de <Coordinates>" << endl;
#endif
} //----- Fin de Coordinates (constructeur par defaut)

Coordinates::Coordinates ( const Coordinates & coord )
{
    longitude = coord.longitude;
    latitude= coord.latitude;

#ifdef MAP
    cout << "Appel au constructeur de copie de <Sensor>" << endl;
#endif
} //----- Fin de Sensor (constructeur de copie)



Coordinates::~Coordinates( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Coordinates>" << endl;
#endif
}//------- Fin de ~Coordinates() (destructeur)

