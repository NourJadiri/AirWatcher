/*************************************************************************
                           Test  -  Classe de tests
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Réalisation du module <Test> (fichier Test.cpp) ------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <regex>
using namespace std;

//------------------------------------------------------ Include personnel
#include "FileManager.h"
#include "DataSet.h"
#include "AppService.h"
#include "Test.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
void Test::testComputeMeanATMOIdx(DataSet* dataSet)
{
    vector<Measure> measures;

    tm timeStruct = {};
    string dateTimeString = "2019-01-01 12:00:00";

    // Extraction des composantes de la date/heure
    sscanf(dateTimeString.c_str(), "%d-%d-%d %d:%d:%d",
           &timeStruct.tm_year, &timeStruct.tm_mon, &timeStruct.tm_mday,
           &timeStruct.tm_hour, &timeStruct.tm_min, &timeStruct.tm_sec);

    // Ajustement des valeurs de la structure tm
    timeStruct.tm_year -= 1900; // Année depuis 1900
    timeStruct.tm_mon -= 1;     // Mois de 0 à 11

    // Conversion en time_t
    time_t time = mktime(&timeStruct);

    cout << "Converted time_t value: " << time << endl;

    Measure measure1("Sensor0", time, "O3", 50.25);
    Measure measure2("Sensor0", time, "NO2", 74.5);
    Measure measure3("Sensor0", time, "SO2", 41.5);
    Measure measure4("Sensor0", time, "PM10",44.75);

    measures.push_back(measure1);
    measures.push_back(measure2);
    measures.push_back(measure3);
    measures.push_back(measure4);

    AppService *app = new AppService(*dataSet);
    int atmo = app->computeMeanATMOIdx(measures);
    cout << "La moyenne ATMO vaut : " << atmo << endl;
    delete app;


}

void Test::testGetSensorsAround(DataSet* dataSet)
{
    AppService appService;

    // Call the getSensorsAround method
    Coordinates center(30, 40);
    double radius = 30.0;
    vector<Sensor> sensorsAround = appService.getSensorsAround(center, radius);
    if(sensorsAround.empty()) cout << "No sensors around for the specified area."<<endl;
    else
    {
        // Print the sensors found within the radius
        cout << "Sensors within the radius:" << endl;
        for (const Sensor& sensor : sensorsAround)
        {
            cout << "Sensor ID: " << sensor.getId() << endl;
            cout << "Sensor Coordinates: (" << sensor.getCoord().getLongitude() << ", " << sensor.getCoord().getLatitude() << ")" << endl;
        }
    }
}

void Test::testMeasureAtMoment(DataSet* dataSet)
{
    AppService appService;

    vector<Sensor> sensors;
    sensors.push_back(Sensor((string)"Sensor0", Coordinates(10, 20)));
    sensors.push_back(Sensor((string)"Sensor2", Coordinates(15, 25)));
    sensors.push_back(Sensor((string)"Sensor3", Coordinates(30, 40)));
    sensors.push_back(Sensor((string)"Sensor4", Coordinates(35, 45)));

    tm timeStruct = {};
    string dateTimeString = "2019-01-01 12:00:00";

    // Extraction des composantes de la date/heure
    sscanf(dateTimeString.c_str(), "%d-%d-%d %d:%d:%d",
           &timeStruct.tm_year, &timeStruct.tm_mon, &timeStruct.tm_mday,
           &timeStruct.tm_hour, &timeStruct.tm_min, &timeStruct.tm_sec);

    // Ajustement des valeurs de la structure tm
    timeStruct.tm_year -= 1900; // Année depuis 1900
    timeStruct.tm_mon -= 1;     // Mois de 0 à 11

    // Conversion en time_t
    time_t time = mktime(&timeStruct);

    vector<Measure> meas = appService.getMeasuresAtMoment(sensors, time);

    if(meas.empty()) cout << "No measure found for the specified date."<<endl;
    else
    {
        // Print the sensors found within the radius
        cout << "measures :" << endl;
        for (Measure& measure : meas)
        {
            cout << "Sensor ID: " << measure.getSensorId() << endl;
            cout << "measure : " << measure.getDateMeas() << ", " << measure.getAttributeValue() << ";" << measure.getValue()<< endl;
        }
    }


}
//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
Test::Test ( )
{
} //----- Fin de Test

Test::~Test ( )
{
} //----- Fin de ~Test

