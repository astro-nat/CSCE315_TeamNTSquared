#include "stdafx.h"
#include "table.h"

Table::Table(std::string attrs[])
{
}

void Table::add(std::string attr)
{
}

void Table::del(std::string attr)
{
}

void Table::insert(Record r)
{
}

std::string * Table::get_attrs()
{
	return nullptr;
}

int Table::size()
{
	return 0;
}

Record * Table::operator[](size_t index)
{
	return nullptr;
}

const Record * Table::operator[](size_t index) const
{
	return nullptr;
}

void Table::cross_join(Table other_table)
{
}

void Table::natural_join(Table other_table)
{
}

int Table::count_attr(std::string attr)
{
	return 0;
}

int Table::min_attr(std::string attr)
{
	return 0;
}

int Table::max_attr(std::string attr)
{
	return 0;
}
