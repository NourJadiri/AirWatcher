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
#include <ctime>

using namespace std;

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
    const string & getSensorId() const;

    const time_t & getDateMeas() const;

    const string & getAttributeValue() const;

    double & getValue();

    void setSensorId(string anId);

    void setDateMeas(time_t aDate);

    void setAttributeType(string aType);

    void setValue(double aValue);

    friend struct MeasureComparator;
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

struct MeasureComparator {
    bool operator()(const Measure& lhs, const Measure& rhs) const {
        return lhs.dateMeas < rhs.dateMeas;
    }
};


#endif // MEASURE_H