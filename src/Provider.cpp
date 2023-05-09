
//---------- Réalisation de la classe <Provider> (fichier Provider.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Provider.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

vector<AirCleaner> & Provider::getProvidedAC(){
    return this->providedAC;
}

void Provider::setProvidedAC(vector<AirCleaner> provAC){
    this->providedAC = provAC;
}

//-------------------------------------------- Constructeurs - destructeur

Provider::Provider(vector<AirCleaner> airCleaners)
{
    providedAC = airCleaners;
}//----- Fin de Provider (constructeur)

Provider::~Provider()
{
} //------- Fin de ~Provider (destructeur)


