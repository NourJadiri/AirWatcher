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
using namespace std;


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
    Vector<AirCleaner> & getProvidedAC();

    void setProvidedAC(Vector<AirCleaner> provAC);

//-------------------------------------------- Constructeurs - destructeur

    Provider ( );


    virtual ~Provider ( );

//------------------------------------------------------------------ PRIVE

protected:

    //----------------------------------------------------- Attributs protégés
    Vector<AirCleaner> providedAC;

};

//-------------------------------- Autres définitions dépendantes de <Provider>

#endif // PROVIDER_H