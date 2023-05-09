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
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void InitSensors();


//-------------------------------------------- Constructeurs - destructeur

    InitService ( );


    virtual ~InitService ( );


};

//-------------------------------- Autres définitions dépendantes de <InitService>

#endif // INITSERVICE_H

