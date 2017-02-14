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


namespace DATABASE {

	class Database {
	private:
		vector<TABLE::Table> data;
	public:
		Database();
		void addTable(string name, TABLE::Table t1);
		void dropTable(string name);
		vector<string> listTables();
		vector<TABLE::Table> getTables();
		TABLE::Table Query(string SELECT, string FROM, string WHERE);
	};

}