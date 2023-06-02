/*************************************************************************
                           Test  -  class for tests
                             -------------------
    beginning            : 09/05/2023
    copyright            : (C) 2023 by Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Réalisation du module <Test> (fichier Test.cpp) ------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Test.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Test::testComputeMeanATMOIdx(DataSet* dataSet)
{
    vector<Measure> measures;

    string dateTimeString = "2019-01-01 12:00:00";
    time_t time = convertToTimeT(dateTimeString);

    //cout << "Converted time_t value: " << time << endl;

    Measure measure1("Sensor0", time, "O3", 50.25);
    Measure measure2("Sensor0", time, "NO2", 74.5);
    Measure measure3("Sensor0", time, "SO2", 41.5);
    Measure measure4("Sensor0", time, "PM10",44.75);
    // this gives an atmo index = 7

    dateTimeString = "2019-01-02 12:00:00";
    time = convertToTimeT(dateTimeString);

    Measure measure5("Sensor0", time, "O3", 180.25);
    Measure measure6("Sensor0", time, "NO2", 4.5);
    Measure measure7("Sensor0", time, "SO2", 151.5);
    Measure measure8("Sensor0", time, "PM10",44.75);
    // this gives an atmo index = 8

    measures.push_back(measure1);
    measures.push_back(measure2);
    measures.push_back(measure3);
    measures.push_back(measure4);

    measures.push_back(measure5);
    measures.push_back(measure6);
    measures.push_back(measure7);
    measures.push_back(measure8);


    AppService *app = new AppService(*dataSet);
    double atmo = app->computeMeanATMOIdx(measures);
    cout << "Mean ATMO index is: " << atmo << endl;
    // thus the mean ATMO index is equal to (7+8)/2 = 7.5
    assert(atmo == 7.5);
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

    string dateTimeString = "2019-01-01 12:00:00";
    time_t time = convertToTimeT(dateTimeString);

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

time_t Test::convertToTimeT(const string& dateStr)
{
    struct tm tm;
    memset(&tm, 0, sizeof(struct tm));

    if (strptime(dateStr.c_str(), "%Y-%m-%d %H:%M:%S", &tm) != nullptr)
    {
        time_t time = mktime(&tm);
        return time;
    }

    return 0; // Return 0 if the conversion fails
}

//-------------------------------------------- Constructeurs - destructeur
Test::Test ( )
{
}

Test::~Test ( )
{
}

