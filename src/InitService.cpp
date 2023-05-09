//
// Created by adrid on 09/05/2023.
//

//---------- Réalisation de la classe <Admin> (fichier Admin.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Admin.h"
#include "User.h"


//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
Admin::Admin ( const Admin & anAdmin )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Admin>" << endl;
#endif
} //----- Fin de Admin (constructeur de copie)


Admin::Admin ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Admin>" << endl;
#endif
} //----- Fin de Admin (constructeur par defaut)


Admin::~Admin( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Admin>" << endl;
#endif
}//------- Fin de ~Admin() (destructeur)

