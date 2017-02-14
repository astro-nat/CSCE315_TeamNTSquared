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

namespace TABLE {

	class Table {
	private:
		vector<string> attributes;
		vector<RECORD::Record> tuples;
	public:
		Table(int rows = 0, int columns = 0);
		template<typename first, typename ... Strings>
		Table(first arg0, const Strings& ... args) {
			// DO NOTHING
		}
		vector<RECORD::Record>::iterator recordItr;
		void addAttribute(string attributeName);
		void deleteAttribute(string attributeName);
		void insert(RECORD::Record newRow);
		vector<string> getAttributes();
		int size();
		void specifyKey(string attributeKey);
		void crossJoin(Table t1, Table t2);
		void naturalJoin(Table t1, Table t2);
		int count();
		int max();
		int min();
	};
}