/*************************************************************************
                           Coordinates  -  longitude + latitude
                             -------------------
    beginning            : 09/05/2023
    copyright            : (C) 2023 by Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Réalisation de la classe <Coordinates> (fichier Coordinates.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cmath>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Coordinates.h"


//----------------------------------------------------- Méthodes publiques

double Coordinates::Distance(const Coordinates& point) const {
    return ( sqrt((point.latitude-this->latitude)*(point.latitude-this->latitude) +
    (point.longitude-this->longitude)*(point.longitude-this->longitude)) );
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
}

//---------------------------------------------------------------- Getters

double Coordinates::getLongitude() const {
    return longitude;
}

double Coordinates::getLatitude() const {
    return latitude;
}

//---------------------------------------------------------------- Setters

void Coordinates::setLongitude(double aLongitude) {
    longitude = aLongitude;
}

void Coordinates::setLatitude(double aLatitude) {
    latitude = aLatitude;
}

