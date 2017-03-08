#pragma once

/*-------------------------------------------------------------------------------------------------------*/
/* DEFINES */

#ifndef TABLE_H
#define TABLE_API __declspec(dllexport)
#else 
#define TABLE_API __declspec(dllimport)
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

namespace TABLE {

	class Table {
	private:
		string key;
		vector<string> attributes;
		vector<RECORD::Record> tuples;
		
	public:
		//TABLE_API Table();
		TABLE_API Table(int rows = 0, int columns = 0);

		TABLE_API Table(vector<string> attr);

		TABLE_API void addAttribute(string attributeName);
		TABLE_API void deleteAttribute(string attributeName);
		TABLE_API void insert(RECORD::Record newRow);
		TABLE_API vector<string> getAttributes();
		TABLE_API int size();
		TABLE_API void specifyKey(string attributeKey);
		TABLE_API string returnKey();
		TABLE_API Table crossJoin(Table t1, Table t2);
		TABLE_API Table naturalJoin(Table t1, Table t2);
		TABLE_API int count(string attributeName);
		TABLE_API int max(string attributeName);
		TABLE_API int min(string attributeName);

		typedef vector<RECORD::Record>::iterator recordItr;
		TABLE_API recordItr begin() { return tuples.begin(); }
		TABLE_API recordItr end() { return tuples.end(); }

		
		TABLE_API vector<string>::iterator attrBegin() { return attributes.begin(); }
		TABLE_API vector<string>::iterator attrEnd() { return attributes.end(); }
	};
}
