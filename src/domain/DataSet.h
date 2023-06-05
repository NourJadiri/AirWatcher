/*************************************************************************
                           DataSet  -  the data base
                             -------------------
    beginning            : 09/05/2023
    copyright            : (C) 2023 by Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <DataSet> (fichier DataSet.h) ----------------
#if ! defined ( DATASET_H )
#define DATASET_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include <vector>
#include <unordered_map>
#include <set>
#include "Sensor.h"
#include "Measure.h"
#include "AirCleaner.h"
#include "User.h"
#include "Provider.h"
#include "data/FileManager.h"
#include "PrivIndiv.h"

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
    void initSensorList();

    void initUserList();

    void initProviderList();

    void initMeasureList();

    void initAirCleanerList();

    const unordered_map<string, Sensor> &getSensorsList() const;

    const unordered_map<string, AirCleaner> &getAirCleanerList() const;

    void setSensorsList(const unordered_map<string, Sensor> &list);

    unordered_map<string, PrivIndiv> &getUserList();

    void setUserList(const unordered_map<string, PrivIndiv> &list);

    const unordered_map<string, Provider> &getProviderList() const;

    void setProviderList(const unordered_map<string, Provider> &list);

    const unordered_multimap<std::pair<string, time_t>, Measure, PairHash, PairEqual> &getMeasureList() const;

    void setMeasureList(const unordered_multimap<std::pair<string, time_t>, Measure, PairHash, PairEqual> &list);

    const FileManager &getFileManager() const;

    void setFileManager(const FileManager &manager);

//-------------------------------------------- Constructeurs - destructeur

    DataSet ( );

    virtual ~DataSet ( );

//------------------------------------------------------------------ PRIVE

private:
    FileManager fileManager;

    unordered_map<string, Sensor> sensorsList;

    unordered_map<string, PrivIndiv> userList;

    unordered_map<string, Provider> providerList;

    unordered_map<string, AirCleaner> airCleanerList;

    unordered_multimap<std::pair<string, time_t>, Measure, PairHash, PairEqual> measureList;
};

#endif // DATASET_H