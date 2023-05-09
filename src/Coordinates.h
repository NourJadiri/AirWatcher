/*************************************************************************
                           Coordinates  -  description
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <Coordinates> (fichier Coordinates.h) ----------------
#if ! defined ( COORDINATES_H )
#define COORDINATES_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
using namespace std;


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Coordinates>
//
//
//
//------------------------------------------------------------------------

class Coordinates
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    double Distance(Coordinates point);

//-------------------------------------------- Constructeurs - destructeur

    Coordinates(double longInput, double latInput);

    virtual ~Coordinates ( );

//------------------------------------------------------------------ PRIVE
private:
    double longitude;
    double latitude;

};

//-------------------------------- Autres définitions dépendantes de <Coordinates>

#endif // COORDINATES_H