
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

const vector<Measure> &DataSet::getMeasureList() const {
    return measureList;
}

void DataSet::setMeasureList(const vector<Measure> &measureList) {
    DataSet::measureList = measureList;
}

const vector<Sensor> &DataSet::getSensorsList() const {
    return sensorsList;
}

void DataSet::setSensorsList(const vector<Sensor> &sensorsList) {
    DataSet::sensorsList = sensorsList;
}

const vector<AirCleaner> &DataSet::getAirCleanerList() const {
    return airCleanerList;
}

void DataSet::setAirCleanerList(const vector<AirCleaner> &airCleanerList) {
    DataSet::airCleanerList = airCleanerList;
}

const vector<User> &DataSet::getUserList() const {
    return userList;
}

void DataSet::setUserList(const vector<User> &userList) {
    DataSet::userList = userList;
}

const vector<Provider> &DataSet::getProviderList() const {
    return providerList;
}

void DataSet::setProviderList(const vector<Provider> &providerList) {
    DataSet::providerList = providerList;
}
//------- Fin de ~DataSet (destructeur)


