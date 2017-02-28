/*-------------------------------------------------------------------------------------------------------*/
/* DEFINES */
/*-------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------*/
/* INCLUDES */

#include <vector>
#include <string>
#include "record.h"
using namespace RECORD;
/*-------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------*/
/* FUNCION DEFINITIONS FOR CLASS: RECORD */


	Record::Record(int size) {
		container.resize(size);
	}

	int Record::size() {
		return container.size();
	}


	string Record::at(int index) {
		if (index < container.size()) {
			return container[index];
		}
		else return "";
	}

	void Record::set(int index, string data) {
		if (index >= container.size()) {
			container.push_back(data);
		}
		else {
			container[index] = data;
		}
	}

	void Record::erase(int index) {
		container.erase(container.begin() + index);
	}

