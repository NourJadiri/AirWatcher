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
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

//------------------------------------------------------ Include personnel

#include "FileManager.h"
#include "Sensor.h"
#include "Coordinates.h"
#include "User.h"
#include "Measure.h" // Inclure le fichier d'en-tête de la classe Measure


//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur

FileManager::FileManager ( )
{

} //----- Fin de FileManager (constructeur par defaut)


FileManager::~FileManager( )
{
}


unordered_map<string, Sensor> FileManager::ParseSensorList()
{
    string filePath = "../src/data/sensors.csv";
    ifstream file(filePath);

    if (!file.is_open())
    {
        cout << "Erreur lors de l'ouverture du fichier " << filePath << endl;
        return unordered_map<string, Sensor>();
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

vector<Measure> FileManager::ParseMeasureList()
{
    vector<Measure> measureList;
    string filePath = "../src/data/measurements.csv";
    ifstream file(filePath);

    if (!file)
    {
        cout << "Erreur lors de l'ouverture du fichier." << endl;
        return measureList; // Retourner une liste vide si le fichier ne peut pas être ouvert
    }
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string cell;

        string dateStr;
        string sensorId;
        string attributeType;
        string valueStr;

        // Utilisation de getline avec le délimiteur ';' pour extraire les valeurs de chaque cellule
        if (getline(ss, dateStr, ';') && getline(ss, sensorId, ';') &&
            getline(ss, attributeType, ';') && getline(ss, valueStr, ';'))
        {
            // Conversion des valeurs au format approprié
            time_t dateMeas = stoi(dateStr); // Conversion de la chaîne de caractères en un entier (date en secondes depuis l'époque)
            double value = stod(valueStr); // Conversion de la chaîne de caractères en un double

            // Création de l'objet Measure et ajout à la liste
            Measure measure(sensorId, dateMeas, attributeType, value);
            measureList.push_back(measure);
        }
        else
        {
            cout << "Erreur lors de la lecture d'une ligne du fichier." << endl;
        }
    }

    file.close();

    return measureList;
}


map<User, vector<string>> FileManager::ParseUserList()
{
    string filePath = "../src/data/users.csv";
    ifstream file(filePath);

    if (!file.is_open())
    {
        cout << "Erreur lors de l'ouverture du fichier " << filePath << endl;
        return map<User, vector<string>>();
    }
    map<User, vector<string>> userList;

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string cell;

        string userId;
        string sensor;

        while (getline(ss, cell, ';'))
        {
            if (userId.empty())
            {
                userId = cell;
            }
            else
            {
                sensor = cell;
            }
        }

        if (!userId.empty())
        {
            User tempUser(userId); // Crée un objet User temporaire
            userList[tempUser].push_back(sensor); // Ajoute l'objet temporaire à la map
        }
    }

    file.close();

    return userList;

}

vector<AirCleaner> FileManager::ParseAirCleanerList(const string &path)
{
    // Implementer le code pour la lecture du fichier des purificateurs d'air
    vector<AirCleaner> airCleaners;
    return airCleaners;
}

vector<Provider> FileManager::ParseProviderList(const string &path)
{
    // Implementer le code pour la lecture du fichier des fournisseurs de services
    vector<Provider> providers;
    return providers;
}

//------- Fin de FileManager() (destructeur)

