/*-------------------------------------------------------------------------------------------------------*/
/* DEFINES */
/*-------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------*/
/* INCLUDES */

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
		if (data.at(i).returnKey == name)
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


// HELPER FUNCTION FOR Query
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

// SELECT input format: "'FirstArg' 'Second ARG' [...] 'Last arg'" 
// Comma deliminated
TABLE::Table Database::Query(string SELECT, string FROM, string WHERE){
	TABLE::Table newTable;
	vector<string> selectArgs;
	for (int i = 0; i < SELECT.size(); i++)
	{

		if (SELECT.size() == 1 && SELECT == "*")
		{
			//add all attribute names to table
		}
		else
		{
			selectArgs = separateAtApostrophe(SELECT);
		}

	}



	return newTable;
}