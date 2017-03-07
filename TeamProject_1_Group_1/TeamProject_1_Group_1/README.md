# API Overview

## Record Class

### Constructor

Initializes new empty record:
```c++
Record(int size = 0);
```

### Methods

Returns record size:
```c++
int size();
```

Returns value at given index:
```c++
string at(int index);
```

Sets record at given index to new data:
```c++
void set(int index, string data);
```

Erases record value at given index:
```c++
void erase(int index);
```

## Table Class

### Data Members

Stores key of table:
```c++
string key;
```

Stores table's attributes, or table column headers:
```c++
vector<string> attributes;
```

Stores all records in table:
```c++
vector<Record::Record> tuples;
```

### Constructor

Initializes an empty table with 0 rows and 0 columns:
```c++
Table(int rows = 0, int columsn = 0;
```

Initializes a table with given attributes:
```c++
Table(vector<string> attr);
```

### Methods


## Database Class

### Data Members

Stores vector of Tables:
```c++
vector<TABLE::Table> data;
```

### Constructor

Initializes an empty database:
```c++
Database();
```

### Methods

Adds new table to database:
```c++
void addTable(string name, TABLE::Table t1);
```

Drops table from database: 
```c++
void dropTable(string name);
```

Lists all tables in database by returning a vector of table names:
```c++
vector<string> listTables();
```

Gets all tables in database by returning a vector of table objects:
```c++
vector<string> listTables();
```

Returns a table object resulting from given query:
```c++
Table Query(string SELECT, string FROM, string WHERE);
```

Returns index of table with given name:
```c++
int indexAtName(string name);
```
