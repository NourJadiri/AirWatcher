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
void AppService::produceStatsPeriod(Date day1, Date day2, Coordinates coord, double radius){}

void AppService::produceStatsMoment(time_t day, Coordinates coord, double radius)
{
    vector<Sensor> sensors = data.getSensorsAround(coord, radius);
}

int AppService::computeMeanATMOIdx(vector<Measure> listMeasures)
{
    // TODO: Implémenter la méthode computeMeanATMOIdx
    return 0;
}

vector<Sensor> AppService::getSensorsAround(Coordinates coord, double radius)
{
    vector<Sensor> sensors = data.getSensorsList();
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
    vector<Measure> measures = data.getMeasureList();
    vector<Measure> measuresAtMom;
    for (const Measure& measure : measures)
    {
        if(measure->getDateMeas() == date)
            measuresAtMom.push_back(measure);
    }
    return measures;
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




