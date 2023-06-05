/*************************************************************************
                           Provider  -  user of type provider
                             -------------------
    beginning            : 09/05/2023
    copyright            : (C) 2023 by Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <Provider> (fichier Provider.h) ----------------
#if ! defined ( PROVIDER_H )
#define PROVIDER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include <vector>

//------------------------------------------------------ Include personnel
#include "domain/AirCleaner.h"
#include "SuperUser.h"

//------------------------------------------------------------------------
// Rôle de la classe <Provider>
//
//
//
//------------------------------------------------------------------------

class Provider : public SuperUser
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void printAirCleaners() const;

    const string &getProviderId() const;

    void setProviderId(const string &providerId);

    const vector<AirCleaner> &getProvidedAc() const;

    void setProvidedAc(const vector<AirCleaner> &providedAc);

//-------------------------------------------- Constructeurs - destructeur
    Provider();

    explicit Provider(string providerID);

    Provider (const string & providerID, const vector<AirCleaner> & airCleaners);

    virtual ~Provider ( );

//------------------------------------------------------------------ PRIVE

protected:

    //----------------------------------------------------- Attributs protégés
    string providerID;

    vector<AirCleaner> providedAC;

};

#endif // PROVIDER_H