/*************************************************************************
                           AirCleaner  -  description
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <AirCleaner> (fichier AirCleaner.h) ----------------
#if ! defined ( AIRCLEANER_H )
#define AIRCLEANER_H

//--------------------------------------------------- Interfaces utilisées
#include <string.h>
#include <map>
#include <ctime>
using namespace std;

typedef struct Coordinates {
    double long;
    double lat;
} Coordinates;


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AirCleaner>
//
//
//
//------------------------------------------------------------------------

class AirCleaner
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    string & getAirCleanerID();

    void setAirCleanerID(string anID);

    Coordinates & getCoord();

    void setCoord(Coordinates coord);

    time_t & getDateStart();

    void setDateStart(const time_t aStart);

    time_t & getDateStop();

    void setDateStop(const time_t aStop);

    AirCleaner & operator = ( const AirCleaner &anAirCleaner );

//-------------------------------------------- Constructeurs - destructeur

    AirCleaner (string idInput, Coordinates coordInput, time_t dateStartInput, time_t dateStopInput);

    virtual ~AirCleaner ( );

//------------------------------------------------------------------ PRIVE
private:
    string id;
    Coordinates coord;
    time_t dateStart;
    time_t dateStop;
};


//-------------------------------- Autres définitions dépendantes de <AirCleaner>

#endif // AIRCLEANER_H