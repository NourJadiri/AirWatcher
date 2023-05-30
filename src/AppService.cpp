/*************************************************************************
                           AppService  -  lancement du programme
                             -------------------
    début                : 30/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Réalisation de la classe <AppService> (fichier AppService.cpp) ----------------


//--------------------------------------------------- Includes

#include "AppService.h"
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AppService>
//
//
//
//------------------------------------------------------------------------



    //----------------------------------------------------------------- PUBLIC


//-------------------------------------------- Constructeurs - destructeur
AppService::AppService(DataSet& dataInput)
{
    data = &dataInput;
}


    //----------------------------------------------------- Méthodes publiques
void AppService::produceStatsPeriod(time_t day1, time_t day2, Coordinates coord, double radius){}

double AppService::produceStatsMoment(time_t day, Coordinates coord, double radius)
{
    //vector<Sensor> sensors = data.getSensorsAround(coord, radius);
    return 0;
}


int AppService::computeMeanATMOIdx(vector<Measure> listMeasures)
{
    if (listMeasures.empty())
    {
        return 0; // Return 0 if the list of measures is empty
    }
    // Define the breakpoints for each pollutant
    vector<pair<int, int>> OzoneBreakpoints = {{0, 50}, {50, 100}, {100, 130}, {130, 240}, {240, 380}, {380, INT_MAX}};
    vector<pair<int, int>> SO2Breakpoints = {{0, 100}, {100, 200}, {200, 350}, {350, 500}, {500, 750}, {750, INT_MAX}};
    vector<pair<int, int>> NO2Breakpoints = {{0, 40}, {40, 90}, {90, 120}, {120, 230}, {230, 340}, {340, INT_MAX}};
    vector<pair<int, int>> PM10Breakpoints = {{0, 20}, {20, 40}, {40, 50}, {50, 100}, {100, 150}, {150, INT_MAX}};
    vector<pair<int, int>> PM25Breakpoints = {{0, 10}, {10, 20}, {20, 25}, {25, 50}, {50, 75}, {75, INT_MAX}};

    int sumATMOIdx = 0;
    for (Measure& measure : listMeasures)
    {
        int ATMOIdx = 0;

        // Get the attribute type and value of the measure
        string attributeType = measure.getAttributeValue();
        double attributeValue = measure.getValue();

        // Calculate ATMO index based on the attribute value
        if (attributeType == "O3")
        {
            ATMOIdx = getATMOIdx(attributeValue, OzoneBreakpoints);
        }
        else if (attributeType == "SO2")
        {
            ATMOIdx = getATMOIdx(attributeValue, SO2Breakpoints);
        }
        else if (attributeType == "NO2")
        {
            ATMOIdx = getATMOIdx(attributeValue, NO2Breakpoints);
        }
        else if (attributeType == "PM10")
        {
            ATMOIdx = getATMOIdx(attributeValue, PM10Breakpoints);
        }
        else if (attributeType == "PM2.5")
        {
            ATMOIdx = getATMOIdx(attributeValue, PM25Breakpoints);
        }
        else
        {
            ATMOIdx = 6; // Extrêmement mauvais
        }

        sumATMOIdx += ATMOIdx;
    }

    int meanATMOIdx = sumATMOIdx / listMeasures.size();
    return meanATMOIdx;
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

    return i; // Invalid range
}

vector<Sensor> AppService::getSensorsAround(Coordinates coord, double radius)
{
    vector<Sensor> sensors;
    //sensors = data.getSensorsList();
    vector<Sensor> sensorsAround;

    for (const Sensor& sensor : sensors)
    {
        if (sensor.getCoord().Distance(coord) <= radius)
        {
            sensorsAround.push_back(sensor);
        }
    }

    return sensorsAround;
}


vector<Measure> AppService::getMeasuresAtMoment(vector<Sensor> listSensor, time_t date)
{
    vector<Measure> measures;
    //measures = data->getMeasureList();
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


void AppService::analysePIndSensor(string sensorId)
{
    // TODO: Implémenter la méthode analysePIndSensor (avec sensorId en paramètre)
}

void AppService::analysePIndSensor()
{
    // TODO: Implémenter la méthode analysePIndSensor (sans paramètre)
}

AppService::~AppService() {

}



//------------------------------------------------------------------ PRIVE




