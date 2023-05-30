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
#include "Sensor.h"
#include "Measure.h"
#include "AirCleaner.h"
#include "User.h"
#include "Provider.h"

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
public:
    const vector<Measure> &getMeasureList() const;

    void setMeasureList(const vector<Measure> &measureList);

    const vector<Sensor> &getSensorsList() const;

    void setSensorsList(const vector<Sensor> &sensorsList);

    const vector<AirCleaner> &getAirCleanerList() const;

    void setAirCleanerList(const vector<AirCleaner> &airCleanerList);

    const vector<User> &getUserList() const;

    void setUserList(const vector<User> &userList);

    const vector<Provider> &getProviderList() const;

    void setProviderList(const vector<Provider> &providerList);

private:
    vector<Measure> measureList;
    vector<Sensor> sensorsList;
    vector<AirCleaner> airCleanerList;
    vector<User> userList;
    vector<Provider> providerList;

};

//-------------------------------- Autres définitions dépendantes de <DataSet>

#endif // DATASET_H