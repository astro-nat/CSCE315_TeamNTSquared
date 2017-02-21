#include "database.h"
#include "table.h"
#include "record.h"
#include <iostream>
using namespace std;

int main() {
	Database db();
	Table t1;

	/*
	First Error we noticed. Your Record class has no data members
	and the entire class is private. Therefore we cannot create 
	any Record data members.
	*/
	Record r1(0), r2(2), r3(4);
	

	try {
		// Begin testing Record

		// Begin testing Table

		// Begin testing Database
	}
	catch (...) {

	}

	return 0;

}