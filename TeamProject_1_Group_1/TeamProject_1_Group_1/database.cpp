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

TABLE::Table Database::Query(vector<string> SELECT, string FROM, string WHERE) {
	TABLE::Table newTable;

	for (int i = 0; i < SELECT.size(); i++)
	{

		if (SELECT.size() == 1 && SELECT[i] == "*")
		{
			//add all attribute names to table
		}
		else if (SELECT.size() == 1)
		{
			//add attribute SELECT[i] to newTable
		}
		else
		{
			SELECT.push_back(SELECT[i])
		}





		return newTable;
	}