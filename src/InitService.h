/*************************************************************************
                           InitService  -  description
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <InitService> (fichier InitService.h) ----------------
#if ! defined ( INITSERVICE_H )
#define INITSERVICE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include "DataSet.h"
using namespace std;


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
private:
    DataSet * data;

//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

void Initialize();


//-------------------------------------------- Constructeurs - destructeur

    InitService ( DataSet & dataInput );

    InitService();


    virtual ~InitService ( );


};

//-------------------------------- Autres définitions dépendantes de <InitService>


#endif // INITSERVICE_H

