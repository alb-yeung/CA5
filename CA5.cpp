
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include "requirements.h"

using namespace std;

int main(int argc, char* argv[]){

	//argv[1] is the requirement file
	requirements requirements;

	//open file in read mode
	ifstream infile;
	infile.open(argv[1]);

	string tag;

	while(!infile.eof()){
		cin >> tag;
		if(tag == "TOTAL"){
			int t;
			cin >> t;
			requirements.total(t);
		}
		if(tag == "CREDIT"){
			char type;
			int num;
			cin >> type >> num;
			requirements.credit(type, num);
		}
		if(tag == "COURSE"){
			string name;
			char type;
			string next;
			vector<string> prereqs;

			cin >> name >> type >> next;
			
			while(next != "TOTAL" || next != "CREDIT" || next != "COURSE" || next != "CHOOSE"){
				prereqs.push_back(next);
				//next = infile.peek();
				cin >> next;
				cout << next << endl;
			}

			requirements.course(name, type, prereqs);
		}
		if(tag == "CHOOSE"){
			requirements.choose();
		}
	}
	
	infile.close();
}
