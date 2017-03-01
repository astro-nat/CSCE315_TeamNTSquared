/*-------------------------------------------------------------------------------------------------------*/
/* DEFINES */
/*-------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------*/
/* INCLUDES */

#include <iostream>
#include <vector>
#include <string>
#include "record.h"
#include "table.h"
#include "database.h"
using namespace DATABASE;
/*-------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------*/
/* FUNCION DEFINITIONS FOR CLASS: DATABASE */

int Database::indexAtName(string name)
{
	int index = 0;
	for (int i = 0; i < data.size(); i++)
	{
		if (data.at(i).returnKey() == name)
		{
			return index;
		}
		else
		{
			index++;
		}
	}
	return index;
}

Database::Database() {
}

void Database::addTable(string name, TABLE::Table t1) {
	int index;
	data.push_back(t1);
	index = data.size() - 1;
	data.at(index).specifyKey(name);
}

void Database::dropTable(string name) {
	data.erase((data.begin() + indexAtName(name)) - 1);
}


vector<string> Database::listTables() {
	vector<string> table_list;
	for (int i = 0; i < data.size(); i++) {
		table_list.push_back(data.at(i).returnKey());
	}
	return table_list;
}
vector<TABLE::Table> Database::getTables() {
	return data;
}


// HELPER FUNCTIONS FOR Query
vector<string> separateAtApostrophe(string input) {
	vector<string> output;
	int index1;
	//int index2;
	int size;
	bool ready = false;
	for (int i = 0; i < input.size(); i++) {
		if (input.at(i) == '\'' && ready == false) {
			index1 = i + 1;
			ready = true;
		}
		else if (input.at(i) == '\'' && ready == true) {
			size = i - index1;
			output.push_back(input.substr(index1, size));
			ready = false;
		}
		else {
			// KEEP GOING
		}
	}
	return output;
}



// CHECK WHERE
bool checkWhere(string test, string WHERE) {

	Parser parser;
	const char* store = { test.c_str() };

	parser.parse(store);

	return true;
}

// SELECT input format: "'FirstArg' 'Second ARG' [...] 'Last arg'" 
// Comma deliminated
TABLE::Table Database::Query(string SELECT, string FROM, string WHERE){
	TABLE::Table nullTable;
	TABLE::Table newTable;
	RECORD::Record newRecord;
	RECORD::Record temp;
	TABLE::Table searchTable;
	bool found = false;
	vector<string> selectArgs;
	vector<string>::iterator attrItr;
	vector<int> attributeIndexes;
	int j = 0;
	typedef vector<RECORD::Record>::iterator recordItr;
	recordItr recordIterator;
	int recordIndex;
	
	for (int i = 0; i < data.size(); i++) {
		if (data.at(i).returnKey() == FROM) {
			searchTable = data.at(i);
			found = true;
			break;
		}
	}

	if (!found) {
		std::cout << "EROOR: Table not found. \n";
		return nullTable;
	}
	
	else {
		if (SELECT.size() == 1 && SELECT == "*") {
			selectArgs = searchTable.getAttributes();
		}

		else if (SELECT.size() == 1 && SELECT != "*") {
			cout << "ERROR: Invalid SELECT statement. \n";
			return nullTable;
		}
		else {
			selectArgs = separateAtApostrophe(SELECT);
		}
		for (int k = 0; k < selectArgs.size(); k++) {
			newTable.addAttribute(selectArgs.at(k));
		}
		attrItr = searchTable.attrBegin();
		while (attrItr != searchTable.attrEnd()) {
			if (*attrItr == selectArgs.at(j)) {
				attributeIndexes.push_back(j);
			}
			j++;
			attrItr++;
		}
		recordIterator = searchTable.begin();
		while (recordIterator != searchTable.end()) {
			
			recordIndex = 0;
			for (int t = 0; t < attributeIndexes.size(); t++) {
				temp.set(recordIndex, recordIterator->at(attributeIndexes.at(t)));
				recordIndex++;
			}

			RECORD::Record newRec(temp.size());
			// CHECK WITH WHERE
			for (int x = 0; x < temp.size(); x++) {
				if (checkWhere(temp.at(x), WHERE)) {
					newRec.set(x, temp.at(x));
				}
			}

			newTable.insert(newRec);

			for (int s = (temp.size() - 1); s >= 0; s++) {
				temp.erase(s);
				newRec.erase(s);
			}
			recordIterator++;
		}
	}

	return newTable;
}