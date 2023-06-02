/*************************************************************************
                           InitService  -  populating database
                             -------------------
    beginning            : 09/05/2023
    copyright            : (C) 2023 by Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Réalisation de la classe <InitService> (fichier InitService.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "InitService.h"

//----------------------------------------------------- Méthodes publiques

void InitService::Initialize ( ){
    //data->initSensorList();
    //data->initProviderList();
    //data->initUserList();
    //data->initMeasureList();
    //data->initAirCleanersList();
}

//-------------------------------------------- Constructeurs - destructeur

InitService::InitService ( DataSet & dataInput )
{
    data = &dataInput;
}


InitService::~InitService( )
{
}

InitService::InitService() {

}
