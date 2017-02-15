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
using namespace TABLE;
/*-------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------*/
/* FUNCION DEFINITIONS FOR CLASS: TABLE */


	
	Table::Table(int rows, int columns) {
		std::cout << "Table constructor." << endl;
	}

	void Table::addAttribute(string attributeName) {

	}
	void Table::deleteAttribute(string attributeName) {

	}
	void Table::insert(RECORD::Record newRow) {

	}
	vector<string> Table::getAttributes() {
		vector<string> null;
		return null;
	}
	int Table::size() {
		return 0;
	}
	void Table::specifyKey(string attributeKey) {

	}

	void Table::crossJoin(Table t1, Table t2) {

	}
	void Table::naturalJoin(Table t1, Table t2) {

	}
	int Table::count(string attributeName) {
		return 0;
	}
	int Table::max(string attributeNam) {
		return 0;
	}
	int Table::min(string attributeNam) {
		return 0;
	}

