/*************************************************************************
                           IHM  -  lancement du programme
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Réalisation de la classe <InitService> (fichier InitService.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "InitService.h"


//----------------------------------------------------- Méthodes publiques

void InitSensors()
{

}

//-------------------------------------------- Constructeurs - destructeur

InitService::InitService ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <InitService>" << endl;
#endif
} //----- Fin de InitService (constructeur par defaut)


InitService::~InitService( )
{
#ifdef MAP
    cout << "Appel au destructeur de <InitService>" << endl;
#endif
}//------- Fin de ~InitService() (destructeur)

