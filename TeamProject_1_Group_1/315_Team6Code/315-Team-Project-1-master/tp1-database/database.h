// Team_Project_1.cpp : Defines the exported functions for the DLL application.


// Database Methods


#include <string>
#include <vector>
#include "table.h"

class __declspec(dllexport) Database
{
	Database ();

	void add_table(std::string name, Table t);

	void drop(std::string name);

	std::vector<std::string> list_table_names();

	std::vector<Table> get_tables();

	Table query(std::string select, std::string from, std::string where);

};
