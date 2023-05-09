
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

Coordinates::Coordinates (double longInput, double latInput)
{
    longitude = longInput;
    latitude = latInput;
#ifdef MAP
    cout << "Appel au constructeur de <Coordinates>" << endl;
#endif
} //----- Fin de Coordinates (constructeur par defaut)


Coordinates::~Coordinates( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Coordinates>" << endl;
#endif
}//------- Fin de ~Coordinates() (destructeur)

