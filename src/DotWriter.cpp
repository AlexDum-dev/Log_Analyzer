/*************************************************************************
                           DotWriter  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

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
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void DotWriter::GenererGraphe (Data d, string nomFichier )
{
    ofstream OutputFile(nomFichier.c_str());
    OutputFile << "digraph {" << endl;
    map<string, map<string, int> >::iterator it; // = d.graph.begin();
    unsigned int nbNode = 0;
    vector <string> noeuds;
    
    for (it = d.graph.begin(); it != d.graph.end(); it++)
    {
        OutputFile << "node" << nbNode << "[label=\"" << it->first << "\"];" << endl;
        nbNode++;
        noeuds.push_back(it->first);
    }
    
    nbNode = 0;
    
    for (it = d.graph.begin(); it != d.graph.end(); it++)
    {
        map<string, int>::iterator it2 = it->second.begin();
        
        for (it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            OutputFile << "node" << nbNode << " -> node";
            string cible = it2->first;
            unsigned int node = 0;
            /*
            while (noeuds.at(node)!=cible)
            {
                node++;
            }
            */
            OutputFile << node << " [label=\"" << it2->second << "\"];" << endl;
        } 
        nbNode++;

    }

    OutputFile << "}";
} 


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

DotWriter::DotWriter ( )
// Algorithme :
//
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


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

