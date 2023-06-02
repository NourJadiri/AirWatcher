/*************************************************************************
                           InitService  -  populating database
                             -------------------
    beginning            : 09/05/2023
    copyright            : (C) 2023 by Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <InitService> (fichier InitService.h) ----------------
#if ! defined ( INITSERVICE_H )
#define INITSERVICE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include "DataSet.h"
#include "FileManager.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <InitService>
//
//
//
//------------------------------------------------------------------------

class InitService
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Initialize();

//-------------------------------------------- Constructeurs - destructeur

    InitService ( DataSet & dataInput );

    InitService();

    virtual ~InitService ( );

//------------------------------------------------------------------ PRIVE

private:

    DataSet * data;
};

#endif // INITSERVICE_H

