/*************************************************************************
                           AppService  -  computations
                             -------------------
    beginning            : 09/05/2023
    copyright            : (C) 2023 by Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Réalisation de la classe <AppService> (fichier AppService.cpp) ----------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <map>
using namespace std;

//------------------------------------------------------ Include personnel
#include "AppService.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void AppService::produceStatsPeriod(time_t day1, time_t day2, Coordinates coord, double radius){}

double AppService::produceStatsMoment(time_t day, Coordinates coord, double radius)
{
    vector<Sensor> sensors = getSensorsAround(coord, radius);
    if(sensors.empty()) return -1;

    vector<Measure> measures = getMeasuresAtMoment(sensors, day);
    if(measures.empty()) return -2;

    return computeMeanATMOIdx(measures);
}

double AppService::computeMeanATMOIdx(vector<Measure> listMeasures)
{
    if (listMeasures.empty())
    {
        return 0; // Return 0 if the list of measures is empty
    }

    // Define the breakpoints for each pollutant
    vector<pair<int, int>> OzoneBreakpoints = {{0, 29}, {30, 54}, {55, 79}, {80, 104}, {105, 129}, {130, 149}, {150, 179}, {180, 209}, {210, 239}, {240, INT_MAX}};
    vector<pair<int, int>> SO2Breakpoints = {{0, 39}, {40, 79}, {80, 119}, {120, 159}, {160, 199}, {200, 249}, {250, 299}, {300, 399}, {400, 499}, {500, INT_MAX}};
    vector<pair<int, int>> NO2Breakpoints = {{0, 29}, {30, 54}, {55, 84}, {85, 109}, {110, 134}, {135, 164}, {165, 199}, {200, 274}, {275, 399}, {400, INT_MAX}};
    vector<pair<int, int>> PM10Breakpoints = {{0, 6}, {7, 13}, {14, 20}, {21, 27}, {28, 34}, {35, 41}, {42, 49}, {50, 64}, {65, 79}, {80, INT_MAX}};
    double sumATMOIdx = 0;

    map<string, int> maxATMOSubIdxByDate; // Store the maximum ATMOSubIdx for each day

    for (Measure& measure : listMeasures)
    {
        int ATMOSubIdx = 10;
        string date;
        // Get the attribute type and value of the measure
        string attributeType = measure.getAttributeValue();
        double attributeValue = measure.getValue();

        // Calculate ATMO subindex based on the attribute value
        if (attributeType == "O3")
        {
            ATMOSubIdx = getATMOIdx(attributeValue, OzoneBreakpoints);
        }
        else if (attributeType == "SO2")
        {
            ATMOSubIdx = getATMOIdx(attributeValue, SO2Breakpoints);
        }
        else if (attributeType == "NO2")
        {
            ATMOSubIdx = getATMOIdx(attributeValue, NO2Breakpoints);
        }
        else if (attributeType == "PM10")
        {
            ATMOSubIdx = getATMOIdx(attributeValue, PM10Breakpoints);
        }

        date = measure.getDateMeas();
        if (maxATMOSubIdxByDate.find(date) == maxATMOSubIdxByDate.end())
        {
            // If the date is not present in the map, initialize it with the current ATMOSubIdx
            maxATMOSubIdxByDate[date] = ATMOSubIdx;
        }
        else
        {
            // If the date is already present, update the value with the maximum ATMOSubIdx
            maxATMOSubIdxByDate[date] = max(maxATMOSubIdxByDate[date], ATMOSubIdx);
        }
    }

    // computing the mean of the ATMO indices
    for (const auto& entry : maxATMOSubIdxByDate)
    {
        sumATMOIdx += entry.second; // Add the maximum ATMOSubIdx for each day to the sum
    }
    return sumATMOIdx / maxATMOSubIdxByDate.size(); // Divide by the number of unique days
}

int AppService::getATMOIdx(double value, const vector<pair<int, int>>& breakpoints)
{
    int i=1;
    for (const auto& range : breakpoints)
    {
        if (value >= range.first && value <= range.second)
        {
            return i;
        }
        i++;
    }

    return 10; // Invalid range so worst atmo sub index
}

vector<Sensor> AppService::getSensorsAround(const Coordinates& coord, double radius)
{
    unordered_map<string, Sensor> sensors;
    sensors = data->getSensorsList();
    vector<Sensor> sensorsAround;

    for (const auto& pair : sensors)
    {
        const Sensor& sensor = pair.second; // Access the sensor object from the pair
        double distance = sensor.getCoord().Distance(coord);
        if (sensor.getCoord().Distance(coord) <= radius)
        {
            sensorsAround.push_back(sensor);
        }
    }

    return sensorsAround;
}


vector<Measure> AppService::getMeasuresAtMoment(const vector<Sensor>& listSensor, time_t date)
{
    vector<Measure> measures;
    measures = data->getMeasureList();

    vector<Measure> measuresAtMom;

    for (Measure& measure : measures)
    {
        string sensorId = measure.getSensorId();

        // Vérifier si le sensorId de la mesure appartient à la liste de Sensor
        for (const Sensor& sensor : listSensor)
        {
            if (sensor.getId() == sensorId && measure.getDateMeas() == date)
            {
                measuresAtMom.push_back(measure);
                break;
            }
        }
    }

    return measuresAtMom;
}

pair<int, vector<double>> AppService::obsImpactLvlImprov(const string& AirCleanId, double radius)
{
    unordered_map<string, AirCleaner> airCleanerIds = data->getAirCleanerList();
    AirCleaner airCl;
    bool found = false;

    for (const auto& airCleanerId : airCleanerIds) {
        if (airCleanerId.first == AirCleanId) {
            airCl = airCleanerId.second;
            found = true;
            break; // Exit the loop since the match is found
        }
    }

    if (!found) {
        // No air cleaner found with the given AirCleanId
        return make_pair(-1, vector<double>()); // Return error code -1 and empty vector
    }
    vector<Sensor> listSensors = getSensorsAround(airCl.getCoord(), radius);
    vector<Measure> measBefore = getMeasuresAtMoment(listSensors, airCl.getDateStart());
    vector<Measure> measAfter = getMeasuresAtMoment(listSensors, airCl.getDateStop());

    double meanATMObefore = computeMeanATMOIdx(measBefore);
    double meanATMOafter = computeMeanATMOIdx(measAfter);

    double diffATMO = meanATMOafter - meanATMObefore;

    vector<double> results;
    // Add relevant values to the results vector
    results.push_back(meanATMObefore);
    results.push_back(meanATMOafter);
    results.push_back(diffATMO);

    return make_pair(0, results); // Return success code 0 and the results vector
}

//-------------------------------------------- Constructeurs - destructeur
AppService::AppService(DataSet& dataInput)
{
    data = &dataInput;
}

AppService::AppService() {

}

AppService::~AppService() {

}




