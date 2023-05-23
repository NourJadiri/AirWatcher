//
// Created by Celia Djouadi on 23/05/2023.
//

//---------- Interface de la classe <Attribute> (fichier Attribute.h) ----------------
#if ! defined ( Attribute_H )
#define Attribute_H
#include <cstring>
//------------------------------------------------------------------------

//------------------------------------------------------------------------

class Attribute {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//-----------------------------------------------------------------Getters
    string getType()
    {
        return type;
    }

    string getUnit()
    {
        return unit;
    }


    string getDescription()
    {
        return description;
    }
    //-----------------------------------------------------------------Setters

    void setType( string id)
    {
        type = id;
    }

    void setUnit(string unite)
    {
        unit = unite;
    }

    void setDescription( string description)
    {
        description= description;
    }

//-------------------------------------------- Autres Methodes
//-------------------------------------------- Constructeurs - destructeur

    Attribute ( const Attribute & anAttribute );

    Attribute ( );

    Attribute ( string unit , string type , string description  );

    virtual ~Attribute ( );



//------------------------------------------------------------------ PRIVE

private:

//----------------------------------------------------- Attribut privés
    string type;

    string unit;

    string description;
};


#endif //ATTRIBUTE_H
