//---------- Interface de la classe <DotWriter> (fichier DotWriter.h) ----------------
#if ! defined ( DOTWRITER_H )
#define DOTWRITER_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring> 
#include"Data.h" 



//------------------------------------------------------------------------
// Rôle de la classe <DotWriter>
// Classe permettant d'écrire dans une fichier .dot (avec un syntaxe précise)
// un graphe.
//------------------------------------------------------------------------

class DotWriter
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
 
    void GenererGraphe (Data  d , string nomFichier);
    //Mode d'emploi : 
    //Permet d'écrire dans un fichier .dot le graphe attribut du paramètre d type data  
    //


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    DotWriter ( );
    

    virtual ~DotWriter ( );
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <DotWriter>

#endif // DOTWRITER_H

