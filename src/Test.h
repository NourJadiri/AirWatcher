/*************************************************************************
                           Test  -  Classe de tests
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <Test> (fichier Test.h) ----------------
#if ! defined ( TEST_H )
#define TEST_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
using namespace std;


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Test>
//
//
//
//------------------------------------------------------------------------

class Test
{
//----------------------------------------------------------------- PUBLIC

public:
    void testComputeMeanATMOIdx(DataSet* dataSet);
    void testGetSensorsAround(DataSet* dataSet);
    void testMeasureAtMoment(DataSet* dataSet);


//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur

    Test ( );


    virtual ~Test ( );


};

//-------------------------------- Autres définitions dépendantes de <Test>

#endif // TEST_H