#include <stdio.h>
#include <string.h>
#include "database.h"
#include "record.h"
#include "table.h"

//try { /* */ } catch (...) { /* */ }
int main(){
try {
	Database db();

	Record r1(), r2(0), r3(1), r4(100), r5(3);

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
	Table t1();
	Table t2(init);
	Table t3(empty);

	//Add a table to the Database
	db.addTable("table2", t2);
	db.addTable("table3", t3);
	int size = db.getTables().size();
	if(size != 2){
		cout << "Error: adding a table is not working properly\n";
	}

	//Drop a table from the Database
	db.dropTable("table3");
	if(db.getTables().size() != size-1){
		cout << "Error: dropping a table is not working properly\n";
	}
	
	//Dropping a table that doesn't exist (shouldn't break program)
	size = db.getTables().size();
	db.dropTable("table3");
	if(db.getTables().size() != size){
		cout << "Error: dropping table not in Database changes Database\n";
	}
	
	//Add a table that already exists (shouldn't create duplicate)
	size = db.getTables().size();
	db.addTable("table2", t2);
	if(db.getTables().size() != size){
		cout << "Error: adding table already in Database changes Database\n";
	}

	//Delete an attribute
	t2.deleteAttribute("name1");
	
	//Delete an attribute that isn't in the table
	size = t3.getSize();
	t3.deleteAttribute("name1");
	if(t3.getSize() != size){
		cout << "Error: removing attribute not in Table changes Table\n";
	}

	t1.addAttribute("new");

	//Add an atrribute already in the table
	size = t1.getSize();
	t1.addAttribute("new");
	if(t1.getSize() != size){
		cout << "Error: adding attribute already in Table changes Table\n";
	}

	t1.designateKey("new");
	if(t1.count("new") != 0){
		cout << "Miscounted attributes for empty Table\n";
	}
	//Test minimum() and maximum() functions for t1
	Record r6(1), r7(1), r8(1);
	r6.set(0, "1");
	r7.set(0, "2");
	r8.set(0, "3");
	t1.addRecord(r6);
	t1.addRecord(r7);
	t1.addRecord(r8);
	if(t1.minimum("new") != "1"){
		cout << "Error in t1.minimum() function\n";
	}
	if(t1.maximum("new") != "3"){
		cout << "Error in t1.maximum() function\n";
	}
	//Another thought:
	//What is the return value if you call maximum() from an empty table?
	//You could have an exception thrown, return empty string, or have tables start at size=1

	//put empty record into empty table (strange, but works based on your current design)
	t1.insertRecord(r1);
	
	//put empty record into non-empty table (should get error)
	bool error = false;
	try {t2.insertRecord(r1);} catch (...) { error = true; }
	if(!error) cout << "Error not thrown for invalid record insert\n";
	
	//Insert record(size=3) into table(size=3), this is valid.
	t2.insertRecord(r5);

	//Another though:
	//Output the values in t2 and t1 to confirm these functions work properly
	int size2 = t2.getSize(), size3 = t3.getSize();
	Table.crossJoin(t2, t3);
	if(t2.getSize() != size2*size3){
		cout << "Problem with cross join!\n";
	}
	Table.naturalJoin(t1, t2);

//	cout << db.getListTables();
//	cout << db.getTables();

	t1.addAttribute("test1");
	t1.addAttribute("test2");
	t1.addAttribute("test3");
	if(t1.getSize() != 3){
		cout << "Error adding attributes\n";
	}
	//standard query (should get returned values)
	Table result = db.query("*", "table1",  "> new NOT < test2");
	
	//query for something not in the table
	db.query("*", "table2", "= thing not in table with spaces in name");
	
	//query for a table not in the database
	db.query("*", "TableNotFound", "= new");

	cout << "End of Tests\n";
}
catch(...) {
	cout << "Program error\n";
}
}
