#pragma once

#include <vector>


class __declspec(dllexport) Record {

	Record(unsigned int size);

	int size();

	std::string* operator[](size_t index);

};
