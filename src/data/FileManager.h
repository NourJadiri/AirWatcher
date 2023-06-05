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
#include <set>
#include "../domain/Sensor.h"
#include "../domain/Coordinates.h"
#include "../domain/Measure.h"
#include "../domain/User.h"
#include "../domain/AirCleaner.h"
#include "../domain/Provider.h"


//------------------------------------------------------------- Constantes

// We define custom hash functions for pair <string, time_t> in order to use them for random access
struct PairHash {
    std::size_t operator()(const std::pair<std::string, std::time_t>& p) const {
        std::hash<std::string> stringHash;
        std::hash<std::time_t> timeHash;

        // Custom hash function for hashing pairs
        std::size_t hash = 17;
        hash = hash * 31 + stringHash(p.first);
        hash = hash * 31 + timeHash(p.second);
        return hash;
    }
};

// Define custom equality operator
struct PairEqual {
    template <typename T1, typename T2>
    bool operator()(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs) const {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }
};

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

    unordered_multimap<std::pair<string, time_t>, Measure, PairHash, PairEqual> ParseMeasureList();

    void UpdatePoints(const string& id, int points);

    time_t convertToTimeT(const string& dateString);

//-------------------------------------------- Constructeurs - destructeur

    FileManager ( );

    virtual ~FileManager ( );

private:

    string basePath = "../src/data/csv/";

};



#endif // FILEMANAGER_H

