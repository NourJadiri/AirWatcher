/*************************************************************************
                           Measure  -  a measurement of a pollutant
                             -------------------
    beginning            : 09/05/2023
    copyright            : (C) 2023 by Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <Measure> (fichier Measure.h) ----------------
#if ! defined ( MEASURE_H )
#define MEASURE_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
#include <map>
#include <ostream>

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

    time_t & getDateMeas();

    string & getAttributeValue();

    double & getValue();

    void setSensorId(string anId);

    void setDateMeas(time_t aDate);

    void setAttributeType(string aType);

    void setValue(double aValue);

    friend ostream &operator<<(ostream &os, const Measure &measure);

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


#endif // MEASURE_H