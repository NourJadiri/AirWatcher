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

#include "DataSet.h"
#include "Coordinates.h"
#include "Measure.h"
#include "Sensor.h"

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

    explicit AppService(DataSet& data);
    explicit AppService();
    virtual ~AppService( );

    //----------------------------------------------------- Méthodes publiques

    void produceStatsPeriod(time_t day1, time_t day2, Coordinates coord, double radius);

    double produceStatsMoment(time_t day, Coordinates coord, double radius);

    double computeMeanATMOIdx(std::vector<Measure> listMeasures);

    vector<Sensor> getSensorsAround(const Coordinates& coord, double radius);

    vector<Measure> getMeasuresAtMoment(const vector<Sensor>& listSensor, time_t date);

    int getATMOIdx(double value, const vector<pair<int, int>>& breakpoints);

    pair<int, vector<double>> obsImpactLvlImprov(const std::string& id, double radius);


    //------------------------------------------------------------------ PRIVE

private:

    DataSet * data;
};

#endif // APPSERVICE_H
