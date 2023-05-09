
//---------- Réalisation de la classe <Measure> (fichier Measure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Measure.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

  string & Measure::getSensorId(){
      return this->sensorId;
  }

  void Measure::setSensorId(string anId){
      this->sensorId = anId;
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
      this->attributeType = aType;
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


Measure::~Measure( )
{
}//------- Fin de ~Measure() (destructeur)

