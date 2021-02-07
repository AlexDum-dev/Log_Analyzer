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
// Rôle de la classe <LogReader>
// Classe objet, gère la création des LogLineReader et l'initialisation de ses
// attributs en passant pas les setters
//
//------------------------------------------------------------------------

class LogReader : public ifstream
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	LogLineReader NextLine();
    //Mode d'emploi :
    // Créer un object LogLineReder et initialise ses attributs. Retourne l'object crée dans le main
    //Contrat : sans
    //



//-------------------------------------------- Constructeurs - destructeur


   LogReader(const char* nomFichierLog);
    // Mode d'emploi :
    // Constructeurs de l'object LogReader, prend en entrée le nom du fichier à analyser et l'ouvre avec ifstream
    // Contrat : sans
    //

    virtual ~LogReader ( );
    // Mode d'emploi :
    // Detructeur de LogReader
    // Contrat : sans
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés


};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // LogReader_H
