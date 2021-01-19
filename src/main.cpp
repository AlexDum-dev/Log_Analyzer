#include "LogLineReader.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){

	LogLineReader lrd;
	ifstream fic("test.log");
	fic >> lrd;
	
	cout << lrd.GetReferer() << endl;
	cout << lrd.GetCible() << endl;
	return 0;
}
