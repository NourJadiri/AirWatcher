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

    return 0;
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



    //------------------------------------------------------------------ PRIVE




