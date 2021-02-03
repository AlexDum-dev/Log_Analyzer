#include <iostream>
#include <cstring>
#include "LogReader.h"
#include "Data.h"
#include "LogLineReader.h"
using namespace std;

bool enleverImages(int argc, char* argv[]);
bool optionHeure(int argc, char* argv[]);
bool genererGraph(int argc, char* argv[]);
bool error = false; //Traque erreur

int main(int argc, char *argv[])
{
  string nameFicLog(argv[argc-1]);
  LogReader logReader(nameFicLog);
  Data data;

  while(!logReader.eof())
  {
      LogLineReader llr = logReader.NextLine();
      if(enleverImages(argc, argv) and llr.GetCible().find(".css") != -1  and llr.GetCible().find(".png") and llr.GetCible().find(".jpg")  and llr.GetCible().find(".svg") and llr.GetCible().find(".js") and llr.GetCible().find(".gif") and llr.GetCible().find(".bmp") and llr.GetCible().find(".tiff") and llr.GetCible().find(".jpeg"))
      {
        continue;
      }

      if(optionHeure(argc, argv) and llr.GetDateTime().substr(llr.GetDateTime().find(":"),llr.GetDateTime().find(":")+2) == "10")
      {
        continue;
      }
      data.Adapt(llr); //-> adapter le top 10 ainsi que le graphe


  }



  //Statistiques stat;
  //LogReader LR(argv[argc-1]);
  enleverImages(argc, argv);
  optionHeure(argc, argv);
  bool generGraph = genererGraph(argc, argv);

 if(error){
    cout << "Erreur dans la saisie des paramètres, fin du programme." << endl;
    return 1;
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
				int heure = atoi(aa);
        cout << heure << endl;
        if(heure >= 24){
          cout << "Erreur : l'heure est trop grande!" << endl;
          error = true;
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
        char* nomGraph = argv[i+1];
        cout << nomGraph << endl;
        int size=0;
        while(nomGraph[size]!='\0') size++; //Compte nombre caractère
        if(nomGraph[size-1]!='t' && nomGraph[size-2]!='o' && nomGraph[size-3]!='d' && nomGraph[size-4]!='.'){
          error = true;
          cout << "Erreur, le fichier graph ne porte pas la bonne extension (.dot)." << endl;
          return 0;
        }
        //cout << "Taille : " << size << endl;
			  return 1;
			}
	  }

	return 0;
}
