
//---------- Réalisation de la classe <PrivIndiv> (fichier PrivIndiv.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "PrivIndiv.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

vector<Sensor> & PrivIndiv::getProvidedSensors(){
    return this->providedSensors;
}

void PrivIndiv::setProvidedSensors(vector<Sensor> provSens){
    this->providedSensors = provSens;
}

int & PrivIndiv::getPoints(){
    return this->points;
}

void PrivIndiv::setPoints(int aPoint){
    this->points = aPoint;
}



//-------------------------------------------- Constructeurs - destructeur
PrivIndiv::PrivIndiv ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <PrivIndiv>" << endl;
#endif
} //----- Fin de PrivIndiv (constructeur par defaut)


PrivIndiv::~PrivIndiv( )
{
#ifdef MAP
    cout << "Appel au destructeur de <PrivIndiv>" << endl;
#endif
}//------- Fin de ~PrivIndiv() (destructeur)

