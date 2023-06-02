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
#include <iomanip>
#include <sstream>
#include <cassert>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Test.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Test::testComputeMeanATMOIdx(DataSet* dataSet)
{
    vector<Measure> measures;

    AppService *app = new AppService(*dataSet);

    // empty measure list so should print a message saying that the list is empty
    double atmo = app->computeMeanATMOIdx(measures);
    assert(atmo == 0);
    cout << endl << "** Test 1 for computeMeanATMOIdx() passed **" << endl << endl;

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


    atmo = app->computeMeanATMOIdx(measures);
    cout << "Mean ATMO index is: " << atmo << endl;
    // thus the mean ATMO index is equal to (7+8)/2 = 7.5
    assert(atmo == 7.5);
    cout << endl << "** Test 2 for computeMeanATMOIdx() passed **" << endl << endl;

    delete app;
}

void Test::testGetSensorsAround(DataSet* dataSet)
// on the 10 sensors, only sensors 2 and 3 are within a 150km radius from point(44,1)
{
    AppService *app = new AppService(*dataSet);
    // list of sensors
    unordered_map<string, Sensor> sensors;
    sensors["Sensor0"] = Sensor("Sensor0", Coordinates(44, -1), true);
    sensors["Sensor1"] = Sensor("Sensor1", Coordinates(45, -0.3), true);
    sensors["Sensor2"] = Sensor("Sensor2", Coordinates(44, 0.5), true);
    sensors["Sensor3"] = Sensor("Sensor3", Coordinates(44, 1), true);
    sensors["Sensor4"] = Sensor("Sensor4", Coordinates(49, 1.8), true);
    sensors["Sensor5"] = Sensor("Sensor5", Coordinates(44, -2.5), true);
    sensors["Sensor6"] = Sensor("Sensor6", Coordinates(44, 3.2), true);
    sensors["Sensor7"] = Sensor("Sensor7", Coordinates(41, 3.9), true);
    sensors["Sensor8"] = Sensor("Sensor8", Coordinates(44, -4.6), true);
    sensors["Sensor9"] = Sensor("Sensor9", Coordinates(44, 5.3), true);


    // Call the getSensorsAround method with the made-up list
    Coordinates center(44, 1);
    double radius = 150.0;

    vector<Sensor> sensorsAround = app->getSensorsAround(center, radius, sensors);

    if (sensorsAround.empty()) cout << "No sensors around for the specified area." << endl;
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

    assert(sensorsAround.size() == 2);
    cout << endl << "** Test 1 for getSensorsAround() passed **" << endl << endl;


    // Call the getSensorsAround method with the other made-up list
    sensors.clear();
    sensors["Sensor0"] = Sensor("Sensor0", Coordinates(44, -1), true);
    sensors["Sensor1"] = Sensor("Sensor1", Coordinates(45, -0.3), true);

    sensorsAround = app->getSensorsAround(center, radius, sensors);
    cout << "No matching sensors for the given area." << endl;

    assert(sensorsAround.empty());
    cout << endl << "** Test 2 for getSensorsAround() passed **" << endl << endl;



    // Call the getSensorsAround method with the entire list of sensors
    sensorsAround = app->getSensorsAround(center, radius);

    if(sensorsAround.empty()) cout << "No sensors around for the specified area." << endl;
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

    assert(sensorsAround.size() == 18);
    cout << endl << "** Test 3 for getSensorsAround() passed **" << endl << endl;

    delete app;

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
    struct tm tm = {};
    istringstream ss(dateStr);
    ss >> get_time(&tm, "%Y-%m-%d %H:%M:%S");

    if (!ss.fail())
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

