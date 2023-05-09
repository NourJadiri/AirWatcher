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


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PrivIndiv>
//
//
//
//------------------------------------------------------------------------

class PrivIndiv
{
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    vector<Sensor> & getProvidedSensors();

    void setProvidedSensors(vector<Sensor> provSens);

    int & getPoints();

    void setPoints(int aPoint);

//-------------------------------------------- Constructeurs - destructeur

    PrivIndiv ( vector<Sensor> provSens );


    virtual ~PrivIndiv ( );


//------------------------------------------------------------------ PRIVE

protected:

    //----------------------------------------------------- Attributs protégés
    vector<Sensor> providedSensors;
    int points;

};

//-------------------------------- Autres définitions dépendantes de <PrivIndiv>

#endif // PRIVINDIV_H