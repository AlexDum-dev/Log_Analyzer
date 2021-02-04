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
#include <string>
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "LogReader.h"
#include "LogLineReader.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//

LogLineReader LogReader::NextLine()
{
    
    LogLineReader res;
    string tmp;
    string urlLocal = "http://intranet-if.insa-lyon.fr";
    std::getline(*this,tmp, ' ');
    res.SetIp(tmp);
    std::getline(*this,tmp,'[');
    std::getline(*this,tmp, ']');
    res.SetDateTime(tmp);
    (*this).get();
    (*this).get();
    std::getline(*this,tmp, ' ');
    res.SetTypeRequest(tmp);
    std::getline(*this,tmp, ' ');
    res.SetCible(tmp);
    std::getline(*this,tmp, '"');
    std::getline(*this,tmp, ' ');
    res.SetStatus(tmp);
    std::getline(*this,tmp, '"');
    res.SetQuantity(tmp);

    std::getline(*this, tmp, '"');
    cout << "tmp : " << tmp << endl;
    if(tmp.find(urlLocal) != string::npos)
    {
        size_t position = tmp.find(urlLocal);
        tmp = tmp.substr(position+urlLocal.size(), tmp.size());
        res.SetReferer(tmp);
        
    } else 
    {
        res.SetReferer(tmp);
    }
    (*this).get();
    (*this).get();
    std::getline(*this, tmp, '"');
    res.SetUserAuthentification(tmp);
    (*this).get(); //consomme le retour à la ligne

    return res;
}

	
//-------------------------------------------- Constructeurs - destructeur

LogReader::LogReader(const char* nomFichierLog) : ifstream(nomFichierLog)
{
#ifdef MAP
    cout << "Appel au constructeur de <LogReader>" << endl;
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

