/*************************************************************************
                           User  -  description
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <User> (fichier User.h) ----------------
#if ! defined ( USER_H )
#define USER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <User>
//
//
//
//------------------------------------------------------------------------

class User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    const string& getId() const;
    bool operator<(const User& other) const;
    bool operator==(const User& other) const;

//-------------------------------------------- Constructeurs - destructeur

    explicit User(const string& idInput);

    User();
    // Constructor without password

//------------------------------------------------------------------ PRIVE

protected:
    string id;
};

#endif // USER_H
