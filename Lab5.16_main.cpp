/*

5.16 LAB: Using the built-in C++ sort() and reverse() functions on a vector of tuples
How does the built-in C++ sort() function deal with tuples? Which field/attribute does it sort on?

To answer this question, you will write a C++ program that

reads in an unknown number of grocery items (each with a name, a unit price, and a quantity) into a vector;
displays the contents of the vector;
uses the built-in C++ sort() function to sort the vector in ascending order;
displays the vector contents in ascending order;
uses the built-in C++ reverse() function to reverse the contents of the vector; and
displays the vector contents in descending order.
*/

#include <iostream>
#include <iomanip>
#include <algorithm> // for sort, reverse
#include <vector>
#include <tuple>
#include <string>

using namespace std;

typedef tuple< string , double , unsigned > item;

template< typename T >
void display( const vector< T > &L )
{
   string name;
   double unitPrice;
   unsigned count;

   for( auto item: L )
   {
      tie( name , unitPrice , count ) = item;
      cout << setw(4) << count
           << setw(8) << name
           << setw(6) << setprecision(2) << fixed << unitPrice
           << endl;
   }
}


// DRIVER FUNCTION

int main()
{

// STEP 1: Read in an unknown number of grocery items into a vector.
  string name;
  vector <item> buffer;
  while (cin >> name)
  {
    double price;
    cin >> price;
    unsigned quantity;
    cin >> quantity;
    item first = make_tuple(name,price,quantity);
    buffer.push_back(first);
  }

// STEP 2: Display the grocery items stored in the vector.
  cout << "Original list: "<< endl;
  display(buffer);
  cout << endl;
// STEP 3: Use the built-in C++ sort() function to sort in *ascending* order.
  sort(buffer.begin(), buffer.end());


// STEP 4: Display the vector contents in *ascending* order.
  cout << "Sorted (ascending) list:"<< endl;
  display(buffer);
  cout << endl;

// STEP 5: Use the built-in C++ reverse() function to reverse the contents of the vector.
  reverse(buffer.begin(), buffer.end());

// STEP 6: Display the vector contents in *descending* order.
  cout << "Sorted (descending) list:"<< endl;
  display(buffer);
  cout << endl;

   return 0;
}
