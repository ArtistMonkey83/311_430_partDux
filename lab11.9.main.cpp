/*
11.9 Using the C++ priority_queue class
Specifications

The objectives of this lab are:

to introduce you to the built-in C++ priority_queue class template; and
to provide you with the experience of using a priority queue data structure to solve a problem.
You are to read an unknown number of integers from standard input and then display these values in both ascending and descending order without using a sort algorithm to actually sort the data. To do this, you will use

a C++ priority_queue object as a min–heap to show the integers in ascending order; and
a C++ priority_queue object as a max–heap to show the integers in descending order.
By default, when you declare a C++ priority queue object, it is considered a max–heap. To declare a C++ priority queue object as a min–heap, you need to use the following declaration:

    priority_queue < Type, vector<Type>, ComparisonType > min_heap;
For example, the following declares a min–heap of integers called myMinHeap:

    priority_queue < int, vector<int>, greater<int> > myMinHeap;
Note: The greater operator is defined in <functional> …

Write a driver program that reads in an unknown number of integers from standard input then displays the integers in ascending order in a single line (separated by spaces), and then displays the integers in descending order in a single line (separated by spaces)).

Input

There is an unknown number of integer data that will be provided from standard input.

Sample Input

10 9 8 7 6 5 4 3 2 1
Output

The only output is the list of integers in the order they were entered, one item per line, then a blank line, then the reverse order of the integers, one item per line. Sample output, corresponding to the sample input above, is provided below.

Sample Output

 1 2 3 4 5 6 7 8 9 10
 10 9 8 7 6 5 4 3 2 1
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  priority_queue<int> maxHeap;
  priority_queue<int,vector<int>, greater<int>> minHeap;

  vector<int> data;                 //Data vector will hold our data from standard input
  string value;                        //Value will hold the data as it is entered and then push_back into data vector
  int number;
  while (cin >> number){      //Get one line at a time from standard input

    //number = stoul(value);
    maxHeap.push(number);            //Push back the values into the vector
    minHeap.push(number);
  }

  while(!minHeap.empty()){
    cout << " " << minHeap.top();
    minHeap.pop();
  }
  cout << endl;

  while(!maxHeap.empty()){
    cout  << " "<< maxHeap.top();
    maxHeap.pop();
  }
  cout << endl;


   return 0;
}
