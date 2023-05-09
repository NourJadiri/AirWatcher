//
// Created by adrid on 09/05/2023.
//


//---------- Réalisation de la classe <User> (fichier User.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "User.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur

User::User(string idInput, string passwordInput)
{
  password = passwordInput;
  id = idInput;

#ifdef MAP
    cout << "Appel au constructeur de <User>" << endl;
#endif
} //----- Fin de User


User::  ~User ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <User>" << endl;
#endif
} //----- Fin de ~User


