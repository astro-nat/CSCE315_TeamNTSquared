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




	Database::Database() {

	}
	void Database::addTable(string name, TABLE::Table t1) {

	}
	void Database::dropTable(string name) {

	}
	vector<string> Database::listTables() {
		vector<string> null;
		return null;
	}
	vector<TABLE::Table> Database::getTables() {
		vector<TABLE::Table> null;
		return null;
	}
	TABLE::Table Database::Query(string SELECT, string FROM, string WHERE) {
		TABLE::Table null;
		return null;
	}