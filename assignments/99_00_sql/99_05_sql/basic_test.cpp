#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>

//------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/sql/sql.h"



//------------------------------------------------------------------------------

using namespace std;

//------------------------------------------------------------------------------
//          COPY BASIC_TEST INTO THIS FILE.
//                    AND THEN,
//         DO NOT EDIT THIS FILE ANY FURTHER
//------------------------------------------------------------------------------

const vector<string> command_list = {
/*00*/     "create table employee fields  last,       first,         dep,      salary, year",
/*01*/     "insert into employee values Blow,       Joe,           CS,       100000, 2018",
/*02*/     "insert into employee values Blow,       JoAnn,         Physics,  200000, 2016",
/*03*/     "insert into employee values Johnson,    Jack,          HR,       150000, 2014",
/*04*/     "insert into employee values Johnson,    \"Jimmy\",     Chemistry,140000, 2018",

/*05*/     "create table student fields  fname,          lname,    major,    age",
/*06*/     "insert into student values Flo,            Yao, 	Art, 	20",
/*07*/     "insert into student values Bo, 		     Yang, 	CS, 		28",
/*08*/     "insert into student values \"Sammuel L.\", Jackson, 	CS, 		40",
/*09*/     "insert into student values \"Billy\",	     Jackson, 	Math,	27",
/*10*/     "insert into student values \"Mary Ann\",   Davis,	Math,	30",

/*11*/     "select * from employee",
/*12*/     "select last, first, age from employee",
/*13*/     "select last from employee",
/*14*/     "select * from employee where last = Johnson",
/*15*/     "select * from employee where last=Blow and major=\"JoAnn\"",

/*16*/     "select * from student",
/*17*/     "select * from student where (major=CS or major=Art)",
/*18*/     "select * from student where lname>J",
/*19*/     "select * from student where lname>J and (major=CS or major=Art)"
};

const int MAKE_TABLE_COMMANDS = 11;
const int SELECT_COMMANDS = 20;

bool sql_basic(bool debug = false)
{
  SQL sql;
  Table t;
  // create the tables
  cout << "> " << command_list[0] << endl;
  sql.command(command_list[0]);
  cout << "table is created" << endl << endl;
  // insert to the tables
  for (int i = 0; i < MAKE_TABLE_COMMANDS; i++) {
    cout << "> " << command_list[i] << endl;
    t = sql.command(command_list[i]);
  }

  cout << endl << endl;
  
  // select the tables
  for (int i = MAKE_TABLE_COMMANDS; i < command_list.size(); i++)
  {
    cout << "> " << command_list[i] << endl;
    t = sql.command(command_list[i]);
    if (debug) cout << t << endl;
    cout << "records selected: " << sql.select_recnos() << endl << endl;
  }

  return true;
}

bool sql_batch(bool debug = false)
{
  SQL sql;
  sql.batch((string("_!sample01.txt").c_str()));
  return true;
}

//Lord help me! 
const bool debug = false;

TEST(SQL_BASIC, SQLBasic)
{
  bool success = sql_basic(debug);
  EXPECT_EQ(success, true);
}

TEST(SQL_BASIC, SQLBatch)
{
  bool success = sql_batch(debug);
  EXPECT_EQ(success, true);
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


/*
includes
├── binary_files
|   ├── file_record.cpp
|   ├── file_record.h
|   ├── utilities.cpp
|   └── utilities.h
├── linked_list
│   ├── linked_list_functions
│   │   └── linked_list_functions.h
│   ├── node
│   │   └── node.h
│   ├── queue
│   │   └── MyQueue.h
│   └── stack
│       └── MyStack.h
├── map
│   ├── bplustree.h
│   ├── btree_array_functions.h
│   ├── map.h
│   ├── mmap.h
│   ├── mpair.h
│   └── pair.h
├── parser
|   ├── constants.h
│   ├── parser.cpp
│   └── parser.h
├── rpn
│   ├── rpn.cpp
│   └── rpn.h
├── shunting_yard
│   ├── shunting_yard.cpp
│   └── shunting_yard.h
├── sql
│   ├── sql.cpp
│   └── sql.h
├── table
│   ├── table.cpp
│   └── table.h
└── token
    ├── constants.h
    ├── leftparen.h
    ├── logical.h
    ├── relational.h
    ├── rightparen.h
    ├── token.h
    ├── tokenstr.h
    └── universal.h

9 directories, 33 files


----------running basic_test.cpp---------


[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from SQL_BASIC
[ RUN      ] SQL_BASIC.SQLBasic
FAILED: create table: table name cannot be empty
FAILED: create table: table name cannot be empty
> create table employee fields  last,       first,         dep,      salary, year
table is created

> create table employee fields  last,       first,         dep,      salary, year
FAILED: create table: employee table already exists
> insert into employee values Blow,       Joe,           CS,       100000, 2018
> insert into employee values Blow,       JoAnn,         Physics,  200000, 2016
> insert into employee values Johnson,    Jack,          HR,       150000, 2014
> insert into employee values Johnson,    "Jimmy",     Chemistry,140000, 2018
> create table student fields  fname,          lname,    major,    age
> insert into student values Flo,            Yao,       Art,    20
> insert into student values Bo,                     Yang,      CS,             28
> insert into student values "Sammuel L.", Jackson,     CS,             40
> insert into student values "Billy",        Jackson,   Math,   27
> insert into student values "Mary Ann",   Davis,       Math,   30


> select * from employee
records selected: 0 1 2 3 

> select last, first, age from employee
records selected: 0 1 2 3 

> select last from employee
records selected: 0 1 2 3 

> select * from employee where last = Johnson
records selected: 2 3 

> select * from employee where last=Blow and major="JoAnn"
records selected: 

> select * from student
records selected: 0 1 2 3 4 

> select * from student where (major=CS or major=Art)
records selected: 0 1 2 

> select * from student where lname>J
records selected: 2 3 1 0 

> select * from student where lname>J and (major=CS or major=Art)
records selected: 0 1 2 

[       OK ] SQL_BASIC.SQLBasic (21 ms)
[ RUN      ] SQL_BASIC.SQLBatch
See output.txt file for the output.
[       OK ] SQL_BASIC.SQLBatch (79 ms)
[----------] 2 tests from SQL_BASIC (100 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (101 ms total)
[  PASSED  ] 2 tests.
*/