/*************************************************************************
                           Test  -  class for tests
                             -------------------
    beginning            : 09/05/2023
    copyright            : (C) 2023 by Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <Test> (fichier Test.h) ----------------
#if ! defined ( TEST_H )
#define TEST_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>

//------------------------------------------------------ Include personnel
#include "../data/FileManager.h"
#include "../domain/DataSet.h"
#include "../services/AppService.h"

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

    //----------------------------------------------------- Méthodes publiques
    void testGetATMOIdx(DataSet* dataSet);

    void testComputeMeanATMOIdx(DataSet* dataSet);

    void testAddPointsToPrivIndiv(DataSet* dataSet);

    void testGetSensorsAround(DataSet* dataSet);

    void testGetMeasuresAtMoment(DataSet* dataSet);

    void testObsImpactLvlImprov(DataSet* dataSet);

    void testProduceStatsMoment(DataSet* dataSet);

    time_t convertToTimeT(const std::string& dateStr);

    string convertTimeToString(const time_t& time);

    void testUpdatePoints();

    //-------------------------------------------- Constructeurs - destructeur

    Test ( );

    virtual ~Test ( );

};


#endif // TEST_H