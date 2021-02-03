//---------- Interface de la classe <Data> (fichier Data.h) ----------------
#if ! defined ( DATA_H )
#define DATA_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include "LogLineReader.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Data>
//
//
//------------------------------------------------------------------------

class Data
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Adapt(LogLineReader llr);
    //Mode d'emploi :
    //
    //Contrat : 
    //

 
//-------------------------------------------- Constructeurs - destructeur

    Data ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Data( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    map<string, map<string, int>> graph;
    map<string, int> topTen;

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Data>

#endif // DATA_H

