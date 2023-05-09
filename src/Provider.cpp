
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

Vector<AirCleaner> & Provider::getProvidedAC(){
    return this->providedAC;
}

void Provider::setProvidedAC(Vector<AirCleaner> provAC){
    this->providedAC = provAC;
}

//-------------------------------------------- Constructeurs - destructeur
Provider::Provider ( )
{
#ifdef MAP
    cout << "Appel au constructeur par defaut de <Provider>" << endl;
#endif
} //----- Fin de Provider (constructeur par defaut)


Provider::Provider(String id, Vector<AirCleaner> airCleaners)
{
#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif
    this->id = id;
    providedAC = airCleaners;
}//----- Fin de Provider (constructeur)

Sensor :: ~Provider()
{
#ifdef MAP
    cout << "Appel au destructeur de <Provider>" << endl;
#endif
} //------- Fin de ~Provider (destructeur)


