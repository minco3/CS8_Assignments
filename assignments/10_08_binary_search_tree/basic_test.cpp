#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>

//------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/binary_tree/binary_tree.h"
#include "../../includes/binary_search_tree/binary_search_tree.h"


//------------------------------------------------------------------------------

using namespace std;

//------------------------------------------------------------------------------
//          COPY BASIC_TEST INTO THIS FILE.
//                    AND THEN,
//         DO NOT EDIT THIS FILE ANY FURTHER
//------------------------------------------------------------------------------

template <class Item>
void print_item (Item& data)
{
  cout << "[" << data << "]";
}

bool basic_test_tree_node(bool debug=false)
{
  int sorted_list[50], size = 0;
  for (int i = 0; i < 20; i++)
  {
    sorted_list[i] = i*2;
    size++;
  }

  BST<int> bst(sorted_list, size);
  BST<int> bst_copy = bst; //copy ctor (you should also test assignment!)
  binary_tree_node<int> *temp;

  cout << "BST is:" << endl << bst << endl;
  cout << "----------------------------" << endl << endl;

  cout << "Search BST" << endl << endl;

  temp = bst.search(21);
  cout << "Found subtree of node 21 is NULL: " << boolalpha << (temp==nullptr) << endl << endl;

  temp = bst.search(8);
  cout << "Found subtree of node 8 is:" << endl;
  print(temp);
  cout << "----------------------------" << endl << endl;

  temp = bst.search(22);
  cout << "Found subtree of node 22 is:" << endl;
  print(temp);
  cout << "----------------------------" << endl << endl;

  cout << "Insert BST" << endl << endl;

  bst.insert(9);
  cout << "Insert node 9 is:" << endl << bst << endl;
  cout << "----------------------------" << endl << endl;

  bst.insert(11);
  cout << "Insert node 11 is:" << endl << bst << endl;
  cout << "----------------------------" << endl << endl;
  
  cout << "Delete BST" << endl << endl;

  bst.erase(12);
  cout << "Delete node 12 is:" << endl << bst << endl;
  cout << "----------------------------" << endl << endl;

  bst.erase(16);
  cout << "Delete node 16 is:" << endl << bst << endl;
  cout << "----------------------------" << endl << endl;

  bst.erase(14);
  cout << "Delete node 14 is:" << endl << bst << endl;
  cout << "----------------------------" << endl << endl;

  bst.erase(0);
  cout << "Delete node 0 is:" << endl << bst << endl;
  cout << "----------------------------" << endl << endl;

  bst.erase(2);
  cout << "Delete node 2 is:" << endl << bst << endl;
  cout << "----------------------------" << endl << endl;

  bst.erase(4);
  cout << "Delete node 4 is:" << endl << bst << endl;
  cout << "----------------------------" << endl << endl;

  cout << "Merge two BSTs" << endl << endl;

  bst += bst_copy;
  cout << "Merged two BSTs:" << endl << bst << endl;
  cout << "----------------------------" << endl << endl;

  cout << "pre_order    : ";
  preorder(print_item<int>, bst.root());
  cout << endl;

  cout << "in_order     : ";
  inorder(print_item<int>, bst.root());
  cout << endl;

  cout << "post_order   : ";
  postorder(print_item<int>, bst.root());
  cout << endl;
  cout << endl;

  cout << "Clear BST" << endl;
  cout << "bst is empty     : " << boolalpha << bst.empty() << endl;
  cout << "bst_copy is empty: " << boolalpha << bst.empty() << endl << endl;
  bst.clear_all();
  bst_copy.clear_all();
  cout << "bst is empty     : " << boolalpha << bst.empty() << endl;
  cout << "bst_copy is empty: " << boolalpha << bst.empty() << endl << endl;

  return true;
}


//Lord help me! 
const bool debug = false;

TEST(BASIC_TEST, TestTreeNode)
{
  bool success = basic_test_tree_node(debug);
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
├── binary_tree
│   └── binary_tree.h
└── binary_search_tree
    └── binary_search_tree.h

2 directories, 2 files

----------running basic_test.cpp---------


[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from BASIC_TEST
[ RUN      ] BASIC_TEST.TestTreeNode
BST is:
                [38]
            [36]
        [34]
                [32]
            [30]
    [28]
                [26]
            [24]
        [22]
            [20]
[18]
                [16]
            [14]
        [12]
            [10]
    [8]
                [6]
            [4]
        [2]
            [0]

----------------------------

Search BST

Found subtree of node 21 is NULL: true

Found subtree of node 8 is:
            [16]
        [14]
    [12]
        [10]
[8]
            [6]
        [4]
    [2]
        [0]
----------------------------

Found subtree of node 22 is:
        [26]
    [24]
[22]
    [20]
----------------------------

Insert BST

Insert node 9 is:
                [38]
            [36]
        [34]
                [32]
            [30]
    [28]
                [26]
            [24]
        [22]
            [20]
[18]
                [16]
            [14]
        [12]
            [10]
                [9]
    [8]
                [6]
            [4]
        [2]
            [0]

----------------------------

Insert node 11 is:
                [38]
            [36]
        [34]
                [32]
            [30]
    [28]
                [26]
            [24]
        [22]
            [20]
[18]
                [16]
            [14]
        [12]
                [11]
            [10]
                [9]
    [8]
                [6]
            [4]
        [2]
            [0]

----------------------------

Delete BST

Delete node 12 is:
                [38]
            [36]
        [34]
                [32]
            [30]
    [28]
                [26]
            [24]
        [22]
            [20]
[18]
            [16]
        [14]
                [11]
            [10]
                [9]
    [8]
                [6]
            [4]
        [2]
            [0]

----------------------------

Delete node 16 is:
                [38]
            [36]
        [34]
                [32]
            [30]
    [28]
                [26]
            [24]
        [22]
            [20]
[18]
        [14]
                [11]
            [10]
                [9]
    [8]
                [6]
            [4]
        [2]
            [0]

----------------------------

Delete node 14 is:
                [38]
            [36]
        [34]
                [32]
            [30]
    [28]
                [26]
            [24]
        [22]
            [20]
[18]
            [11]
        [10]
            [9]
    [8]
                [6]
            [4]
        [2]
            [0]

----------------------------

Delete node 0 is:
                [38]
            [36]
        [34]
                [32]
            [30]
    [28]
                [26]
            [24]
        [22]
            [20]
[18]
            [11]
        [10]
            [9]
    [8]
                [6]
            [4]
        [2]

----------------------------

Delete node 2 is:
                [38]
            [36]
        [34]
                [32]
            [30]
    [28]
                [26]
            [24]
        [22]
            [20]
[18]
            [11]
        [10]
            [9]
    [8]
            [6]
        [4]

----------------------------

Delete node 4 is:
                [38]
            [36]
        [34]
                [32]
            [30]
    [28]
                [26]
            [24]
        [22]
            [20]
[18]
            [11]
        [10]
            [9]
    [8]
        [6]

----------------------------

Merge two BSTs

Merged two BSTs:
                [76]
            [72]
        [68]
                [64]
            [60]
    [56]
                [52]
            [48]
        [44]
            [40]
[36]
                [16]
            [25]
        [22]
            [19]
    [16]
                [6]
            [4]
        [8]
            [0]

----------------------------

pre_order    : [36][16][8][0][4][6][22][19][25][16][56][44][40][48][52][68][60][64][72][76]
in_order     : [0][8][4][6][16][19][22][25][16][36][40][44][48][52][56][60][64][68][72][76]
post_order   : [0][6][4][8][19][16][25][22][16][40][52][48][44][64][60][76][72][68][56][36]

Clear BST
bst is empty     : false
bst_copy is empty: false

bst is empty     : true
bst_copy is empty: true

[       OK ] BASIC_TEST.TestTreeNode (4 ms)
[----------] 1 test from BASIC_TEST (4 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (4 ms total)
[  PASSED  ] 1 test.
*/