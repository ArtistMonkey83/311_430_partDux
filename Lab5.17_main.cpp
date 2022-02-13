/*

5.17 LAB: Using sort() on a vector of structs
How does the built-in C++ sort() function deal with a container of structs?

The code given below does not compile. The program correctly sets up a vector of structs but somehow the built-in C++ sort() function does not know how to compare two structs. What do we need to do?

Edit the code given below so that, once completed, your C++ program will

read in an unknown number of grocery items (each with a name, a unit price, and a quantity) into a vector [DONE];
displays the contents of the vector [DONE];
uses the built-in C++ sort() function to sort the vector in ascending order;
displays the vector contents in ascending order;
uses the built-in C++ reverse() function to reverse the contents of the vector; and
displays the vector contents in descending order.
Note: Unlike the other LAB similar to this, when we sort the grocery items, they are sorted by unit price first, and then by their name next.

sort by price first, then if the price is the same we will sort by name. what did we learn about structs.
*/

#include <iostream>
#include <iomanip>
#include <algorithm> // for sort, reverse
#include <vector>
#include <tuple>
#include <string>

using namespace std;

// User-defined type item that is a struct
// representing items in a grocery list.
struct item
{
   string   name;
   double   unitPrice;
   unsigned count;
};

template< typename T >
void display( const vector< T > &L )
{
   for( auto x: L )
   {
      cout << setw(4) << x.count
           << setw(10) << x.name
           << setw(6) << setprecision(2) << fixed << x.unitPrice
           << endl;
   }
}

bool sortByName(item a, item b)
{
  if(a.unitPrice == b.unitPrice) { return (a.name <b.name);}
  return (a.unitPrice < b.unitPrice);
}

// DRIVER FUNCTION

int main()
{

// STEP 1: Read in an unknown number of grocery items into a
//         vector of structs.

   vector<item> myList;
//struct is like a class but everything is public, tuple is just data
//
   string name;
   //typedef tuple<string,double,unsigned> item;

   while (cin >> name)
   {
     double price;
     cin >> price;
     unsigned quantity;
     cin >> quantity;
     struct item first;
     first.name=name;
     first.unitPrice=price;
     first.count=quantity;

     myList.push_back(first);
   }


// STEP 2: Display the grocery items stored in the vector in the
//         order they were read in.
  cout << "Original list: "<<endl;
  display(myList);
  cout <<endl;
// STEP 3: Use the built-in C++ sort() function to sort in *ascending* order.
  sort(myList.begin(), myList.end(),sortByName); // I am missing my begining and ending index (.begin/.end)

// STEP 4: Display the vector contents in *ascending* order.
  cout << "Sorted (ascending) list:"<<endl;
  display(myList);
  cout <<endl;
// STEP 5: Use the built-in C++ reverse() function to reverse the contents of the vector.
  reverse(myList.begin(), myList.end());

// STEP 6: Display the vector contents in *descending* order.
  cout << "Sorted (descending) list:"<<endl;
  display(myList);
  cout <<endl;

   return 0;
}
