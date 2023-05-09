
//---------- Réalisation de la classe <DataSet> (fichier DataSet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

//------------------------------------------------------ Include personnel
#include "DataSet.h"

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur

DataSet::DataSet(string aId, Coordinates someCoord, bool reliable)
{
    this->id = aId;
    coord = someCoord;
    reliable = reliable;

#ifdef MAP
    cout << "Appel au constructeur de <DataSet>" << endl;
#endif
}//----- Fin de DataSet(constructeur)

DataSet :: ~DataSet()
{

#ifdef MAP
    cout << "Appel au destructeur de <DataSet>" << endl;
#endif
} //------- Fin de ~DataSet (destructeur)


