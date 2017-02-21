#include "stdafx.h"
#include "database.h"

void Database::add_table(std::string name, Table t)
{
}

void Database::drop(std::string name)
{
}

std::vector<std::string> Database::list_table_names()
{
	return std::vector<std::string>();
}

std::vector<Table> Database::get_tables()
{
	return std::vector<Table>();
}

Table Database::query(std::string select, std::string from, std::string where)
{
	return Table();
}
