/*

8.7 LAB: Iterating through a C++ set container object
This lab will be available until March 8th, 11:59 PM PST
Specifications
The objectives of this lab are:

to introduce you to the C++ set container class;
to provide you with the experience of using a binary search tree data structure to solve a problem; and
to provide you with the opportunity to use both the range–based for-loop (a.k.a. the for-each loop, although this is misleading because C++ has a for_each feature) and iterators with the C++ set class to traverse the structure in the appropriate/required ways.
You are to determine unique integers (no duplicates) from standard input and show the contents in ascending and descending order without using a sort algorithm. To do this, you will implement the following template functions:

a function named show() that displays the contents of a set object in ascending order using a range–based for-loop; and
a function named showReverse() that displays the contents of a set object in descending order using a reverse iterator.
Both functions display each item to standard output with a single space character in front and all items in a single line (separated by this space) terminated by an endl.

Write a driver program that tests these two functions on integer data.

Input
There is an unknown number of integer data that will be provided from standard input.

Sample Input
10 9 8 7 6 5 4 3 2 1
Output
The only output are the set contents in ascending order (in one line) followed by the set contents in descending order (in the following line) — both without duplicates.

Sample output, corresponding to the sample input above, is provided below.

Sample Output
 1 2 3 4 5 6 7 8 9 10
 10 9 8 7 6 5 4 3 2 1

*/

#include <set>
#include <iterator>
#include <iostream>

using namespace std;

/////
////  FUNCTION PROTOTYPES
/////

void show(set <int>);          // Displays the contents of a set object in ascending order using a range–based for-loop
void showReverse(set <int>);   // Displays the contents of a set object in descending order using a reverse iterator

/////
////  DRIVING PROGRAM
/////

int main(){

  set <int> userInput;  // A set to hold input from the user
  int data;

  while (cin >> data){        // While there is input from the user via cin.....
    userInput.insert(data);   //Push the value the user inputted into the set

  }

  show(userInput);    // Calling show function to show the contents of userInput set in ascending order

  showReverse(userInput);   // Calling showReverse function to show the contents of userInput set in descending order


  return 0;
}

/////
////  FUNCTION DECLARATIONS
/////

// Displays the contents of a set object in ascending order using a range–based for-loop
void show(set <int> dataFromMain){
  for(auto&  element : dataFromMain){
    cout << " " << element;
  }
  cout << endl;
}

// Displays the contents of a set object in descending order using a reverse iterator
void showReverse(set <int> dataFromMain){
  for(auto&  element : dataFromMain){
    cout << " " << element;
  }
  cout << endl;
}
