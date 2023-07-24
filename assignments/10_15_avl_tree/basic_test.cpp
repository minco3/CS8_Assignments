#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>

//------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/binary_tree/binary_tree.h"
#include "../../includes/avl_tree/avl_tree.h"


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

template <class Item>
bool isAVL(binary_tree_node<Item>* root)
{
  // base case
  if (root == nullptr) return true;
  // balance factor of root be -1, 0 , 1
  if (root->balance_factor()<-1 || root->balance_factor()>1) return false;
  // traverse entire tree
  return isAVL(root->left()) && isAVL(root->right());
}

bool basic_test_avl_tree(bool debug=false)
{
  AVL<int> simple;
  simple.insert(15);
  simple.insert(80);
  simple.insert(64);
  cout << "AVL is:" << endl << simple << endl;

  int sorted_list[50], size = 0;
  for (int i = 0; i < 30; i++)
  {
    sorted_list[i] = i*2;
    size++;
  }

  AVL<int> avl(sorted_list, size);
  cout << "AVL is:" << endl << avl << endl;
  cout << "This is an AVL tree: " << boolalpha << isAVL(avl.root()) << endl;
  cout << "----------------------------" << endl << endl;

  avl.erase(2);
  avl.erase(0);
  cout << "AVL is:" << endl << avl << endl;
  cout << "This is an AVL tree: " << boolalpha << isAVL(avl.root()) << endl;
  cout << "----------------------------" << endl << endl;

  avl.insert(11);
  avl.erase(4);
  avl.erase(6);
  cout << "AVL is:" << endl << avl << endl;
  cout << "This is an AVL tree: " << boolalpha << isAVL(avl.root()) << endl;
  cout << "----------------------------" << endl << endl;

  avl.insert(7);
  avl.insert(6);
  avl.insert(5);
  cout << "AVL is:" << endl << avl << endl;
  cout << "This is an AVL tree: " << boolalpha << isAVL(avl.root()) << endl;
  cout << "----------------------------" << endl << endl;
  return true;
}


//Lord help me! 
const bool debug = false;

TEST(BASIC_TEST, TestAVL)
{
  bool success = basic_test_avl_tree(debug);
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
├── avl_tree
│   └── avl_tree.h
└── binary_tree
    └── binary_tree.h

2 directories, 2 files

----------running basic_test.cpp---------


[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from BASIC_TEST
[ RUN      ] BASIC_TEST.TestTreeNode
AVL is:
    [80]
[64]
    [15]

AVL is:
                [58]
            [56]
                [54]
        [52]
                [50]
            [48]
                [46]
    [44]
                [42]
            [40]
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

This is an AVL tree: true
----------------------------

AVL is:
                [58]
            [56]
                [54]
        [52]
                [50]
            [48]
                [46]
    [44]
                [42]
            [40]
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

This is an AVL tree: true
----------------------------

AVL is:
                [58]
            [56]
                [54]
        [52]
                [50]
            [48]
                [46]
    [44]
                [42]
            [40]
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
            [8]

This is an AVL tree: true
----------------------------

AVL is:
                [58]
            [56]
                [54]
        [52]
                [50]
            [48]
                [46]
    [44]
                [42]
            [40]
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
                [8]
        [7]
            [6]
                [5]

This is an AVL tree: true
----------------------------

[       OK ] BASIC_TEST.TestTreeNode (0 ms)
[----------] 1 test from BASIC_TEST (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.
*/