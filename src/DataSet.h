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

private:
    unordered_map<string,Sensor> sensorsList;
    unordered_map<string,User> userList;
    unordered_map<string,Provider> providerList;
    vector<Measure> measureList;
    vector<AirCleaner> airCleanerList;

};

//-------------------------------- Autres définitions dépendantes de <DataSet>

#endif // DATASET_H