/*************************************************************************
                           Attribute  -  type of pollutant
                             -------------------
    beginning            : 09/05/2023
    copyright            : (C) 2023 by Q41 : Adrien Morin, Isaline Foissey, Marie Roulier, Célia Djouadi et Nour ElJadiri
*************************************************************************/

//---------- Interface de la classe <Attribute> (fichier Attribute.h) ----------------
#if ! defined ( Attribute_H )
#define Attribute_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>

//------------------------------------------------------------------------
// Rôle de la classe <Attribute>
//
//
//
//------------------------------------------------------------------------

class Attribute {
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    std::string getType();

    std::string getUnit();

    std::string getDescription();

    void setType(string id);

    void setUnit(string unite);

    void setDescription( string aDescription);

//-------------------------------------------- Constructeurs - destructeur

    Attribute ( const Attribute & anAttribute );

    Attribute ( );

    Attribute ( string unit, string type, string description );

    virtual ~Attribute ( );


//------------------------------------------------------------------ PRIVE

private:

//----------------------------------------------------- Attribut privés
    string type;

    string unit;

    string description;
};


#endif //ATTRIBUTE_H
