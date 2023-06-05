/*************************************************************************
                           User  -  person who uses the app (abstract)
                             -------------------
    beginning            : 09/05/2023
    copyright            : (C) 2023 by Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Réalisation de la classe <User> (fichier User.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------ Include personnel
#include "User.h"

#include <utility>
using namespace std;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

const string& User::getId() const {
    return id;
}

//------------------------------------------------- Surcharge d'opérateurs

bool User::operator<(const User& other) const {
    return id < other.id;
}

bool User::operator==(const User& other) const {
    return id == other.id;
}

//-------------------------------------------- Constructeurs - destructeur

User::User(string  idInput) : id(std::move(idInput)) {
}

User::User() = default;
