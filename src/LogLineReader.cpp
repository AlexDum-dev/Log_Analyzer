
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

string LogLineReader::GetStatus()
{
    return status;
}

string LogLineReader::GetQuantity()
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

void LogLineReader::SetIp(string uneip)
{
    ip = uneip;
}

void LogLineReader::SetDateTime(string uneDate)
{
    dateTime = uneDate;
}

void LogLineReader::SetTypeRequest(string uneTypeRequest)
{
    typeRequest = uneTypeRequest;
}


void LogLineReader::SetCible(string uneCible)
{
    cible = uneCible;
}


void LogLineReader::SetStatus(string unStatus)
{
    status = unStatus;
}

void LogLineReader::SetQuantity(string uneQuantity)
{
    quantity = uneQuantity;

}

void LogLineReader::SetReferer(string unReferer)
{
    referer = unReferer;
}
    
void LogLineReader::SetUserAuthentification(string uneUserAuthentification)
{
    userAthentification = uneUserAuthentification;
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

