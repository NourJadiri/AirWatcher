
//---------- Réalisation de la classe <PrivIndiv> (fichier PrivIndiv.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "PrivIndiv.h"

#include <utility>

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

vector<Sensor> & PrivIndiv::getProvidedSensors(){
    return this->providedSensors;
}

void PrivIndiv::setProvidedSensors(vector<Sensor> provSens){
    this->providedSensors = std::move(provSens);
}

int & PrivIndiv::getPoints(){
    return this->points;
}

void PrivIndiv::setPoints(int aPoint){
    this->points = aPoint;
}

//-------------------------------------------- Constructeurs - destructeur
PrivIndiv::PrivIndiv ( vector<Sensor> provSens )
{
    this->providedSensors = std::move(provSens);
} //----- Fin de PrivIndiv (constructeur par defaut)


PrivIndiv::~PrivIndiv( )
{
}//------- Fin de ~PrivIndiv() (destructeur)

