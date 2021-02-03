//---------- Réalisation de la classe <Data> (fichier Data.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include "LogLineReader.h"

//------------------------------------------------------ Include personnel
#include "Data.h"


//------------------------------------------------------------- Constantes
void Data::Adapt(LogLineReader llr)
{
    //Adaptation du graphe : 
    if(graph[llr.GetReferer()].find(llr.GetCible()) != graph[llr.GetReferer()].end()) //s'il ne trouve pas alors find renvoie une itérateur sur end
    {
        graph[llr.GetReferer()][llr.GetCible()] =  graph[llr.GetReferer()][llr.GetCible()] + 1; //s'il exite déjà l'arête alors on incrémente le poids
    } else 
    {
        graph[llr.GetReferer()].insert({llr.GetCible(), 1}); //Dans le cas où il n'y a pas l'arête, je la créée
    }

    //Adaptation du top ten : 
    
    

}
//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur

Data::Data ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Data>" << endl;
#endif
} //----- Fin de Data


Data::~Data ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
} //----- Fin de ~Data


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

