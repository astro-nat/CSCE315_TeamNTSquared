#pragma once

#include <string>
#include "Record.h"
#include <vector>
#include "record.h"


class __declspec(dllexport) Table {

private:
	std::vector<Record> records;

public:
	class iterator : std::vector<Record>::iterator {};


	Table() : records() {

	}

	Table(std::string attrs[]);

	void add(std::string attr);

	void del(std::string attr);

	void insert(Record r);

	std::string* get_attributes();

	int size();



	Record* operator[](size_t index);

	const Record* operator[](size_t index) const;



	std::vector<Record>::iterator begin() { return records.begin(); }

	std::vector<Record>::iterator end() { return records.end(); }



	void rename(std::string attr, std::string n_attr);

	void spec_key(std::string keys[]);



	void cross_join(Table other_table);

	void natural_join(Table other_table);



	int count_attr(std::string attr);

	int min_attr(std::string attr);

	int max_attr(std::string attr);
	
};

