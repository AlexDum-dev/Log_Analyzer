/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <LogLineReader> (fichier LogLineReader.h) ----------------
#if ! defined ( LOGLINEREADER_H )
#define LOGLINEREADER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LogLineReader>
//
//
//------------------------------------------------------------------------

class LogLineReader
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string GetIp();
    string GetDateTime();
    string GetTypeRequest();
    string GetCible();
    int GetStatus();
    int GetQuantity();
    string GetReferer();
    string GetUserAuthentification();

    void SetIp(string ip);
    void SetDateTime(string dateTime);
    void SetTypeRequest(string typeRequest);
    void SetCible(string cible);
    void SetStatus(int status);
    void SetQuantity(int quantity);
    void SetReferer(string referer);
    void SetUserAuthentification(string userAuthentification);
    


//------------------------------------------------- Surcharge d'opérateurs
     friend istream & operator >> (istream & in, LogLineReader & unLogLineReader);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur

    LogLineReader();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~LogLineReader ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string ip;
    string dateTime;
    string typeRequest;
    string cible;
    int status;
    int quantity;
    string referer;
    string userAthentification;

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // LogLineReader_H

