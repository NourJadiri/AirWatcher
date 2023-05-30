/*************************************************************************
                           PrivIndiv  -  description
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <PrivIndiv> (fichier PrivIndiv.h) ----------------
#if ! defined ( PRIVINDIV_H )
#define PRIVINDIV_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include <vector>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Sensor.h"
#include "User.h"


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PrivIndiv>
//
//
//
//------------------------------------------------------------------------

class PrivIndiv : public User
{
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------------------- PUBLIC

public:
    PrivIndiv();

//----------------------------------------------------- Méthodes publiques
    vector<Sensor> & getProvidedSensors();

    void printProvidedSensors() const;

    void setProvidedSensors(vector<Sensor> provSens);

    int & getPoints();

    void setPoints(int aPoint);

//-------------------------------------------- Constructeurs - destructeur

    PrivIndiv ( const string &id, vector<Sensor> provSens );


    virtual ~PrivIndiv ( );


//------------------------------------------------------------------ PRIVE

protected:

    //----------------------------------------------------- Attributs protégés
    vector<Sensor> providedSensors;
    int points{};

};

//-------------------------------- Autres définitions dépendantes de <PrivIndiv>

#endif // PRIVINDIV_H