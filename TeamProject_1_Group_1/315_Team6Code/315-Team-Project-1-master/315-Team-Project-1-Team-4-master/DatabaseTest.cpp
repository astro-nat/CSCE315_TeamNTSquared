#include "database.h"
#include "table.h"
#include "record.h"
#include <iostream>
#include <string>
using namespace std;

// GLOBAL TEST VARIABLE
string TEST = "TEST";

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
		// Begin testing Table

		// Begin testing Database
	}
	catch (string e) {
		cout << e;
	}

	return 0;

}