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

const string& User::getId() const {
    return id;
}

bool User::operator<(const User& other) const {
    return id < other.id;
}

bool User::operator==(const User& other) const {
    return id == other.id;
}

//-------------------------------------------- Constructeurs - destructeur

User::User(const string& idInput, const string& passwordInput) : id(idInput), password(passwordInput) {
}

User::User(const string& idInput) : id(idInput) {
}