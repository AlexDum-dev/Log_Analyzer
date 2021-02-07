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
void analyseNameLog(int  argc,char * argv[]);
void testOption (int argc, char* argv[]);

static int heure;
static char* nomGraph;

int main(int argc, char *argv[])
{
  //Test sur le fichier dot
  try
  {
    genererGraph(argc, argv);
  }
  catch(exception const& e)
  {
    cerr << e.what()<< endl;
    return -1;
  }
  //Test sur le paramètre heure de l'utilisateur 
  try
  {
    optionHeure(argc, argv);
  }
  catch(const exception& e)
  {
    cerr << e.what() << endl;
    return -1;
  }

  //Test sur le nom de fichier log
  try
  {
    analyseNameLog(argc, argv);
  }
  catch(const std::exception& e)
  {
    cerr << e.what() << endl;
    return -1;
  }

  //Test si une option non autorisée a été donnée en paramètre
  try
  {
    testOption(argc, argv);
  }
  catch(exception const& e)
  {
    cerr << e.what()<< endl;
    return -1;
  }
  
  LogReader logReader(argv[argc-1]);
  if(!logReader) //teste si le fichier existe ou peut s'ouvrir
  {
    cerr << "Erreur : saisie incorrecte du nom de fichier log" << endl;
    return -1;
  }

  Data data;

  while(!logReader.eof()) //lit le fichier log
  {
      LogLineReader llr = logReader.NextLine();
      if(enleverImages(argc, argv) and (llr.GetCible().find(".css") != string::npos  or llr.GetCible().find(".png")!= string::npos or llr.GetCible().find(".jpg") != string::npos or llr.GetCible().find(".svg") != string::npos or llr.GetCible().find(".js") != string::npos or llr.GetCible().find(".gif") != string::npos or llr.GetCible().find(".bmp") != string::npos or llr.GetCible().find(".tiff") != string::npos or llr.GetCible().find(".jpeg") != string::npos))
      {
        continue; //on passe à l'itération suivante si on l'option -e et que la ligne comporte des extensions qu'on veut enlever
      }

      size_t pos = llr.GetDateTime().find(":");
      string s = llr.GetDateTime().substr(pos+1,2);

      if(optionHeure(argc, argv) and stoi(s) != heure)
      {
        continue; //passe à  l'itération suivante si on est pas dans l'intervalle d'heure demandé
      }
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


bool enleverImages (int argc, char* argv[])
//Renvoie si l'option -e a été activée
{
	 for (int i=1; i<argc-1; i++){ //rq : argv[0] contient "./main" donc on le compte pas

			if (strcmp(argv[i],"-e") == 0){
			return 1;
			}
	  }

	return 0;
}



bool optionHeure (int argc, char* argv[])
//Analyse le paramètre heurre
//throw une erreur si l'heure est trop grande ou s'il s'agit d'une heure invalide ("aa" par exemple )
{
	for (int i=1; i<argc-1; i++){ //rq : argv[0] contient "./main" donc on le compte pas
			if (strcmp(argv[i],"-t") == 0){

				char* aa = argv[i+1];
				heure = atoi(aa);
        if(heure > 23 or heure < 0){
          throw Erreur(1, "Erreur : l'heure est trop grande!", 1);
          return 0;
        }

        if (((strlen(aa) == 1) and (aa[0] < 48 or aa[0] > 57)) or ((strlen(aa) > 1) and (aa[0] < 48 or aa[0] > 57 or aa[1] < 48 or aa[1] > 57)) or (strlen(aa) > 2))
        {
          throw Erreur(1,"Erreur : l'heure est invalide", 1);
        }
        
        else
        	return 1;
			}
	  }

	return 0;

}

bool genererGraph (int argc, char* argv[])
//Analyse le nom du fichier 
//throw une erreur dans le cas ou l'extension n'est pas bonne ou nom non conforme
{
	 for (int i=1; i<argc-1; i++){ //rq : argv[0] contient "./main" donc on le compte pas

			if (strcmp(argv[i],"-g") == 0){
        nomGraph = argv[i+1];
        int size=0;
        while(nomGraph[size]!='\0') size++; //Compte nombre caractère
        if( size < 4 or nomGraph[size-1]!='t' or nomGraph[size-2]!='o' or nomGraph[size-3]!='d' or nomGraph[size-4]!='.'){
          throw Erreur(0,"Erreur, le fichier graph ne porte pas la bonne extension (.dot)",1); 
        }
			  return 1;
			}
	  }

	return 0;
}

void analyseNameLog(int  argc,char * argv[])
//Anlyse le nom de fichier log
//throw une erreur si l'extension ou si le fichier n'existe pas
{
  int taille = strlen(argv[argc-1]);

  if(taille <= 4 or argv[argc-1][taille-1] != 'g' or argv[argc-1][taille-2] != 'o' or argv[argc-1][taille-3] != 'l' or argv[argc-1][taille-4] != '.')
  {
  throw Erreur(3, "Erreur : saisie incorrecte du nom de fichier log",1);
  }
}

void testOption (int argc, char* argv[])
// Fonction qui analyse si des options non autorisées ont eté fournies :
// throw une erreur dans le cas ou un option non autorisée a été fournie
{
    bool param = false;

     for (int i=1; i<argc-1; i++){ //rq : argv[0] contient "./main" donc on le compte pas

        if (strcmp(argv[i],"-g") != 0 && strcmp(argv[i],"-e") != 0 && strcmp(argv[i],"-t") != 0 && !param){
          throw Erreur(0,"Erreur, mauvais paramètre en entrée",1);
      }
        param = false;
        if(strcmp(argv[i],"-g") == 0 || strcmp(argv[i],"-t") == 0){
            param = true;
        }
      }
}