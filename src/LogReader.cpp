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
    string urlLocal = "intranet-if.insa-lyon.fr";
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
    std::getline(*this,tmp, ' ');
    std::getline(*this,tmp, ' ');
    res.SetStatus(stoi(tmp));
    std::getline(*this,tmp, '"');
    res.SetQuantity(stoi(tmp));
    std::getline(*this, tmp, '/');
    std::getline(*this, tmp, '/');
    std::getline(*this, tmp, '/');
    if(tmp == urlLocal)
    {
        string ref;
        std::getline(*this, ref, '"');
        res.SetReferer("/" + ref);
    } else 
    {
        tmp = "http://" + tmp; //l'adresse n'est pas locale on veut garder tout l'url
        string tmp2;
        std::getline(*this,tmp2,'"');
        tmp = tmp + tmp2;
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

LogReader::LogReader(string nomFichierLog) : ifstream(nomFichierLog.c_str())
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

