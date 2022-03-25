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
//#include <conio.h>
using namespace std;

int INDEX = -1;

bool isMinHeap(const vector<int> input){
  bool conclusion = false;      //Variable used to determine if the vector passed is a min heap

  for(int i = input.front(); i < input.back(); i++){  //For loop to iterate through all the elements in the vector passed from main till we find a parent greater than a child.
    if(input.at(i) > input.at(2*i+1)){
      INDEX = 2*i+1;
    }
    if(input[i] > input[2*i+2]){
      INDEX = 2*i+2;
    }
    else{
      if(input.at(i)==input.back() && INDEX == -1){     //This line is executed if we traverse the enire vector without finding a parent greater than both its children.

        conclusion = true;

      }
    }
  }
  return conclusion;
}

int main(){
  vector<int> data;                 //Data vector will hold our data from standard input
  int value;                        //Value will hold the data as it is entered and then push_back into data vector

  while (getline(cin, value)){      //Get one line at a time from standard input
    data.push_back(value);            //Push back the values into the vector

    if(isMinHeap(data)){                //Determine if the vector we just created is a min Heap
      cout << "Vector is a min-heap." << endl;
    }
    else
    if(INDEX!= -1 && isMinHeap(data) == false){
      cout << "Min-heap order property violated at index " << INDEX << "." << endl;
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


  /*
  int i =0;
  while(input[i] < input[2*i+1] && input[i] < input[2*i+2] ){ //while the parent node is less than both of its children...
    i++;      //increment i to the next element to continue checking if the vector is a min heap.
  */


/*
void min_heap(int *a, int m, int n){
   int j, t;
   t= a[m];
   j = 2 * m;
   while (j <= n) {
      if (j < n && a[j+1] < a[j])
         j = j + 1;
      if (t < a[j])
         break;
      else if (t >= a[j]) {
         a[j/2] = a[j];
         j = 2 * j;
      }
   }
   a[j/2] = t;
   return;
}
void build_minheap(int *a, int n) {
   int k;
   for(k = n/2; k >= 1; k--) {
      min_heap(a,k,n);
   }
}
*/
