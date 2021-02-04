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

friend bool cmp(pair<string, int>& a, 
         pair<string, int>& b); 

friend class DotWriter;

//----------------------------------------------------- Méthodes publiques

    map<string, map<string, int> >  GetGraph();
    //Mode d'emploi :
    //
    //Contrat : 
    //

    void Adapt(LogLineReader llr);
    //Mode d'emploi :
    //
    //Contrat : 
    //

   

    void AfficheTopTen(); //Remplir + trier + afficher

 
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


    void remplirTopTen();
    //Mode d'emploi : 
    //Contrat :
    //

//----------------------------------------------------- Attributs protégés

    map<string, map<string, int> > graph;
    map<string, int> topTen;
};

//-------------------------------- Autres définitions dépendantes de <Data>

#endif // DATA_H

