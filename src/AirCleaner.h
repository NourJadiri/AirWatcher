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
#include <cstring>
#include <map>
#include "Coordinates.h"
#include <ctime>
using namespace std;


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

    const string & getAirCleanerID() const;

    const Coordinates & getAirCleanerCoord() const;

    void setAirCleanerID(string anID);

    void setCoord(const Coordinates& coord);

    const time_t & getDateStart() const;

    void setDateStart(time_t aStart);

    const time_t & getDateStop() const;

    void setDateStop(time_t aStop);

//-------------------------------------------- Constructeurs - destructeur

    AirCleaner() = default;

    AirCleaner (string idInput, const Coordinates& coordInput, time_t dateStartInput, time_t dateStopInput);

    virtual ~AirCleaner ( );

//------------------------------------------------------------------ PRIVE
private:
    string id;
    Coordinates coord;
public:
    const Coordinates &getCoord() const;

private:
    time_t dateStart{};
    time_t dateStop{};
};


//-------------------------------- Autres définitions dépendantes de <AirCleaner>

#endif // AIRCLEANER_H