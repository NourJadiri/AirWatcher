
//---------- Réalisation de la classe <StatsService> (fichier StatsService.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "StatsService.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
StatsService::StatsService ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <StatsService>" << endl;
#endif
} //----- Fin de StatsService

StatsService::~StatsService ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <StatsService>" << endl;
#endif
} //----- Fin de StatsService

