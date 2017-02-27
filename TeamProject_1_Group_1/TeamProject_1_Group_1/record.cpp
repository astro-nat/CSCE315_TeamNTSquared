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

	}

	int Record::size() {
		return 0;
	}

	string Record::at(int index) {
		return "";
	}

	void Record::set(int index, string data) {

	}

	void Record::erase(int index) {
		container.erase(container.begin() + index);
	}
