/*************************************************************************
                           AppService  -  description
                             -------------------
    début                : 30/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <AppService> (fichier AppService.h) ----------------

#ifndef APPSERVICE_H
#define APPSERVICE_H


//--------------------------------------------------- Interfaces utilisées

#include <vector>
#include <string>
#include "DataSet.h"
#include "Date.h"
#include "Coordinates.h"
#include "Measure.h"
#include "Sensor.h"
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AppService>
//
//
//
//------------------------------------------------------------------------


class AppService
{
    //----------------------------------------------------------------- PUBLIC

public:

//-------------------------------------------- Constructeurs - destructeur

    AppService(DataSet& data);
    virtual ~AppService( );
    //----------------------------------------------------- Méthodes publiques

    void produceStatsPeriod(Date day1, Date day2, Coordinates coord, double radius);
    void produceStatsMoment(Date day, Coordinates coord, double radius);
    int computeMeanATMOIdx(std::vector<Measure> listMeasures);
    vector<Sensor> getSensorsAround(Coordinates coord, double radius);
    vector<Measure> getMeasuresAtMoment(vector<Sensor> listSensor, Date date);
    void analysePIndSensor(string sensorId);
    void analysePIndSensor();


    //------------------------------------------------------------------ PRIVE
private:
    DataSet& data;
};

#endif // APPSERVICE_H
