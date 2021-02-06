#include <iostream>
#include <cstring>
#include "LogReader.h"
#include "Data.h"
#include "LogLineReader.h"
#include "DotWriter.h"
#include "Erreur.h"
using namespace std;

bool enleverImages(int argc, char* argv[]);
bool optionHeure(int argc, char* argv[]);
bool genererGraph(int argc, char* argv[]);
void AnalyseLog(int argc, char * argv[]);
static int heure;
static char* nomGraph;
bool error = false; //Traque erreur

int main(int argc, char *argv[])
{
  try
  {
    genererGraph(argc, argv);
  }
  catch(exception const& e)
  {
    cerr << e.what()<< endl;
    return -1;
  }

  try
  {
    optionHeure(argc, argv);
  }
  catch(const exception& e)
  {
    cerr << e.what() << endl;
    return -1;
  }
  
  LogReader logReader(argv[argc-1]);
  if(!logReader)
  {
    cerr << "Erreur : saisie incorrecte du nom de fichier log" << endl;
    return -1;
  }

  Data data;

  while(!logReader.eof())
  {
      LogLineReader llr = logReader.NextLine();
      if(enleverImages(argc, argv) and (llr.GetCible().find(".css") != string::npos  or llr.GetCible().find(".png")!= string::npos or llr.GetCible().find(".jpg") != string::npos or llr.GetCible().find(".svg") != string::npos or llr.GetCible().find(".js") != string::npos or llr.GetCible().find(".gif") != string::npos or llr.GetCible().find(".bmp") != string::npos or llr.GetCible().find(".tiff") != string::npos or llr.GetCible().find(".jpeg") != string::npos))
      {
        continue;
      }
      size_t pos = llr.GetDateTime().find(":");
      string s = llr.GetDateTime().substr(pos+1,2);

      if(optionHeure(argc, argv) and stoi(s) == heure)
      {
        continue;
      }

      /*
      map<string, map<string, int> > l = data.GetGraph();
      map<string, map<string, int> >::iterator it;
      map<string, int>::iterator it2;

      for(it = l.begin(); it != l.end();it++)
      {
            for(it2 = it -> second.begin();it2 != it -> second.end();it2++)
            {
              cout << "Referer :" << it -> first << " Cible : " << it2 -> first << " " << it2 -> second << " hits" << endl;
            }
      }
      */

      data.Adapt(llr); //-> adapter le top 10 ainsi que le graphe
  }

  data.AfficheTopTen();
  DotWriter d;
  if (genererGraph(argc, argv))
  {
    string nom(nomGraph);
    d.GenererGraphe(data, nom);
  } 
  return 0;
}

//decomposer pour renvoyer des messages d erreur qui decrivent le pb


bool enleverImages (int argc, char* argv[]){

	 for (int i=1; i<argc-1; i++){ //rq : argv[0] contient "./main" donc on le compte pas

			if (strcmp(argv[i],"-e") == 0){
			return 1;
			}
	  }

	return 0;
}



bool optionHeure (int argc, char* argv[]){

	for (int i=1; i<argc-1; i++){ //rq : argv[0] contient "./main" donc on le compte pas
			if (strcmp(argv[i],"-t") == 0){

				char* aa = argv[i+1];
				heure = atoi(aa);
        if(heure >= 24){
          throw Erreur(1, "Erreur : l'heure est trop grande!", 1);
          return 0;
        }
        else
        	return 1;
			}
	  }

	return 0;

}

bool genererGraph (int argc, char* argv[]){

	 for (int i=1; i<argc-1; i++){ //rq : argv[0] contient "./main" donc on le compte pas

			if (strcmp(argv[i],"-g") == 0){
        nomGraph = argv[i+1];
        //cout << nomGraph << endl;
        int size=0;
        while(nomGraph[size]!='\0') size++; //Compte nombre caractère
        if(nomGraph[size-1]!='t' && nomGraph[size-2]!='o' && nomGraph[size-3]!='d' && nomGraph[size-4]!='.'){
          throw Erreur(0,"Erreur, le fichier graph ne porte pas la bonne extension (.dot).",1); 
        }
        //cout << "Taille : " << size << endl;
			  return 1;
			}
	  }

	return 0;
}
