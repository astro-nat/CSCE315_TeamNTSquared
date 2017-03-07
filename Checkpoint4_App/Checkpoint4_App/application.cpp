#include "ServerAPI.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;



Table createTableFromJson(ifstream infile);

int main() {

}

Table createTableFromJson(ifstream infile){
	string line;
	Table outTable;

	getline(infile, line);

	int index;
	int size; 
	bool check = true;
	string attribute;
	
	// Create the Table with Columns
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == '"' && (line[i - 1] == ',' || line[i - 1] == '"')) {
			index = i + 1;
			check = true;
		}
		else if (line[i] == '"' && check == true) {
			size = i - index;
			check = false;
			attribute = line.substr(index, size);
			outTable.addColumn(attribute);
		}
		else {

		}
	}

	Record outRec(outTable.getAttributes().size());
	string recData;
	check = false;
	bool arrayCheck = false;

	while (!infile.eof()) {
		int recIndex = 0;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '"' && line[i - 1] == ':') {
				index = i + 1;
				check = true;
			}
			else if (line[i] == '[') {
				index = i + 1;
				arrayCheck = true;
			}
			else if (line[i] == '"' && check == true && arrayCheck == false) {
				size = i - index;
				check = false;
				recData = line.substr(index, size);
				outRec[recIndex] = recData;
				recIndex++;
			}
			else if (line[i] == ']' && arrayCheck == true) {
				arrayCheck = false;
				size = i - index;
				recData = line.substr(index, size);
				outRec[recIndex] = recData;
				recIndex++;
			}
			else {

			}
		}
		outTable.insertRecord(outRec);
		getline(infile, line);
	}

	return outTable;
}