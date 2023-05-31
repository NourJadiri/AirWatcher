
//---------- Réalisation de la classe <DataSet> (fichier DataSet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cmath>
using namespace std;

//------------------------------------------------------ Include personnel
#include "DataSet.h"

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur

DataSet::DataSet()
{
    initSensorList();
    initUserList();
#ifdef MAP
    cout << "Appel au constructeur de <DataSet>" << endl;
#endif
}//----- Fin de DataSet(constructeur)

DataSet :: ~DataSet() = default;


void DataSet::initSensorList() {
    sensorsList = std::move(fileManager.ParseSensorList());
}

void DataSet::initAirCleanerList() {
    airCleanerList = std::move(fileManager.ParseAirCleanerList());
}

void DataSet::initUserList() {
    unordered_map<string, vector<string>> usersSensors = fileManager.ParseUserList();

    // For each user in the user-sensor list
    for(const auto & pair : usersSensors){
        auto key = pair.first;
        auto sensorsIds = pair.second;

        // Create a vector of Sensors
        vector<Sensor> userSensorList{};
        userSensorList.reserve(sensorsIds.size());

        // And use the sensorList to get all the sensors of a specific user
        for(const auto& sensor : sensorsIds){
            userSensorList.push_back(sensorsList[sensor]);
        }

        PrivIndiv pindiv(key, userSensorList);

        userList[key] = pindiv;
    }
}

void DataSet::initProviderList() {
    unordered_map<string, vector<string>> providersAirCleaners = fileManager.ParseProviderList();

    for(const auto & pair : providersAirCleaners){
        auto key = pair.first;
        auto airCleanersIds = pair.second;

        // We create the vector of aircleaners
        vector<AirCleaner> airCleanersList{};
        airCleanersList.reserve(airCleanersIds.size());

        // And then we get all the airCleanersIds provided by the same provider
        for(const auto & airCleanerId : airCleanersIds){
            airCleanersList.push_back(airCleanerList[airCleanerId]);
        }

        Provider provider(key, airCleanersList);

        providerList[key] = provider;
    }
}






const unordered_map<string, Sensor> &DataSet::getSensorsList() const {
    return sensorsList;
}

void DataSet::setSensorsList(const unordered_map<string, Sensor> &list) {
    DataSet::sensorsList = list;
}

const unordered_map<string, PrivIndiv> &DataSet::getUserList() const {
    return userList;
}

void DataSet::setUserList(const unordered_map<string, PrivIndiv> &list) {
    DataSet::userList = list;
}

const unordered_map<string, Provider> &DataSet::getProviderList() const {
    return providerList;
}

void DataSet::setProviderList(const unordered_map<string, Provider> &list) {
    DataSet::providerList = list;
}

const vector<Measure> &DataSet::getMeasureList() const {
    return measureList;
}

void DataSet::setMeasureList(const vector<Measure> &list) {
    DataSet::measureList = list;
}

const FileManager &DataSet::getFileManager() const {
    return fileManager;
}

void DataSet::setFileManager(const FileManager &manager) {
    DataSet::fileManager = manager;
}

//------- Fin de ~DataSet (destructeur)


