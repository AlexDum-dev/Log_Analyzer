/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <LogReader> (fichier LogReader.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LogReader.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//

LogLineReader LogReader::NextLine(){
	
	
}


// //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LogReader>" << endl;
     
    LogReader::LogReader(char * nomFichierLog) : ifstream(nomFichierLog){
		 

	
	 }
    
#endif
} //----- Fin de Xxx


LogReader::~LogReader ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LogReader>" << endl;
#endif
} //----- Fin de ~Xxx


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

