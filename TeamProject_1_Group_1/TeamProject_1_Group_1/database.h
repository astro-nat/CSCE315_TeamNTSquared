#pragma once

/*-------------------------------------------------------------------------------------------------------*/
/* DEFINES */

#ifndef DATABASE_H
#define DATABASE_API __declspec(dllexport)
#else 
#define DATABASE_API __declspec(dllimport)
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
		DATABASE_API Database();
		DATABASE_API void addTable(string name, TABLE::Table t1);
		DATABASE_API void dropTable(string name);
		DATABASE_API vector<string> listTables();
		DATABASE_API vector<TABLE::Table> getTables();
		DATABASE_API TABLE::Table Query(vector<string>SELECT, string FROM, string WHERE); //changed to vector select
		DATABASE_API int indexAtName(string name); //added extra function for database
	};

}