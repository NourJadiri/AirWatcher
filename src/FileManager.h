/*************************************************************************
                           FileManager  -  description
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <FileManager> (fichier FileManager.h) ----------------
#if ! defined ( INITSERVICE_H )
#define INITSERVICE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include <vector>
#include <unordered_map>
#include "Sensor.h"
#include "Measure.h"
#include "User.h"
#include "AirCleaner.h"
#include "Provider.h"

using namespace std;


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <FileManager>
//
//
//
//------------------------------------------------------------------------

class FileManager
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    unordered_map<string, Sensor> ParseSensorList();
    vector<Measure> ParseMeasureList();
    map<User, vector<string>> ParseUserList();
    vector<AirCleaner> ParseAirCleanerList(const string & path);
    vector<Provider> ParseProviderList(const string & path);

//-------------------------------------------- Constructeurs - destructeur

    FileManager ( );


    virtual ~FileManager ( );


};

//-------------------------------- Autres définitions dépendantes de <FileManager>

#endif // INITSERVICE_H

