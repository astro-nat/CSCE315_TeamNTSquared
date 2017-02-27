// Group5Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../database.h"
#include <iostream>
#include <string>

using namespace std;

int record_test() {
	cout << "Testing single RECORD...";
	RECORD::Record a(1);
	a.set(1, "Ryan");
	if (a.at(1) == "Ryan" && a.size() == 1) {
		cout << "Passed!";
		//return 0;
	}
	else {
		cout << "Failed! Exiting...";
		return -1;
	}

	cout << "Testing multiple RECORD...";
	RECORD::Record b(3);
	b.set(1, "Ryan");
	b.set(2, "Andrew");
	b.set(3, "Ethan");
	if (b.at(1) == "Ryan" && b.at(2) == "Andrew" && b.at(3) == "Ethan" && b.size() == 3) {
		cout << "Passed!";
		return 0;
	}
	else {
		cout << "Failed! Exiting...";
		return -1;
	}
}

int table_test() {
	RECORD::Record a(3);
	a.set(1, "1");
	a.set(2, "2");
	a.set(3, "3");

	RECORD::Record b(3);
	b.set(1, "4");
	b.set(2, "5");
	b.set(3, "6");

	RECORD::Record c(3);
	c.set(1, "7");
	c.set(2, "8");
	c.set(3, "9");

	cout << "Testing Table...";

	TABLE::Table t1(3, 3);
	t1.addAttribute("First");
	t1.addAttribute("Second");
	t1.addAttribute("Third");
	t1.specifyKey("First");

	vector<string> test_attributes = t1.getAttributes();
	if (test_attributes[1] != "First") {
		cout << "Failed <getAttributes()>" << endl;
		return -1;
	}

	if (test_attributes[2] != "Second") {
		cout << "Failed <getAttributes()>" << endl;
		return -1;
	}

	if (test_attributes[3] != "Third") {
		cout << "Failed <getAttributes()>" << endl;
		return -1;
	}

	t1.insert(a);
	t1.insert(b);
	t1.insert(c);

	TABLE::Table t2(3, 3);
	t2.addAttribute("First");
	t2.addAttribute("Second");
	t2.addAttribute("Third");
	t2.specifyKey("First");

	t2.insert(c);
	t2.insert(b);
	t2.insert(a);

	if (t2.size() != 3) {
		cout << "Failed <size()>" << endl;
			return -1;
	}

	t1.deleteAttribute("Third");
	t2.deleteAttribute("Third");

	if (t1.size() != 2 || t2.size() != 2) {
		cout << "Failed <deleteAttribute()>" << endl;
		return -1;
	}

	if (t1.count("First") != 3) {
		cout << "Failed <count()>" << endl;
		return -1;
	}

	if (t1.min("First") != 1) {
		cout << "Failed <min()>" << endl;
		return -1;
	}

	if (t1.max("First") != 7) {
		cout << "Failed <max()>" << endl;
		return -1;
	}

	TABLE::Table t_cross = t1.crossJoin(t1, t2);
	TABLE::Table t_natural = t1.naturalJoin(t1, t2);

	cout << "Passed!" << endl;

	return 0;
}

int database_test() {
	DATABASE::Database testDB;
	TABLE::Table t1(1, 2);
	t1.addAttribute("Name");
	t1.addAttribute("BOOL");

	RECORD::Record a(2);
	RECORD::Record b(2);

	a.set(1, "Ryan");
	a.set(2, "True");

	a.set(1, "Ethan");
	b.set(2, "False");

	t1.insert(a);
	t1.insert(b);



	cout << "Testing addTable and listTable...";
	testDB.addTable("test1", t1);
	vector<string> list = testDB.listTables();
	if (list[0] == "test1")
	{
		cout << "addTable and listTable PASS.";
	}
	else
	{
		cout << "FAIL";
		return 0;
	}

	TABLE::Table c = testDB.Query("*", "test1", "BOOL = True");
	for (auto it = c.recordItr.begin(); it != c.recordItr.end(); ++it) {
		RECORD::Record i = std::distance(c.recordItr.begin(), it);
		cout << i.at(0);
		if (i.at(0) != "Ryan") {
			cout << "error with query";
		}
	}

	vector<TABLE::Table> tables = testDB.getTables();
	vector<string> tableAttributeNames = tables[0].getAttributes();
	if (tableAttributeNames[0] != "Name") {
		cout << "error with getTables";
	}

	cout << "Testing dropTable...";
	testDB.dropTable("test1");
	list = testDB.listTables();
	if (list.empty())
	{
		cout << "dropTable PASS.";
	}
	else
	{
		cout << "FAIL";
		return 0;
	}
}

int main()
{
	record_test();
	table_test();
	database_test();
}

