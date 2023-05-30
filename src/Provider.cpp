
//---------- Réalisation de la classe <Provider> (fichier Provider.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


#include <utility>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Provider.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur

Provider::Provider() = default;

Provider::Provider(string providerIDInput) : providerID(std::move(providerIDInput)) {}

Provider::Provider( const string & providerID, const vector<AirCleaner> & airCleaners )
{
    this->providerID = providerID;
    providedAC = airCleaners;
}

void Provider::printAirCleaners() const {
    for(const auto & aircleaner : providedAC){
        cout << aircleaner.getAirCleanerID() << endl;
    }
}

const string &Provider::getProviderId() const {
    return providerID;
}

void Provider::setProviderId(const string &providerId) {
    providerID = providerId;
}

const vector<AirCleaner> &Provider::getProvidedAc() const {
    return providedAC;
}

void Provider::setProvidedAc(const vector<AirCleaner> &providedAc) {
    providedAC = providedAc;
}
//----- Fin de Provider (constructeur)

Provider::~Provider()= default;
//------- Fin de ~Provider (destructeur)


