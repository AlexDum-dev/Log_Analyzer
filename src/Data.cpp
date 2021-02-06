//---------- Réalisation de la classe <Data> (fichier Data.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include "LogLineReader.h"
#include <vector>
#include <algorithm>
#include <iterator>


//------------------------------------------------------ Include personnel
#include "Data.h"

bool cmp(pair<string, int>& a, pair<string, int>& b)
{ 
    return a.second > b.second; 
} 

map<string, map<string, int> > Data::GetGraph()
{
    return graph;
}

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
}




void Data::AfficheTopTen()
{
    remplirTopTen();
   
   //Sort using a vector : 
    vector<pair<string, int> > tmp; 
    map<string,int>::iterator it;
    for (it = topTen.begin(); it != topTen.end(); it++) { 
        tmp.push_back(*it); 
    } 
  
    sort(tmp.begin(), tmp.end(), cmp);
    
    //Affichage :
    //vector<pair<string, int>>::iterator itV;
    for(size_t i=0; i<10 and i<tmp.size();i++)
    {
        cout << tmp[i].first << " (" << tmp[i].second << " hits)" << endl; 
    }
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

void Data::remplirTopTen()
{
    map<string,map<string,int> >::iterator it;
    map<string,int>::iterator it2;
    for(it = graph.begin(); it != graph.end(); it++)
    {
        for(it2 = it->second.begin(); it2 != it->second.end();it2++)
        {
            if(topTen.find(it2->first) != topTen.end())
            {
                topTen[it2->first] += it2 -> second;
            } else
            {
                //topTen.insert(*it2);
                topTen.insert({it2->first,it2->second});
            }
        }
    }
}