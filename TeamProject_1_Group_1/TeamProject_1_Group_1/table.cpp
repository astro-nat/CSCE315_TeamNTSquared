/*-------------------------------------------------------------------------------------------------------*/
/* DEFINES */
/*-------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------*/
/* INCLUDES */

#include <iostream>
#include <vector>
#include <string>
#include "record.h"
#include "table.h"

/*-------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------*/
/* FUNCION DEFINITIONS FOR CLASS: TABLE */

Table::Table(int rows = 0, int columns = 0) {
	std::cout << "Table constructor." << endl;
}

void Table::addAttribute(string attributeName) {

}
void Table::deleteAttribute(string attributeName) {

}
void Table::insert(Record newRow) {

}
vector<string> Table::getAttributes() {

}
int Table::size() {

}
void Table::specifyKey(string attributeKey) {

}

void Table::crossJoin(Table t1, Table t2) {

}
void Table::naturalJoin(Table t1, Table t2) {

}
int Table::count() {

}
int Table::max() {

}
int Table::min() {

}