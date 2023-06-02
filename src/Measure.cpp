/*************************************************************************
                           Measure  -  a measurement of a pollutant
                             -------------------
    beginning            : 09/05/2023
    copyright            : (C) 2023 by Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Réalisation de la classe <Measure> (fichier Measure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <utility>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Measure.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//---------------------------------------------------------------- Getters

string & Measure::getSensorId(){
    return this->sensorId;
}

time_t & Measure::getDateMeas(){
    return this->dateMeas;
}

string & Measure::getAttributeValue(){
    return this->attributeType;
}

double & Measure::getValue(){
    return this->value;
}

//---------------------------------------------------------------- Setters

void Measure::setSensorId(string anId){
    this->sensorId = anId;
}

void Measure::setDateMeas(time_t aDate){
    this->dateMeas = aDate;
}

void Measure::setAttributeType(string aType){
    this->attributeType = aType;
}

void Measure::setValue(double aValue){
    this->value = aValue;
}

//-------------------------------------------- Constructeurs - destructeur

Measure::Measure ( )
{
}

Measure::Measure (string  sensorIdInput, const time_t& dateMeasInput, string  attributeTypeInput, const double& valueInput)
: sensorId(sensorIdInput), dateMeas(dateMeasInput), attributeType(attributeTypeInput), value(valueInput)
{
}

Measure::~Measure( )
{
}

