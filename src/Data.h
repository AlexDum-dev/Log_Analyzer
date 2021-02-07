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
// La classe Data contient les informations contenues dans les fichiers log.
//
//------------------------------------------------------------------------

class Data
{
//----------------------------------------------------------------- PUBLIC

public:

    friend bool cmp ( pair <string, int> & a, pair <string, int> & b ) ; 

    friend class DotWriter;

//----------------------------------------------------- Méthodes publiques

    map <string, map<string, int> > GetGraph ( ) ;
    // Mode d'emploi :
    // La méthode GetGraph() renvoie l'attribut graph de l'objet invoquant
    // la méthode. Cette méthode est notamment utile pour la classe DotWriter
    // Contrat : 
    // Aucun contrat.

    void Adapt ( LogLineReader llr ) ;
    // Mode d'emploi :
    // La méthode Adapt permet de modifier l'attribut graph de l'objet invoquant
    // la méthode avec un LogLineReader passé en paramètre. 
    // Contrat : 
    // Aucun contrat.

   

    void AfficheTopTen ( ) ; //Remplir + trier + afficher
    // Mode d'emploi :
    // Cette méthode remplit, trie et affiche l'attribut topTen de l'objet invoquant
    // la méthode
    // Contrat : Aucun contrat.

 
//-------------------------------------------- Constructeurs - destructeur

    Data ( );
    // Mode d'emploi :
    // Contruit un objet de type Data vide.
    // Contrat :
    //

    virtual ~Data ( );
    // Mode d'emploi :
    // Détruit l'objet Data.
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées


    void remplirTopTen ( ) ;
    // Mode d'emploi : 
    // Cette méthode remplit l'attribut topTen de l'objet invoquant
    // la méthode.
    // Contrat :
    // Aucun contrat.

//----------------------------------------------------- Attributs protégés

    map<string, map<string, int> > graph;
    map<string, int> topTen;
};

//-------------------------------- Autres définitions dépendantes de <Data>

#endif // DATA_H

