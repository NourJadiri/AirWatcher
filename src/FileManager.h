/*************************************************************************
                           FileManager  -  description
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <FileManager> (fichier FileManager.h) ----------------
#if ! defined ( FILEMANAGER_H )
#define FILEMANAGER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include <vector>
#include <unordered_map>
#include "Sensor.h"
#include "Coordinates.h"
#include "Measure.h"
#include "User.h"
#include "AirCleaner.h"
#include "Provider.h"


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

    unordered_map<string, vector<string>> ParseUserList();

    unordered_map<string, AirCleaner> ParseAirCleanerList();

    unordered_map<string, vector<string>> ParseProviderList();

    map<string, int> ParsePointsFile();

    vector<Measure> ParseMeasureList();

    void UpdatePoints(string id, int points);

    time_t convertToTimeT(const string& dateString);

//-------------------------------------------- Constructeurs - destructeur

    FileManager ( );

    virtual ~FileManager ( );

};

#endif // FILEMANAGER_H

