/*************************************************************************
                           User  -  person who uses the app (abstract)
                             -------------------
    beginning            : 09/05/2023
    copyright            : (C) 2023 by Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <User> (fichier User.h) ----------------
#if ! defined ( USER_H )
#define USER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

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
    const std::string& getId() const;

    bool operator<(const User& other) const;

    bool operator==(const User& other) const;

//-------------------------------------------- Constructeurs - destructeur
    explicit User(const std::string& idInput);

    User();

//------------------------------------------------------------------ PRIVE

protected:

    std::string id;

};

#endif // USER_H
