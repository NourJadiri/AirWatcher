
//---------- Réalisation de la classe <Coordinates> (fichier Coordinates.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cmath>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Coordinates.h"


//----------------------------------------------------- Méthodes publiques

double Coordinates::Distance(const Coordinates& point) {
    return (sqrt((point.latitude-this->latitude)*(point.latitude-this->latitude)+(point.longitude-this->longitude)*(point.longitude-this->longitude)));
}

//-------------------------------------------- Constructeurs - destructeur

Coordinates::Coordinates() {
    longitude = .0;
    latitude = .0;
}

Coordinates::Coordinates (double longInput, double latInput)
{
    longitude = longInput;
    latitude = latInput;
} //----- Fin de Coordinates (constructeur par defaut)

Coordinates::Coordinates ( const Coordinates & coord )
{
    longitude = coord.longitude;
    latitude= coord.latitude;
} //----- Fin de Sensor (constructeur de copie)

Coordinates::~Coordinates( )
{
}//------- Fin de ~Coordinates() (destructeur)

