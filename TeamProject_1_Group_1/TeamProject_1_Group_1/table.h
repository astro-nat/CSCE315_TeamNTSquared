#pragma once

/*-------------------------------------------------------------------------------------------------------*/
/* DEFINES */

#ifndef TABLE_H
#define TABLE_declspec(dllexport)
#else 
#define TABLE_declspec(dllimport)
#endif 
/*-------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------*/
/* INCLUDES */

#include <vector>
#include <string>
#include "record.h"
/*-------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------*/
/* CLASS DEFINITIONS */

namespace Table

class Table {
private:
	vector<string> attributes;
	vector<Record> tuples; 
public:
	vector<Record>::iterator recordItr;
	Table(int rows = 0, int columns = 0);
	template<typedef ... Strings>
	Table(const Strings& ... args);
	void addAttribute(string attributeName);
	void deleteAttribute(string attributeName);
	void insert(Record newRow);
	vector<string> getAttributes();
	int size();
	void specifyKey(string attributeKey);
	void crossJoin(Table t1, Table t2);
	void naturalJoin(Table t1, Table t2);
	int count();
	int max();
	int min();
};