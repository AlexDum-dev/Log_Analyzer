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

