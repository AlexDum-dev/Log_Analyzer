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
#include <string>;
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef enum typeHttp typeHttp;

enum typeHttp
{
    GET,POST,OPTIONS,PUT,HEAD, DELETE, PATCH
};
//------------------------------------------------------------------------
// Rôle de la classe <LogLineReader>
//
//
//------------------------------------------------------------------------

class LogLineReader : 
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
    typeHttp GetTypeRequest();
    string GetUrl();
    int GetStatus();
    int GetQuantity();
    string GetReferer();
    string GetUserAuthentification();

    string SetIp();
    string SetDateTime();
    typeHttp SetTypeRequest();
    string SetUrl();
    int SetStatus();
    int SetQuantity();
    string SetReferer();
    string SetUserAuthentification();
    


//------------------------------------------------- Surcharge d'opérateurs
    Xxx & operator = ( const Xxx & unXxx );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Xxx ( const Xxx & unXxx );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Xxx ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Xxx ( );
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
    typeHttp typeRequest;
    string url;
    int satus;
    int quantity;
    int status;
    int quantity;
    string referer;
    string userAthentification;

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // LogLineReader_H

