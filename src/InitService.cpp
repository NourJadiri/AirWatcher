/*************************************************************************
                           InitService  -  lancement du programme
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Réalisation de la classe <InitService> (fichier InitService.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "InitService.h"
#include "Sensor.h"
#include "Coordinates.h"


//----------------------------------------------------- Méthodes publiques

void InitService::InitSensors()
{
    // Chemin vers le fichier CSV contenant les données des capteurs
    std::string filePath = "../src/data/sensors.csv";

    // Ouverture du fichier CSV en lecture
    std::ifstream file(filePath);

    if (!file.is_open())
    {
        std::cout << "Erreur lors de l'ouverture du fichier " << filePath << std::endl;
        return;
    }

    // Map pour stocker les capteurs avec leur ID comme clé
    std::map<std::string, Sensor> sensors;

    // Lecture ligne par ligne du fichier CSV
    std::string line;
    while (std::getline(file, line))
    {
        // Utilisation d'un stringstream pour extraire les valeurs de chaque ligne
        std::stringstream ss(line);
        std::string sensorId;
        double latitude, longitude;

        // Extraction des valeurs séparées par des ;
        if (std::getline(ss, sensorId, ';') &&
            ss >> latitude &&
            ss.ignore() &&
            ss >> longitude)
        {
            // Création d'une instance de la classe Coordinates pour les coordonnées du capteur
            Coordinates coord(latitude, longitude);

            // Création d'une instance de la classe Sensor avec les valeurs extraites
            Sensor sensor(sensorId, coord, true); // Ici, on suppose que tous les capteurs sont initialement fiables

            // Ajout du capteur à la map avec son ID comme clé
            sensors[sensorId] = sensor;
        }
        else
        {
            std::cout << "Erreur de format dans le fichier CSV" << std::endl;
        }
    }

    // Fermeture du fichier
    file.close();

    // Affichage des capteurs
    for (const auto& pair : sensors)
    {
        const Sensor& sensor = pair.second;
        std::cout << "ID: " << sensor.getId() << ", Latitude: " << sensor.getCoord().getLatitude() << ", Longitude: " << sensor.getCoord().getLongitude() << std::endl;
    }
}

//-------------------------------------------- Constructeurs - destructeur

InitService::InitService ( )
{
} //----- Fin de InitService (constructeur par defaut)


InitService::~InitService( )
{
}//------- Fin de ~InitService() (destructeur)

