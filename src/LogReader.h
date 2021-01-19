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
#include <string>;
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
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	LogLineReader NextLine();
    


//-------------------------------------------- Constructeurs - destructeur
 

   LogReader(char * nomFichierLog);
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

