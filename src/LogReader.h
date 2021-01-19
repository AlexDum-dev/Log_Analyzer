/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <LogReader> (fichier LogReader.h) ----------------
#if ! defined ( LOGREADER_H )
#define LOGREADER_H

//--------------------------------------------------- Interfaces utilisées
#include "LogLineReader.h"
#include "fstream"
#include <string>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types


//------------------------------------------------------------------------
// Rôle de la classe <LogLineReader>
//
//
//------------------------------------------------------------------------

class LogReader : public ifstream
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
	LogLineReader NextLine();
    //Mode d'emploi : 
    //
    //Contrat : 
    //
    


//-------------------------------------------- Constructeurs - destructeur
 

   LogReader(string nomFichierLog);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~LogReader ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // LogReader_H

