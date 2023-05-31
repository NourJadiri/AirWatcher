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

    /// Getters and setters
public:
    const unordered_map<string, Sensor> &getSensorsList() const;

    const unordered_map<string, AirCleaner> &getAirCleanerList() const;

    void setSensorsList(const unordered_map<string, Sensor> &list);

    const unordered_map<string, PrivIndiv> &getUserList() const;

    void setUserList(const unordered_map<string, PrivIndiv> &list);

    const unordered_map<string, Provider> &getProviderList() const;

    void setProviderList(const unordered_map<string, Provider> &list);

    const vector<Measure> &getMeasureList() const;

    void setMeasureList(const vector<Measure> &list);

    const FileManager &getFileManager() const;

    void setFileManager(const FileManager &manager);

private:
    unordered_map<string,Sensor> sensorsList;
    unordered_map<string, PrivIndiv> userList;
    unordered_map<string,Provider> providerList;
    unordered_map<string, AirCleaner> airCleanerList;
    vector<Measure> measureList;
};

//-------------------------------- Autres définitions dépendantes de <DataSet>

#endif // DATASET_H