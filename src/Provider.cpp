
//---------- Réalisation de la classe <Provider> (fichier Provider.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


#include <utility>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Provider.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

vector<AirCleaner> & Provider::getProvidedAC(){
    return this->providedAC;
}

void Provider::setProvidedAC(vector<AirCleaner> provAC){
    this->providedAC = std::move(provAC);
}

string & Provider :: getProviderID()
{
    return this->providerID;
}

//-------------------------------------------- Constructeurs - destructeur

Provider::Provider() {}
Provider::Provider(string providerIDInput) : providerID(std::move(providerIDInput)) {}
Provider::Provider(string providerIDInput, vector<AirCleaner> airCleaners)
{
    providedAC = std::move(airCleaners);
    providerID = std::move(providerIDInput);
}//----- Fin de Provider (constructeur)

Provider::~Provider()
{
} //------- Fin de ~Provider (destructeur)


