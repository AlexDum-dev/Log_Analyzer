/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <LogLineReader> (fichier LogLineReader.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LogLineReader.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string LogLineReader::GetIp()
{
    return ip;
}

string LogLineReader::GetDateTime()
{
    return dateTime;
}

/*typeHttp LogLineReader::GetTypeRequest()
{
    return  typeRequest;
}
*/

string LogLineReader::GetCible()
{
    return cible;
}

int LogLineReader::GetStatus()
{
    return status;
}

int LogLineReader::GetQuantity()
{
    return quantity;

}

string LogLineReader::GetReferer()
{
    return referer;
}

string LogLineReader::GetUserAuthentification()
{
    return userAthentification;
}

//Setters : 

string LogLineReader::SetIp()
{
    return ip;
}

string LogLineReader::SetDateTime()
{
    return dateTime;
}

/*typeHttp LogLineReader::SetTypeRequest()
{
    return  typeRequest;
}
*/

/*string LogLineReader::SetUrl()
{
    return cible;
}
*/

int LogLineReader::SetStatus()
{
    return status;
}

int LogLineReader::SetQuantity()
{
    return quantity;

}

string LogLineReader::SetReferer()
{
    return referer;
}

string LogLineReader::SetUserAuthentification()
{
    return userAthentification;
}


//------------------------------------------------- Surcharge d'opérateurs
istream & operator >> (istream & in, LogLineReader & unLogLineReader )
// Algorithme :
//
{
    string tmp;
    string urlLocal = "intranet-if.insa-lyon.fr";
    getline(in,unLogLineReader.ip, ' ');
    getline(in,tmp,'[');
    getline(in,unLogLineReader.dateTime, ']');
    in.get();
    in.get();
    getline(in,unLogLineReader.typeRequest, ' ');
    getline(in,unLogLineReader.cible, ' ');
    getline(in,tmp, ' ');
    getline(in,tmp, ' ');
    unLogLineReader.status = stoi(tmp);
    getline(in,tmp, '"');
    unLogLineReader.quantity = stoi(tmp);
    getline(in, tmp, '/');
    getline(in, tmp, '/');
    getline(in, tmp, '/');
    if(tmp == urlLocal)
    {
        getline(in, unLogLineReader.referer, '"');
        unLogLineReader.referer = "/" + unLogLineReader.referer; 
    } else 
    {
        tmp = "http://" + tmp; //l'adresse n'est pas locale on veut garder tout l'url
        string tmp2;
        getline(in,tmp2,'"');
        tmp = tmp + tmp2;
        unLogLineReader.referer = tmp;
    }
    in.get();
    in.get();
    getline(in, unLogLineReader.userAthentification, '"');
    in.get(); //consomme le retour à la ligne
}




LogLineReader::LogLineReader ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LogLineReader>" << endl;
#endif
} //----- Fin de LogLineReader


LogLineReader::~LogLineReader ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
} //----- Fin de ~Xxx


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

