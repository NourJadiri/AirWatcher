
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

const unordered_map<string, Sensor> &DataSet::getSensorsList() const {
    return sensorsList;
}

void DataSet::setSensorsList(const unordered_map<string, Sensor> &sensorsList) {
    DataSet::sensorsList = sensorsList;
}

const unordered_map<string, User> &DataSet::getUserList() const {
    return userList;
}

void DataSet::setUserList(const unordered_map<string, User> &userList) {
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


