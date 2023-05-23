// Created by Celia Djouadi on 23/05/2023.
//---------- Réalisation de la classe <Attribute> (fichier Attribute.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Attribute.h"



//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
Attribute::Attribute ( const Attribute & anAttribute )
{
    unit = anAttribute.unit;
    type = anAttribute.type;
    description = anAttribute.description;

#ifdef MAP
    cout << "Appel au constructeur de copie de <Attribute>" << endl;
#endif
} //----- Fin de Attribute (constructeur par defaut)


Attribute::Attribute( string unit , string type , string description  )
{
    type = type;
    unit = unit;
    description = description;
#ifdef MAP
    cout << "Appel au constructeur de <Attribute>" << endl;
#endif
} //----- Fin de Attribute (constructeur)


Attribute::~Attribute ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Attribute>" << endl;
#endif
} //----- Fin de ~Attribute (destructeur)


