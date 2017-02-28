/*-------------------------------------------------------------------------------------------------------*/
/* DEFINES */
/*-------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------*/
/* INCLUDES */

#include <iostream>
#include <vector>
#include <string>
#include <cstdarg>
#include "record.h"
#include "table.h"
using namespace TABLE;
/*-------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------*/
/* FUNCION DEFINITIONS FOR CLASS: TABLE */

/*
	Table::Table() {
		tuples.clear();
		attributes.clear();
		key = "";
	}
*/
	Table::Table(int rows, int columns) {
		attributes.clear();
		tuples.clear();
		RECORD::Record null(columns);
		for (int i = 0; i < rows; i++) {
			tuples.push_back(null);
		}
		key = "";
		attributes.clear();
	}

	Table::Table(char* arg, ...) {
		char* attrChar;
		string attribute;
		int index;
		va_list args;
		va_start(args, arg);
		
		while ((attrChar = va_arg(args, char*)) != NULL) {
			attribute = attrChar;
			attributes.push_back(attribute);
		}
		va_end(args);
		key = "";
	}

	void Table::addAttribute(string attributeName) {
		attributes.push_back(attributeName);
		int index = attributes.size() - 1;
		for (int i = 0; i < tuples.size(); i++) {
			tuples.at(i).set(index, "NULL");
		}
	}

	void Table::deleteAttribute(string attributeName) {
		bool check = false;
		int index = 0;
		for (int i = 0; i < attributes.size(); i++) {
			if (attributes.at(i) == attributeName) {
				attributes.erase(attributes.begin() + i);
				index = i;
				check = true;
				break;
			}
		}
		if (check == false) {
			cout << "Unable to find the attribute to be deleted." << endl;
		}
		else {
			for (int j = 0; j < tuples.size(); j++) {
				tuples.at(j).erase(index);
			}
		}
	}
	void Table::insert(RECORD::Record newRow) {
		tuples.push_back(newRow);
	}
	vector<string> Table::getAttributes() {
		return attributes;
	}
	int Table::size() {
		return tuples.size();
	}

	void Table::specifyKey(string attributeKey) {
		key = attributeKey;
	}

	string Table::returnKey() {
		return key;
	}

	Table Table::crossJoin(Table t1, Table t2) {
		Table null(0,0);
		return null;
	}

	Table Table::naturalJoin(Table t1, Table t2) {
		Table null(0,0);
		return null;
	}

	int Table::count(string attributeName) {
		int index;
		bool check = false;
		int count = 0;
		for (int i = 0; i < attributes.size(); i++) {
			if (attributes.at(i) == attributeName) {
				check = true;
				index = i;
				break;
			}
		}
		if (check) {
			for (int j = 0; j < tuples.size(); j++) {
				if (tuples.at(j).at(index) != "NULL" && tuples.at(j).at(index) != "") {
					count++;
				}
				else {
					count = count + 0;
				}
			}
		}
		else {
			cout << "ERROR: Attribute not found." << endl;
			count = -1;
		}
		return count;
	}
	int Table::max(string attributeName) {
		int index;
		bool check = false;
		int max = 0;
		int currentVal;
		for (int i = 0; i < attributes.size(); i++) {
			if (attributes.at(i) == attributeName) {
				check = true;
				index = i;
				break;
			}
		}
		if (check) {
			for (int j = 0; j < tuples.size(); j++) {
				currentVal = stoi(tuples.at(j).at(index));
				if (currentVal > max) {
					max = currentVal;
				}
				else {
					max = max;
				}
			}
		}
		else {
			cout << "ERROR: Attribute not found." << endl;
			max = -1;
		}
		return max;
	}
	int Table::min(string attributeName) {
		int index;
		bool check = false;
		int min = 2147483647;
		int currentVal;
		for (int i = 0; i < attributes.size(); i++) {
			if (attributes.at(i) == attributeName) {
				check = true;
				index = i;
				break;
			}
		}
		if (check) {
			for (int j = 0; j < tuples.size(); j++) {
				currentVal = stoi(tuples.at(j).at(index));
				if (currentVal < min) {
					min = currentVal;
				}
				else {
					min = min;
				}
			}
		}
		else {
			cout << "ERROR: Attribute not found." << endl;
			min = -1;
		}
		return min;
	}

