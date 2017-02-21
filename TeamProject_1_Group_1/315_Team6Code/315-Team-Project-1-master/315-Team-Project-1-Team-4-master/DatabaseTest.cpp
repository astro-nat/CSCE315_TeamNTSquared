#include "database.h"
#include "table.h"
#include "record.h"
#include <iostream>
#include <string>
using namespace std;

// GLOBAL TEST VARIABLE
string TEST = "TEST";

int main() {
	
	/*
	First Error we noticed. Your Database class has no data members
	and the entire class is private. Therefore we cannot create 
	any Database data members.
	*/
	Database db();
	
	
	Table t1;
	
	/*
	First Error we noticed. Your Record class has no data members
	and the entire class is private. Therefore we cannot create 
	any Record data members.
	*/
	Record r1(0), r2(2), r3(4);
	

	try {

		///* BEGIN TESTING RECORD *///
		
		// Test Record.size();
		if (r1.size() != 0) {
			throw string("Record size error.\n");
		}
		if (r2.size() != 2) {
			throw string("Record size error.\n");
		}
		if (r3.size() != 4) {
			throw string("Record size error.\n");
		}

		// Test Basic Initialization
		// Records should be intialized with an array of empty strings based on the size given
		if (!r1[0].empty()) {
			throw string("Record initialization error.\n");
		}
		if (!r2[1].empty()) {
			throw string("Record initialization error.\n");
		}
		if (!r3[3].empty()) {
			throw string("Record initialization error.\n");
		}

		// Test Getting/Setting values
		r1[0] = TEST;
		r2[1] = TEST;
		r3[3] = TEST;
		if (r1[0] != TEST) {
			throw string("Record Set/access failed.\n");
		}
		if (r2[1] != TEST) {
			throw string("Record Set/access failed.\n");
		}
		if (r3[3] != TEST) {
			throw string("Record Set/access failed.\n");
		}
		
		
		///* BEGIN TESTING TABLE *///

		
		///* BEGIN TESTING DATABASE *///
		
		// Should Be No Tables in Database upon Initialization
		if(!db.tables.empty()) {
			throw string("Database size error.\n");
		}
		
		// Test add_table
		db.add_table("Table1", t1);
		if(db.tables.size() != 1) {
			throw string("Add failed.\n");
		}
		
		// Test list_table_names
		if(db.list_table_names()[0] != "Table1") {
			throw string("List table names failed.\n");
		}
		
		// Test get_tables
		if(t1 != db.get_tables()[0]) {
			throw string("Get tables failed.\n");
		}
		
		// Test query with existing table with existing record(s)
		Table result = db.query("*", "Table1",  "TEST");
	
		// Test query with existing table with nonexistent record(s)
		db.query("*", "Table1", "DUMMY_COLUMN = NOTFOUND");
	
		// Test query with nonexisting table
		db.query("*", "FakeTable", "TEST");
		
		// Test drop
		db.drop("Table1");
		if(db.tables.size() != 0) {
			throw string("Table drop failed.\n");
		}
		
	}
	catch (string e) {
		cout << e;
	}

	
	
	return 0;

}