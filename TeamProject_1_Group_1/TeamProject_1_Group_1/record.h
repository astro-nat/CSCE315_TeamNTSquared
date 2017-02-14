#pragma once

/*-------------------------------------------------------------------------------------------------------*/
/* DEFINES */

#ifndef RECORD_H
#define RECORD_declspec(dllexport)
#else 
#define RECORD_declspec(dllimport)
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
		Record(int size = 0);
		int size();
		string at(int index);
		void set(int index, string data);
	};
}

/*-------------------------------------------------------------------------------------------------------*/