
//---------- Réalisation de la classe <Measure> (fichier Measure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Measure.h"


//----------------------------------------------------- Méthodes publiques



//-------------------------------------------- Constructeurs - destructeur

Measure::Measure ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Measure>" << endl;
#endif
} //----- Fin de Measure (constructeur par defaut)


Measure::~Measure( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Measure>" << endl;
#endif
}//------- Fin de ~Measure() (destructeur)

