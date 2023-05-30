/*************************************************************************
                           DataSet  -  description
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <DataSet> (fichier DataSet.h) ----------------
#if ! defined ( DATASET_H )
#define DATASET_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include <vector>
#include <unordered_map>
#include "Sensor.h"
#include "Measure.h"
#include "AirCleaner.h"
#include "User.h"
#include "Provider.h"
#include "FileManager.h"
#include "PrivIndiv.h"

using namespace std;


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DataSet>
//
//
//
//------------------------------------------------------------------------

class DataSet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur

    DataSet ( );

    virtual ~DataSet ( );

//------------------------------------------------------------------ PRIVE
private:
    FileManager fileManager;

public:


    void initSensorList();

    void initUserList();

    void initProviderList();

    void initMeasureList();

    void initAirCleanerList();

private:
public:
    const unordered_map<string, Sensor> &getSensorsList() const;

    void setSensorsList(const unordered_map<string, Sensor> &sensorsList);

    const unordered_map<string, PrivIndiv> &getUserList() const;

    void setUserList(const unordered_map<string, PrivIndiv> &userList);

    const unordered_map<string, Provider> &getProviderList() const;

    void setProviderList(const unordered_map<string, Provider> &providerList);

    const vector<Measure> &getMeasureList() const;

    void setMeasureList(const vector<Measure> &measureList);

    const vector<AirCleaner> &getAirCleanerList() const;

    void setAirCleanerList(const vector<AirCleaner> &airCleanerList);

private:
    unordered_map<string,Sensor> sensorsList;
    unordered_map<string, PrivIndiv> userList;
    unordered_map<string,Provider> providerList;

    vector<Measure> measureList;
    vector<AirCleaner> airCleanerList;
};

//-------------------------------- Autres définitions dépendantes de <DataSet>

#endif // DATASET_H