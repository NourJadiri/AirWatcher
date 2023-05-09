
//---------- Réalisation de la classe <Attribute> (fichier Attribute.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Attribute.h"


//----------------------------------------------------- Méthodes publiques



//-------------------------------------------- Constructeurs - destructeur

Attribute::Attribute ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Attribute>" << endl;
#endif
} //----- Fin de Attribute (constructeur par defaut)


Attribute::~Attribute( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Attribute>" << endl;
#endif
}//------- Fin de ~Attribute() (destructeur)

