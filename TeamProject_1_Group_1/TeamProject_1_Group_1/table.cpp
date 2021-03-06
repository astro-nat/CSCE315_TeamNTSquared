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
	// Initializes empty table
	Table::Table() {
		tuples.clear();
		attributes.clear();
		key = "";
	}
*/

	// Initializes empty table with specified number of rows and columns
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

	// Initializes empty table with given attributes/columns
	Table::Table(vector<string> attr) {
		for (int i = 0; i < attr.size(); i++) {
			attributes.push_back(attr.at(i));
		}
		tuples.clear();
		key = "";
	}

	// Adds attribute to table
	void Table::addAttribute(string attributeName) {

		attributes.push_back(attributeName);
		int index = attributes.size() - 1;

		// Each value in attribute is initialized to "NULL"
		for (int i = 0; i < tuples.size(); i++) {
			tuples.at(i).set(index, "NULL");
		}
	}

	// Deletes attributes, or column, from table
	void Table::deleteAttribute(string attributeName) {

		bool check = false;
		int index = 0;

		// Searches for attribute with matching name. If found, erase the attribute name
		for (int i = 0; i < attributes.size(); i++) {
			if (attributes.at(i) == attributeName) {
				attributes.erase(attributes.begin() + i);
				index = i;
				check = true;
				break;
			}
		}

		// If attribute not found, print message
		if (check == false) {
			cout << "Unable to find the attribute to be deleted." << endl;
		}

		// If attribute was found, erase all records at given attribute index
		else {
			for (int j = 0; j < tuples.size(); j++) {
				tuples.at(j).erase(index);
			}
		}
	}

	// Inset new record
	void Table::insert(RECORD::Record newRow) {
		tuples.push_back(newRow);
	}

	// Returns attribute/column names
	vector<string> Table::getAttributes() {
		return attributes;
	}

	// Returns number of rows
	int Table::size() {
		return tuples.size();
	}

	// Specifies new table key
	void Table::specifyKey(string attributeKey) {
		key = attributeKey;
	}

	// Returns table key
	string Table::returnKey() {
		return key;
	}

	// Cross joins two tables
	Table Table::crossJoin(Table t1, Table t2) {

		// Multiples sizes of two tables and creates new table, because final size of cross joined table is always size(t1)*size(t2)
		int tableSize = (t1.getAttributes().size() * t2.getAttributes().size());
		Table joinedTable(0, 0);
		
		// Adds attributes from first table to new table
		for (int i = 0; i < t1.getAttributes().size(); i++) {
			joinedTable.addAttribute(t1.getAttributes()[i]);
		}
		// Appends attributes from second table to new table
		for (int j = 0; j < t2.getAttributes().size(); j++) {
			joinedTable.addAttribute(t2.getAttributes()[j]);
		}
		
		// Adds all rows to new table
		for (int i = 0; i < t1.size(); i++) {
			for (int j = 0; j < t2.size(); j++) {

				for (int k = 0; k < tableSize; k++) {

					// Create new record
					RECORD::Record newRecord(tableSize);

					// Sets new record value equal to record in table 1
					for (int m = 0; m < t1.size(); m++) {
						newRecord.set(k, t1.tuples[i].at(m));
					}
					// Appends record value from table 2 to new record
					for (int n = 0; n < t2.size(); n++) {
						newRecord.set(k, t2.tuples[i].at(n));
					}

					// Adds new record to new table
					joinedTable.tuples.push_back(newRecord);
				}
			}
		}
		

		return joinedTable;

	}

	Table Table::naturalJoin(Table t1, Table t2) {
		Table joinedTable(0, 0);

		vector<string>t1_attributes;
		vector<string>t2_attributes;
		t1_attributes = t1.getAttributes();
		t2_attributes = t2.getAttributes();

		int biggerSize;
		int smallerSize;

		if (t1.size() > t2.size()) //get the table with more rows
		{
			biggerSize = t1.size();
			smallerSize = t2.size();
		}
		else
		{
			biggerSize = t2.size();
			smallerSize = t1.size();
		}

		for (int z = 0; z < t1_attributes.size(); z++)
		{
			joinedTable.addAttribute(t1_attributes[z]); //add all the attributes of first table into new table
		}

		for (int z = 0; z < t2_attributes.size(); z++) //add all attributes of second tabe into new table
		{
			joinedTable.addAttribute(t2_attributes[z]); //this will make 2 copies of the same attribute (if they share one). 
		}



		for (int i = 0; i < biggerSize; i++)
		{
			for (int j = 0; j < smallerSize; j++)
			{
				if (t1_attributes[i] == t2_attributes[j]) //if the two columns are the same, begin joining tables
				{
					for (int m = 0; m < biggerSize; m++)
					{
						if (t1.tuples.at(m).at(i) == t2.tuples.at(m).at(j)) //check which rows to join by checking if the content in that row is the same
						{

							joinedTable.tuples.at(m) = t1.tuples.at(m); //add the whole row in table t1 to the new table
							joinedTable.tuples.push_back(t2.tuples.at(m)); //append the matched row in table t2 to the new table

							for (int i = 0; i < joinedTable.size(); i++)
							{
								if (joinedTable.tuples.at(m).at(i) == joinedTable.tuples.at(m).at(i + 1))
								{
									joinedTable.tuples.at(m).erase(i + 1); //since we appended the two rows, they both still share the same value that was equal. need to delete one.
								}
							}
						}
					}
				}
				else
				{
					break;
				}
			}
		}


		for (int i = 0; i < joinedTable.size(); i++)
		{
			if (joinedTable.attributes[i] == joinedTable.attributes[i + 1])
			{
				joinedTable.deleteAttribute(joinedTable.attributes[i + 1]); //delete duplicate attribute (2 same attributes in a row.)
			}
		}

		return joinedTable;
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

