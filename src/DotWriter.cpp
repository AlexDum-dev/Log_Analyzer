//---------- Réalisation de la classe <DotWriter> (fichier DotWriter.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
#include <cstring> 
#include <utility>
#include <vector> 
#include <map>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "DotWriter.h"
#include "Data.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void DotWriter::GenererGraphe (Data d, string nomFichier)
//Algorithme : 
//Itère sur tous les referer et cible de la map pour les ajouter commme noeud dans le fichier dot
//Puis itère sur tous les referer pour trouver à quelle cible il est lié et quel est le poids de cette arête
//Respecte la syntaxe précise d'un fichier .dot
{
    ofstream OutputFile(nomFichier.c_str());
    OutputFile << "digraph {" << endl;
    map<string, map<string, int> >::iterator it; // = d.graph.begin();
    map <string, string> sommets;
    unsigned int numSommet = 0;
    
    for (it = d.graph.begin(); it != d.graph.end(); it++)
    {
        map<string, int>::iterator it2 = it->second.begin();

        if (sommets.insert({it->first,"node"+ to_string(numSommet)}).second)
        {
            numSommet++;
        } 
        
        for (it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            if (sommets.insert({it2->first,"node"+ to_string(numSommet)}).second)
            {
                numSommet++;
            } 
        }
    }

    map <string, string>::iterator sommet;
    for (sommet = sommets.begin(); sommet != sommets.end(); sommet++)
    {
        OutputFile << sommet->second << " [label=\"" << sommet->first << "\"];" << endl;
    }
    
    
    for (it = d.graph.begin(); it != d.graph.end(); it++)
    {
        map<string, int>::iterator it2 = it->second.begin();
        
        for (it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            OutputFile << sommets[it->first] << " -> " << sommets[it2->first] << " [label=\"" << it2->second << "\"];" << endl;
        }

    }
    

    OutputFile << "}";
} 


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

DotWriter::DotWriter ()
{
#ifdef MAP
    cout << "Appel au constructeur de <DotWriter>" << endl;
#endif
} //----- Fin de DotWriter


DotWriter::~DotWriter ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <DotWriter>" << endl;
#endif
} //----- Fin de ~DotWriter