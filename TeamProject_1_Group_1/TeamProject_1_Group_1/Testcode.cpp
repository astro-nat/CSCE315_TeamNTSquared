#include <stdio.h>
#include <string.h>
#include <iostream>
#include "database.h"
#include "record.h"
#include "table.h"
#include "parser.h"

using namespace std;

//try { /* */ } catch (...) { /* */ }
int main(){
	try {
		DATABASE::Database db;

		RECORD::Record r1, r2(0), r3(1), r4(100), r5(3);

		//Put data into records
		r3.set(0, "test");
		r4.set(0, "val1");
		r4.set(99, "val2");
		r5.set(0, "val1");
		r5.set(1, "val2");
		r5.set(2, "val3");

		//Use these to initialize tables
		vector<string> empty;
		vector<string> init(3);
		
		init.push_back("name1");init.push_back("name2");init.push_back("name3");
		
	
	//Intitialize tables
	TABLE::Table t1;
	TABLE::Table t2(init);
	TABLE::Table t3(empty);

	//Add a table to the Database
	db.addTable("table2", t1);
	//db.addTable("table3", t3);
	int size = db.getTables().size();
	if(size != 2){
		std::cout << "Error: adding a table is not working properly\n";
	}

	//Drop a table from the Database
	db.dropTable("table3");
	if(db.getTables().size() != size-1){
		std::cout << "Error: dropping a table is not working properly\n";
	}
	
	//Dropping a table that doesn't exist (shouldn't break program)
	size = db.getTables().size();
	db.dropTable("table3");
	if(db.getTables().size() != size){
		std::cout << "Error: dropping table not in Database changes Database\n";
	}
	
	//Add a table that already exists (shouldn't create duplicate)
	size = db.getTables().size();
	//db.addTable("table2", t2);
	if(db.getTables().size() != size){
		std::cout << "Error: adding table already in Database changes Database\n";
	}

	//Delete an attribute
	//t2.deleteAttribute("name1");
	
	//Delete an attribute that isn't in the table
	/*size = t3.getSize();
	t3.deleteAttribute("name1");
	if(t3.getSize() != size){
		cout << "Error: removing attribute not in Table changes Table\n";
	}*/

	t1.addAttribute("new");

	//Add an atrribute already in the table
	size = t1.size();
	t1.addAttribute("new");
	if(t1.size() != size){
		cout << "Error: adding attribute already in Table changes Table\n";
	}

	t1.specifyKey("new");
	if(t1.count("new") != 0){
		cout << "Miscounted attributes for empty Table\n";
	}
	//Test minimum() and maximum() functions for t1
	RECORD::Record r6(1), r7(1), r8(1);
	r6.set(0, "1");
	r7.set(0, "2");
	r8.set(0, "3");
	t1.insert(r6);
	t1.insert(r7);
	t1.insert(r8);
	if(t1.min("new") != 1){
		cout << "Error in t1.minimum() function\n";
	}
	if(t1.max("new") != 3){
		cout << "Error in t1.maximum() function\n";
	}
	//Another thought:
	//What is the return value if you call maximum() from an empty table?
	//You could have an exception thrown, return empty string, or have tables start at size=1

	//put empty record into empty table (strange, but works based on your current design)
	t1.insert(r1);
	
	//put empty record into non-empty table (should get error)
	bool error = false;
	//try {t2.insertRecord(r1);} catch (...) { error = true; }
	if(!error) cout << "Error not thrown for invalid record insert\n";
	
	//Insert record(size=3) into table(size=3), this is valid.
	t2.insert(r5);

	//Another though:
	//Output the values in t2 and t1 to confirm these functions work properly
	int size2 = t2.size(), size3 = t3.size();

	// Nat note: should join functions be for database?
	t2.crossJoin(t2, t3);
	if(t2.size() != size2*size3){
		cout << "Problem with cross join!\n";
	}
	t2.naturalJoin(t1, t2);

//	cout << db.getListTables();
//	cout << db.getTables();

	t1.addAttribute("test1");
	t1.addAttribute("test2");
	t1.addAttribute("test3");
	if(t1.size() != 3){
		cout << "Error adding attributes\n";
	}
	//standard query (should get returned values)
	TABLE::Table result = db.Query("*", "table1",  "> new NOT < test2");
	
	//query for something not in the table
	db.Query("*", "table2", "= thing not in table with spaces in name");
	
	//query for a table not in the database
	db.Query("*", "TableNotFound", "= new");

	cout << "Passed!\n";
}
catch(...) {
	cout << "Program error\n";
}
}


