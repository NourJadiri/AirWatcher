
//---------- Réalisation de la classe <SuperUser> (fichier SuperUser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "SuperUser.h"
#include "User.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur

SuperUser::SuperUser ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <SuperUser>" << endl;
#endif
} //----- Fin de SuperUser

SuperUser::~SuperUser ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <SuperUser>" << endl;
#endif
} //----- Fin de SuperUser

