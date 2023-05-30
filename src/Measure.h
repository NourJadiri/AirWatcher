/*************************************************************************
                           Measure  -  description
                             -------------------
    début                : 09/05/2023
    copyright            : (C) 2023 par Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <Measure> (fichier Measure.h) ----------------
#if ! defined ( MEASURE_H )
#define MEASURE_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
#include <map>
using namespace std;


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Measure>
//
//
//
//------------------------------------------------------------------------

class Measure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    string & getSensorId();

    void setSensorId(string anId);

    time_t & getDateMeas();

    void setDateMeas(time_t aDate);

    string & getAttributeValue();

    void setAttributeType(string aType);

    double & getValue();

    void setValue(double aValue);

//-------------------------------------------- Constructeurs - destructeur

    Measure ( );
    Measure ( string  sensorIdInput, const time_t& dateMeasInput, string  attributeTypeInput, const double& valueInput);

    virtual ~Measure ( );

//------------------------------------------------------------------ PRIVE

protected:

    //----------------------------------------------------- Attributs protégés
    string sensorId;
    time_t dateMeas{};
    string attributeType;
    double value{};
};

//-------------------------------- Autres définitions dépendantes de <Measure>

#endif // MEASURE_H