#include "ServerAPI.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int LINE_COUNT = 1000;

Table createTableFromJson(char* filename);
void printTable(Table printTable);
void printRecord(Record printRecord);
void printAttributes(Table printTable);

int main() {

	// File Input and Table Creation
	cout << "Reading files . . . \n";


	// File Input and Table Creation //

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


	cout << "Tables have been loaded \n";

	// Specify Keys

	vector<string> attributes;
	vector<string> keys;

	// Sets attributes and adds to keys //
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


	// Create and populate the database
	cout << "Initializing database . . . \n";

	Database db;

	db.addTable(table1, keys.at(0));
	db.addTable(table2, keys.at(1));
	db.addTable(table3, keys.at(2));
	db.addTable(table4, keys.at(3));
	db.addTable(table5, keys.at(4));

	cout << "Database created.\n";

	Table queryTable;
	Table queryTable2;
	Table queryTable3;

	Table joinTable;
	Table joinTable2;
	//queryTable = db.query( "user_id, name, review_count", keys.at(4), "name > \"\"");

	//printTable(queryTable);
	printAttributes(table1);
	//printRecord(table5[0]);
	bool quit = false;
	string name;
	string whereName;

	string bus_name;

	while (!quit) {
		cout << "Select an action: \n";
		cout << "	1: Get information on a user\n";
		cout << "	2: Get information on a business\n";
		cout << "	3: Combine information.\n";
		cout << "   4: Get summary information of a user.\n";
		cout << "   5: Get summary information on a business.\n";
		cout << "   6: Get active users (high review count\n)";
		cout << "	0: Quit\n";
		cout << "Enter your number: ";
		int selection;
		cin >> selection;

		switch (selection) {
		case 1:
			cout << "Enter the name of the user you want to know about: ";
			cin >> name;
			whereName = "name = \"" + name + "\"";
			queryTable = db.query("user_id, name, review_count", keys.at(4), whereName);
			printTable(queryTable);
			break;
		case 2:
			cout << "Enter the name of the business you want to know about: ";
			cin >> name;
			whereName = "name = \"" + name + "\"";
			queryTable = db.query("business_id, name, type", keys.at(0), whereName);
			printTable(queryTable);
			break;
		case 3:
			cout << "Enter the name of a user whose reviews you would like to know about: ";
			cin >> name;
			whereName = "name = \"" + name + "\"";
			queryTable = db.query("user_id, name, review_count", keys.at(4), whereName); //table 1 = user_id, name, review count
																						 //queryTable2 = db.query("user_id, stars, text", keys.at(2),  );
			break;
		case 4:
			cout << "Enter the name of a user who you would like to see the summary for";
			cin >> name;
			whereName = "name = \"" + name + "\"";
			queryTable = db.query("user_id, name, review_count, average_stars", keys.at(4), whereName);
			printTable(queryTable);
		case 5:
			cout << "Enter the name of a business you'd like to see the summary for: ";
			cin >> name;
			whereName = "name = \"" + name + "\"";
			queryTable = db.query("business_id, name, city, state, stars", keys.at(0), whereName);
			printTable(queryTable);
		case 6:
			//queryTable = db.query("name", keys.at(4), review_count > 10 ); //how to compare it?
		case 0:
			quit = true;
			break;
		default:
			cout << "Improper selection. Try again \n";
			break;
		}
	}

}

void printTable(Table printTable) {
	cout << "Records: \n";
	for (int i = 0; i < printTable.getAttributes().size(); i++) {
		cout << printTable.getAttributes().at(i) << " | " << setw(20);
	}
	cout << "\n";
	cout << "--------------------------------------------------------------------------\n";
	for (int i = 0; i < printTable.getNumRecords(); i++) {
		for (int j = 0; j < printTable[i].getSize(); j++) {
			cout << printTable[i][j] << " | " << setw(20);
		}
		cout << "\n";
		cout << "--------------------------------------------------------------------------\n";
	}


}

void printAttributes(Table printTable) {
	for (int i = 0; i < printTable.getAttributes().size(); i++) {
		cout << printTable.getAttributes().at(i) << " | " << setw(20);
	}
	cout << "\n";
	cout << "-----------------------------------------------------------\n";
}

void printRecord(Record printRecord) {
	for (int i = 0; i < printRecord.getSize(); i++) {
		cout << printRecord[i] << " | " << setw(20);
	}
	cout << "\n";
}

// Creates new table from JSON file
Table createTableFromJson(char* filename) {

	ifstream infile;
	infile.open(filename);

	string line;
	Table outTable;

	cout << "Reading file " << filename << "\n";

	if (infile) {
		getline(infile, line);
		//cout << line.substr(0,1000) << "\n";
		int index;
		int size;
		bool check = true;
		bool arrayCheck = false;
		string attribute;

		// Create the Table with Columns
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '[') {
				arrayCheck = true;
			}
			if (line[i] == ']' && arrayCheck == true) {
				arrayCheck = false;
			}
			if (line[i] == '"' && (line[i - 1] == ',' || line[i - 1] == '{')) {
				index = i + 1;
				check = true;
			}
			else if (line[i] == '"' && check == true && arrayCheck == false) {
				size = i - index;
				check = false;
				attribute = line.substr(index, size);
				outTable.addColumn(attribute);
			}
			else {

			}
		}


		Record outRec(outTable.getAttributes().size() * 2);


		string recData;
		check = false;
		arrayCheck = false;
		char endChar = '\}';
		int recIndex = 0;

		int lines = 1;

		// Limit lines to LINE_COUNT value to prevent crash
		while (lines <= LINE_COUNT) {

			recIndex = 0;


			// Parses through JSON file to collect data and create record

			for (int i = 0; i < line.size(); i++) {

				if (line[i] == '"' && line[i - 1] == ':') {
					index = i + 1;
					endChar = '"';
					check = true;
				}
				else if (line[i] == ':' && endChar != '"') {
					endChar = ',';
					index = i + 1;
					check = true;
				}
				else if (line[i] == '[') {
					index = i + 1;
					arrayCheck = true;
				}
				else if (line[i] == endChar && check == true && arrayCheck == false) {
					endChar = '\}';
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

			// Inserts new record into table
			outTable.insertRecord(outRec);

			getline(infile, line);
		}
		infile.close();
		return outTable;
	}
	else {
		cerr << "Couldn't open " << filename << " for reading\n";
	}
}