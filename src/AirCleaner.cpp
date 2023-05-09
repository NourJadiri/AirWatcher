//
// Created by adrid on 09/05/2023.


//---------- Réalisation de la classe <AirCleaner> (fichier AirCleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "AirCleaner.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//Getters et Setters

  string AirCleaner::getAirCleanerID(){
    return airCleanerID;
  }

  void AirCleaner::setAirCleanerID(string anID ){
    aircleanerID = anID;
  }

  float AirCleaner::getCoord(){
    return coordinates;
  }

  void AirCleaner::setCoord(Coordinates coord){
    coordinates = coord;
  }


  string AirCleaner::getStart(){
    return start;
  }

  void AirCleaner::setStart(const Date aStart){
    start = aStart;
  }

  string AirCleaner::getStop(){
    return stop;
  }

  void AirCleaner::setStop(const Date aStop){
    stop = aStop;
  }


//------------------------------------------------- Surcharge d'opérateurs
AirCleaner & AirCleaner::operator = ( const AirCleaner &anAirCleaner )
{
  AircleanerID = anAirCleaner.AircleanerID;
  coordinates = anAirCleaner.coordinates;
  start = anAirCleaner.start;
  stop = anAirCleaner.stop;

return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AirCleaner::AirCleaner(const Cleaner & anAirCleaner )
{
   AircleanerID = anAirCleaner.AircleanerID;
  coordinates = anAirCleaner.coordinates;
  start = anAirCleaner.start;
  stop = anAirCleaner.stop;


#ifdef MAP
    cout << "Appel au constructeur de copie de <AirCleaner>" << endl;
#endif
} //----- Fin de AirCleaner (constructeur de copie)


AirCleaner::AirCleaner( )
{
  #ifdef MAP
      cout << "Appel au constructeur par défaut <AirCleaner>" << endl;
  #endif
} //----- Fin de AirCleaner(constructeur par défaut)


AirCleaner :: AirCleaner ( string id, Coordinates coord, Date dateStart, Date dateStop)
{
  airCleanerID = id;
  coordinates = coord;
  start = dateStart;
  stop= dateStop;

  #ifdef MAP
      cout << "Appel au constructeur de <AirCleaner>" << endl;
  #endif
} //----- Fin de AirCleaner

AirCleaner::~AirCleaner()
{
#ifdef MAP
    cout << "Appel au destructeur de <AirCleaner>" << endl;
#endif
} //----- Fin de ~AirCleaner


