/*************************************************************************
                           AppService  -  computations
                             -------------------
    beginning            : 09/05/2023
    copyright            : (C) 2023 by Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <AppService> (fichier AppService.h) ----------------
#if ! defined ( APPSERVICE_H )
#define APPSERVICE_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
#include <utility>

#include "domain/DataSet.h"
#include "domain/Coordinates.h"
#include "domain/Measure.h"
#include "domain/Sensor.h"

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

    //----------------------------------------------------- Méthodes publiques

    double produceStatsMoment(time_t day, Coordinates coord, double radius);

    double computeMeanATMOIdx(std::vector<Measure> listMeasures);

    unordered_map<string,Sensor> getSensorsAround(const Coordinates& coord, double radius, const unordered_map<string, Sensor>& sensorMap = {} );

    vector<Measure> getMeasuresAtMoment(unordered_map<string, Sensor> & listSensor, time_t date);

    int getATMOIdx(double value, const vector<pair<int, int>>& breakpoints);

    pair<int, vector<double>> obsImpactLvlImprov(const std::string& id, double radius);

    //-------------------------------------------- Constructeurs - destructeur

    explicit AppService(DataSet& data);

    explicit AppService();

    virtual ~AppService( );


    //------------------------------------------------------------------ PRIVE

private:

    DataSet * data{};
};

#endif // APPSERVICE_H
