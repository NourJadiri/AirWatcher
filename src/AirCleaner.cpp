//
// Created by adrid on 09/05/2023.


//---------- Réalisation de la classe <AirCleaner> (fichier AirCleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include "Coordinates.h"
using namespace std;

//------------------------------------------------------ Include personnel
#include "AirCleaner.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//Getters et Setters

  string & AirCleaner::getAirCleanerID() {
      return id;
  }

  void AirCleaner::setAirCleanerID(string anID){
      id = anID;
  }

  Coordinates & AirCleaner::getCoord(){
      return coord;
  }

  void AirCleaner::setCoord(const Coordinates& coordinates){
      coord = coordinates;
  }

  time_t & AirCleaner::getDateStart(){
      return dateStart;
  }

  void AirCleaner::setDateStart(const time_t aStart){
      dateStart = aStart;
  }

  time_t & AirCleaner::getDateStop(){
    return dateStop;
  }

  void AirCleaner::setDateStop(const time_t aStop){
      dateStop = aStop;
  }


//-------------------------------------------- Constructeurs - destructeur

AirCleaner :: AirCleaner ( string idInput, const Coordinates& coordInput, time_t dateStartInput, time_t dateStopInput)
{
  id = idInput;
  coord = coordInput;
  dateStart = dateStartInput;
  dateStop= dateStopInput;
} //----- Fin de AirCleaner

AirCleaner::~AirCleaner()
{
} //----- Fin de ~AirCleaner


