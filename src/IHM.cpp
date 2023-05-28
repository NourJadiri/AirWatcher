/*************************************************************************
                           IHM  -  description
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Réalisation du module <Main> (fichier Main.cpp) ------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "IHM.h"
#include "FileManager.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------ Fonctions privées

static void test ( )
{

} //----- Fin de test

int main()
{
    test();
    cout << "Hello world" << endl;
    FileManager fileManager;
    unordered_map<string, Sensor> sensorsMap = fileManager.ParseSensorList();
    map<User, vector<string>> usersMap = fileManager.ParseUserList();

    // Parcours de la unordered_map
    for (const auto& pair : sensorsMap)
    {
        const string& sensorId = pair.first;
        const Sensor& sensor = pair.second;

        // Affichage des informations du capteur
        cout << "ID: " << sensorId << ", Latitude: " << sensor.getCoord().getLatitude() << ", Longitude: " << sensor.getCoord().getLongitude() << endl;
    }
    // Parcours de la map
    for (const auto& pair : usersMap)
    {
        const User& user = pair.first;
        const vector<string>& sensors = pair.second;

        // Affichage de l'utilisateur
        cout << "User: " << user.getId() << endl;

        // Affichage des capteurs associés à l'utilisateur
        for (const string& sensor : sensors)
        {
            cout << "Sensor: " << sensor << endl;
        }

        cout << endl; // Ligne vide pour séparer les utilisateurs
    }

    vector<Measure> measureList = fileManager.ParseMeasureList();

    //parcours du vector measureList

    for(Measure measure : measureList)
    {
        // Accéder aux attributs de la mesure et effectuer des opérations
        string sensorId = measure.getSensorId();
        time_t dateMeas = measure.getDateMeas();
        string attributeType = measure.getAttributeType();
        double value = measure.getValue();

        // Afficher les valeurs de chaque mesure
        cout << "Sensor ID: " << sensorId << endl;
        cout << "Date: " << ctime(&dateMeas); // Converter date into readable date
        cout << "Attribute Type: " << attributeType << endl;
        cout << "Value: " << value << endl;

    }

    return 0;
}
