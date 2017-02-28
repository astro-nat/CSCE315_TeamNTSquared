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
		return container[index];
	}

	void Record::set(int index, string data) {
		container[index] = data;
	}

	void Record::erase(int index) {
		container.erase(container.begin() + index);
	}
