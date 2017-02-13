#pragma once

/*-------------------------------------------------------------------------------------------------------*/
/* DEFINES */

#ifndef DATABASE_H
#define DATABASE_declspec(dllexport)
#else 
#define DATABASE_declspec(dllimport)
#endif 
/*-------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------*/
/* INCLUDES */

#include <vector>
#include <string>
#include "record.h"
#include "table.h"
/*-------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------*/
/* CLASS DEFINITIONS */

namespace Database

class Database {
private:
	vector<Table> data;
public:
	Database();
	void addTable(string name, Table t1);
	void dropTable(string name);
	vector<string> listTables();
	vector<Table> getTables();
	Table Query(string SELECT, string FROM, string WHERE);
};