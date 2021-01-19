#include <iostream>
#include <cstring>
#include "LogReader.h"

using namespace std;

int main(int argc, char *argv[])
{
    Statistiques stat;
    LogReader LR(argv[argc-1]);

    enleverImages();
    optionHeure();



    return 0;
}

//decomposer pour renvoyer des messages d erreur qui decrivent le pb


bool enleverImages (){

    for (int i=1; i<argc-1; i++){ //rq : argv[0] contient "./main" donc on le compte pas

        if (strcmp(argv[i],"-e") == 0){
            return 1;
        }
    }

    return 0;
}



bool optionHeure (){

        for (int i=1; i<argc-1; i++){ //rq : argv[0] contient "./main" donc on le compte pas

                        if (stcrmp(argv[i],"-t") == 0){

                                char* aa = argv[i+1]
                                int heure = aa[0]-'0'; //

                        return 1;
                        }
          }

        return 0;

}
