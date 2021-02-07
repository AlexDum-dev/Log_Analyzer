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
// Cette classe représente une ligne de log en la décomposant selon ses différents attributs. Classe générale, réutilisable.
//
//------------------------------------------------------------------------

class LogLineReader
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi : getters et setters, pour accéder aux attributs ou les modifier de l'extérieur de la classe.
    

    string GetIp();
    string GetDateTime();
    string GetTypeRequest();
    string GetCible();
    string GetStatus();
    string GetQuantity();
    string GetReferer();
    string GetUserAuthentification();

    void SetIp(string ip);
    void SetDateTime(string dateTime);
    void SetTypeRequest(string typeRequest);
    void SetCible(string cible);
    void SetStatus(string status);
    void SetQuantity(string quantity);
    void SetReferer(string referer);
    void SetUserAuthentification(string userAuthentification);
    
    
//-------------------------------------------- Constructeurs - destructeur

    LogLineReader();
    // Mode d'emploi : constructeur


    virtual ~LogLineReader ( );
    // Mode d'emploi : destructeur
  

//------------------------------------------------------------------ PRIVE

protected:

//----------------------------------------------------- Attributs protégés
    string ip;
    string dateTime;
    string typeRequest;
    string cible;
    string status;
    string quantity;
    string referer;
    string userAthentification;

};

//-------------------------------- Autres définitions dépendantes de <LogLineReader>

#endif // LogLineReader_H

