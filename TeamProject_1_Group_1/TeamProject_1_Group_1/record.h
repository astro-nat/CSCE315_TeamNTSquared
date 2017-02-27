#pragma once

/*-------------------------------------------------------------------------------------------------------*/
/* DEFINES */

#ifndef RECORD_H
#define RECORD_API __declspec(dllexport)
#else 
#define RECORD_API __declspec(dllimport)
#endif 
/*-------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------*/
/* INCLUDES */

#include <vector>
#include <string>

using namespace std;
/*-------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------*/
/* CLASS DEFINITIONS */

namespace RECORD {

	class Record {
	private:
		vector<string> container;
	public:
		RECORD_API Record(int size = 0);
		RECORD_API int size();
		RECORD_API string at(int index);
		RECORD_API void set(int index, string data);
		RECORD_API void erase(int index);
	};
}

/*-------------------------------------------------------------------------------------------------------*/