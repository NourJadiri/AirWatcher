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
#include <unordered_map>
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

unordered_map<string, Sensor> FileManager::ParseSensorList()
{
    string filePath = "../src/data/sensors.csv";
    ifstream file(filePath);

    if (!file.is_open())
    {
        cout << "Erreur lors de l'ouverture du fichier " << filePath << endl;
        return unordered_map<string, Sensor>(); // Retourne une map vide en cas d'erreur
    }

    unordered_map<string, Sensor> sensors;

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string sensorId;
        double latitude, longitude;

        if (getline(ss, sensorId, ';') &&
            ss >> latitude &&
            ss.ignore() &&
            ss >> longitude)
        {
            Coordinates coord(latitude, longitude);
            Sensor sensor(sensorId, coord, true);
            sensors[sensorId] = sensor;
        }
        else
        {
            cout << "Erreur de format dans le fichier CSV" << endl;
        }
    }

    file.close();

    return sensors;
}

//------- Fin de FileManager() (destructeur)

