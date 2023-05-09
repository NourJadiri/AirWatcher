/*************************************************************************
                           Provider  -  description
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <Provider> (fichier Provider.h) ----------------
#if ! defined ( PROVIDER_H )
#define PROVIDER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include <vector>
using namespace std;

//------------------------------------------------------ Include personnel
#include "AirCleaner.h"


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Provider>
//
//
//
//------------------------------------------------------------------------

class Provider
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    vector<AirCleaner> & getProvidedAC();

    void setProvidedAC(vector<AirCleaner> provAC);

//-------------------------------------------- Constructeurs - destructeur

    Provider ( vector<AirCleaner> airCleaners );

    virtual ~Provider ( );

//------------------------------------------------------------------ PRIVE

protected:

    //----------------------------------------------------- Attributs protégés
    vector<AirCleaner> providedAC;

};

//-------------------------------- Autres définitions dépendantes de <Provider>

#endif // PROVIDER_H