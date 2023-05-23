/*************************************************************************
                           FileManager  -  lancement du programme
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Réalisation de la classe <FileManager> (fichier FileManager.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "FileManager.h"
#include "Sensor.h"
#include "Coordinates.h"


//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur

FileManager::FileManager ( )
{

} //----- Fin de FileManager (constructeur par defaut)


FileManager::~FileManager( )
{
}


vector<Measure> FileManager::ParseMeasureList(const string & path) {

}

vector<User> FileManager::ParseUserList(const string & path) {
    return vector<User>();
}

vector<AirCleaner> FileManager::ParseAirCleanerList(const string & path) {
    return vector<AirCleaner>();
}

vector<Provider> FileManager::ParseProviderList(const string & path) {
    return vector<Provider>();
}

vector<Sensor> FileManager::ParseSensorList(const string &path) {
    ifstream is(path);
    vector<Sensor> sensorList;

    return sensorList;

}
//------- Fin de FileManager() (destructeur)

