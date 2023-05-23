/*************************************************************************
                           FileManager  -  description
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <FileManager> (fichier FileManager.h) ----------------
#if ! defined ( INITSERVICE_H )
#define INITSERVICE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
using namespace std;


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <FileManager>
//
//
//
//------------------------------------------------------------------------

class FileManager
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void InitSensors();


//-------------------------------------------- Constructeurs - destructeur

    FileManager ( );


    virtual ~FileManager ( );


};

//-------------------------------- Autres définitions dépendantes de <FileManager>

#endif // INITSERVICE_H

