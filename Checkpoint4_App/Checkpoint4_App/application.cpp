#include "ServerAPI.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int LINE_COUNT = 1000;

Table createTableFromJson(char* filename);

int main() {
	// File Input and Table Creation
	char * jsonIn1 = "yelp_academic_dataset_business.json";
	Table table1(createTableFromJson(jsonIn1));

	char * jsonIn2 = "yelp_academic_dataset_checkin.json";
	Table table2(createTableFromJson(jsonIn2));

	char * jsonIn3 = "yelp_academic_dataset_review.json";
	Table table3(createTableFromJson(jsonIn3));

	char * jsonIn4 = "yelp_academic_dataset_tip.json";
	Table table4(createTableFromJson(jsonIn4));

	char * jsonIn5 = "yelp_academic_dataset_user.json";
	Table table5(createTableFromJson(jsonIn5));

	// Specify Keys
	vector<string> attributes;
	vector<string> keys;

	attributes = table1.getAttributes();
	table1.setAttributeAsKey(attributes.at(0));
	keys.push_back(attributes.at(0));

	attributes = table2.getAttributes();
	table2.setAttributeAsKey(attributes.at(0));
	keys.push_back(attributes.at(0));

	attributes = table3.getAttributes();
	table3.setAttributeAsKey(attributes.at(0));
	keys.push_back(attributes.at(0));

	attributes = table4.getAttributes();
	table4.setAttributeAsKey(attributes.at(0));
	keys.push_back(attributes.at(0));

	attributes = table5.getAttributes();
	table5.setAttributeAsKey(attributes.at(0));
	keys.push_back(attributes.at(0));

}

Table createTableFromJson(char* filename){
	ifstream infile(filename);
	
	string line;
	Table outTable;


	if (infile) {
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

		int lines = 1;
		while (lines <= LINE_COUNT) {
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
			lines++;
			outTable.insertRecord(outRec);
			getline(infile, line);
		}

		return outTable;
	}
	else {
		cerr << "Couldn't open " << filename << " for reading\n";
	}
}