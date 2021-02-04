/*************************************************************************
                           DotWriter  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <DotWriter> (fichier DotWriter.h) ----------------
#if ! defined ( DOTWRITER_H )
#define DOTWRITER_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring> 
#include"Data.h" 

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DotWriter>
//
//
//------------------------------------------------------------------------

class DotWriter
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void GenererGraphe (Data  d , string nomFichier);


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    DotWriter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~DotWriter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <DotWriter>

#endif // DOTWRITER_H

