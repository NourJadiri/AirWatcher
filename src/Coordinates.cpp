
//---------- Réalisation de la classe <Coordinates> (fichier Coordinates.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Coordinates.h"


//----------------------------------------------------- Méthodes publiques

void InitSensors()
{

}

//-------------------------------------------- Constructeurs - destructeur

Coordinates::Coordinates ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Coordinates>" << endl;
#endif
} //----- Fin de Coordinates (constructeur par defaut)


Coordinates::~Coordinates( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Coordinates>" << endl;
#endif
}//------- Fin de ~Coordinates() (destructeur)

