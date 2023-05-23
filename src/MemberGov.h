/*************************************************************************
                           MemberGov  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/
//
// Created by Isaline FOISSEY on 23/05/2023.
//
//---------- Interface de la classe <MemberGov> (fichier MemberGov.h) ----------------
#ifndef AIRWATCHER_MEMBERGOV_H
#define AIRWATCHER_MEMBERGOV_H
//------------------------------------------------------ Include personnel
#include "AirCleaner.h"


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <MemberGov>
//
//
//
//------------------------------------------------------------------------
class MemberGov
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void analysePIndSensor();

    void analysePIndSensor(String sensorId);

//-------------------------------------------- Constructeurs - destructeur

    MemberGov ();

    virtual ~MemberGov( );

//------------------------------------------------------------------ PRIVE

protected:

    //----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <MemberGov>



#endif //AIRWATCHER_MEMBERGOV_H
