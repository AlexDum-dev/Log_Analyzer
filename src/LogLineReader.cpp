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

typeHttp LogLineReader::GetTypeRequest()
{
    return  typeRequest;
}

string LogLineReader::GetUrl()
{
    return url;
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

typeHttp LogLineReader::SetTypeRequest()
{
    return  typeRequest;
}

string LogLineReader::SetUrl()
{
    return url;
}

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
Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Xxx::Xxx ( const Xxx & unXxx )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif
} //----- Fin de Xxx (constructeur de copie)


Xxx::Xxx ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Xxx>" << endl;
#endif
} //----- Fin de Xxx


Xxx::~Xxx ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
} //----- Fin de ~Xxx


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

