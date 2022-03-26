/*
11.8 How do we know if a vector is a min–heap?
Specifications
In this lab, you will write a function that determines if a given vector of integers is a min–heap. Recall that, by default, a vector is a semi–heap satisfying the heap structure property but not the min-heap order property.
Input
There is an unknown number of integer data that will be provided from standard input. Each line of input represents the contents of a vector. We do not know how many lines of input there are.
Sample Input
1 2 3 4 5
5 4 3 2 1
1 9 2 13 10 5 3 15 14 11 21 7 6 4 17 16 24 28
25 32 55 97 43 62 30 2 27 59 15 81 22 97 38 42
Output
The only output is a determination whether each provided vector of integers is a min–heap or not. If it is not a min–heap, report the largest index of the root of a subtree where the min–heap order property is violated.
Sample output, corresponding to the sample input above, is provided below.
Sample Output
Vector is a min-heap. (1 2 3 4 5)
Min-heap order property violated at index 1.(5 4 3 2 1)
Vector is a min-heap.(1 9 2 13 10 5 3 15 14 11 21 7 6 4 17 16 24 28)
Min-heap order property violated at index 5. (25 32 55 97 43 62 30 2 27 59 15 81 22 97 38 42)
Note: The C++ <algorithm> library includes a collection of functions that have to do with (binary) heaps. This includes make_heap() that rearranges the elements in an array or a vector so that it becomes a max-heap, and is_heap() that determines if an array or a vector satisfies the max-heap order property. In this zyLab, you are basically implementing a min-heap version of the is_heap() function yourself.
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//int INDEX = -1;

bool isMinHeap(const vector<int> input, int& index){
  bool conclusion = false;      //Variable used to determine if the vector passed is a min heap

  for(int i = 0; i < input.size(); i++){  //For loop to iterate through all the elements in the vector passed from main till we find a parent greater than a child.
    if( 2*i+1 <input.size()){
      if(input.at(i) > input.at(2*i+1)){
        index = i;
      }
    }
    if(2*i+2 < input.size()){
      if(input[i] > input[2*i+2]){
        index = i;
      }
    }

  }
  if(index == -1){     //This line is executed if we traverse the enire vector without finding a parent greater than both its children.

      conclusion = true;

    }
  return conclusion;
}

vector<string> split( string s , char delimiter )
{
    vector<string> tokens;          // vector of tokens
    string token;                   // a single token
    istringstream tokenStream(s);   // an input string stream

    // Tokenize s by grabbing individual tokens
    while( getline( tokenStream , token , delimiter ) )
        tokens.push_back(token);    // add found token

    return tokens;
}

int main(){
  vector<int> data;                 //Data vector will hold our data from standard input
  vector<string> dataS;
  string value;                        //Value will hold the data as it is entered and then push_back into data vector
  int number;
  while (getline(cin, value)){      //Get one line at a time from standard input
    dataS = split(value, ' '); //vector of strings
    int index = -1;
    for (int i = 0; i < dataS.size();i++) {//for each item in dataS push back converted value

    number = stoul(dataS[i]);
    data.push_back(number);            //Push back the values into the vector
}
    if(isMinHeap(data,index)){                //Determine if the vector we just created is a min Heap
      cout << "Vector is a min-heap." << endl;
      data.clear();
    }
    else
    if(index != -1 && isMinHeap(data,index) == false){
      cout << "Min-heap order property violated at index " << index << "." << endl;
      data.clear();
    }
  }




/*
  build_minheap(a, n);
  cout<<"Min Heap\n";
  for (i = 1; i <= n; i++) {
    cout<<a[i]<<endl;
  }
  getch();
*/


   return 0;
}
