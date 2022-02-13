/*

5.15 LAB: Using the built-in C++ sort() and reverse() functions on a vector
Write a C++ program that

reads in an unknown number of integers into a vector;
displays the contents of the vector;
uses the built-in C++ sort() function to sort the vector in ascending order;
displays the vector contents in ascending order;
uses the built-in C++ reverse() function to reverse the contents of the vector; and
displays the vector contents in descending order.
*/

#include <iostream>
#include <algorithm> // for sort, reverse
#include <vector>

using namespace std;

int main()
{

// STEP 1: Read in an unknown number of integers into an integer vector.
vector<int> data;
int userInput;

/*
void display( vector<int> data)
{
  for( int i =0, i < data.size();i++)
  {
    cout << data[i] << endl;
  }
}
*/

while(cin >> userInput)
{
  data.push_back(userInput);
}

// STEP 2: Display the contents of the vector.
//display(data);
cout << "Original vector: "<< endl;
for( int i =0; i < data.size(); i++)
{
  cout << " " << data[i];
  //if (i == (data.size()-1)) { cout << endl;}
}
cout <<endl;

// STEP 3: Use the built-in C++ sort() function to sort in *ascending* order.
sort(data.begin(),data.end());

// STEP 4: Display the vector contents in *ascending* order.
//display(data);
cout << "Sorted (ascending) vector:" << endl;
for( int i =0; i < data.size(); i++)
{
  cout << " " << data[i];
  //if (i == (data.size()-1)) { cout << endl;}
}
cout <<endl;
// STEP 5: Use the built-in C++ reverse() function to reverse the contents of the vector.
reverse(data.begin(), data.end());

// STEP 6: Display the vector contents in *descending* order.
//display(data);
cout << "Sorted (descending) vector:"<< endl;
for( int i =0; i < data.size(); i++)
{
  cout << " " << data[i];
//  if (i == (data.size()-1)) { cout << endl;}
}
cout <<endl;
   return 0;
}
