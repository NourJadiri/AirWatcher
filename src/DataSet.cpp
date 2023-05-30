
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

DataSet :: ~DataSet()
{

#ifdef MAP
    cout << "Appel au destructeur de <DataSet>" << endl;
#endif
}


void DataSet::initSensorList() {
    sensorsList = std::move(fileManager.ParseSensorList());
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

const unordered_map<string, Sensor> &DataSet::getSensorsList() const {
    return sensorsList;
}

void DataSet::setSensorsList(const unordered_map<string, Sensor> &sensorsList) {
    DataSet::sensorsList = sensorsList;
}

const unordered_map<string, PrivIndiv> &DataSet::getUserList() const {
    return userList;
}

void DataSet::setUserList(const unordered_map<string, PrivIndiv> &userList) {
    DataSet::userList = userList;
}

const unordered_map<string, Provider> &DataSet::getProviderList() const {
    return providerList;
}

void DataSet::setProviderList(const unordered_map<string, Provider> &providerList) {
    DataSet::providerList = providerList;
}

const vector<Measure> &DataSet::getMeasureList() const {
    return measureList;
}

void DataSet::setMeasureList(const vector<Measure> &measureList) {
    DataSet::measureList = measureList;
}

const vector<AirCleaner> &DataSet::getAirCleanerList() const {
    return airCleanerList;
}

void DataSet::setAirCleanerList(const vector<AirCleaner> &airCleanerList) {
    DataSet::airCleanerList = airCleanerList;
}


//------- Fin de ~DataSet (destructeur)


