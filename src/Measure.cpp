
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

  string & Measure::getSensorId(){
      return this->sensorId;
  }

  void Measure::setSensorId(string anId){
      this->sensorId = std::move(anId);
  }

  time_t & Measure::getDateMeas(){
      return this->dateMeas;
  }

  void Measure::setDateMeas(time_t aDate){
      this->dateMeas = aDate;
  }

  string & Measure::getAttributeType(){
      return this->attributeType;
  }

  void Measure::setAttributeType(string aType){
      this->attributeType = std::move(aType);
  }

  double & Measure::getValue(){
      return this->value;
  }

  void Measure::setValue(double aValue){
      this->value = aValue;
  }




//-------------------------------------------- Constructeurs - destructeur

Measure::Measure ( )
{
} //----- Fin de Measure (constructeur par defaut)

Measure::Measure (string  sensorIdInput, const time_t& dateMeasInput, string  attributeTypeInput, const double& valueInput) : sensorId(std::move(sensorIdInput)), dateMeas(dateMeasInput), attributeType(std::move(attributeTypeInput)), value(valueInput)
{
} //----- Fin de Measure (constructeur)


Measure::~Measure( )
{
}//------- Fin de ~Measure() (destructeur)

