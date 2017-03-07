# API Overview

## Record

### Constructor

### Methods

## Table

### Constructor

### Methods



## Database

### Data Members

Stores vector of Tables:
```c++
vector<TABLE::Table> data;
```

### Constructor

Initializes an empty database
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
