/*

8.8 LAB: Implementing the Cartesian product for sets
Specifications
In the branch of mathematics called set theory, the Cartesian product of two sets A and B, denoted A×B, is the set of all ordered pairs (a,b) where a is an element of A and b is an element of B. This can also be written in set notation as

A×B = { (a,b) where a∈A and b∈B }

In this lab, you will implement the Cartesian product as a template function that will work with C++ set objects containing any type. Additionally, you will overload the insertion operator, <<, to work with sets of various types. You are to implement

a template function called cartesianProduct() that builds and returns a set object that contains the Cartesian product of two set objects of unknown types;
an overload of operator<< to "display" the elements in a set object; and
an overload of operator<< to "display" an item representing an element from a Cartesian product as an ordered pair.
Although your driver will work on particular set types, your implementations need to be template functions so that they are generic enough for multiple uses.

Input
All input comes from standard input. Input consists of a pair of lines. Each line in a pair consists of an unknown number of elements in a set. The first set consists of strings and the second set consists of integers. Each element in a set is separated by a single space character.

Note that the types used in this specification only pertain to a particular driver/client code used to test your program.

Sample Input
alpha bravo
1 2 3
Output
Since we are dealing with sets, your output will conform to how sets are identified in the mathematical sense. Your program first displays the elements in each of the sets A and B provided as input, one in each line (see the Sample Output provided below). Then, it displays the elements in the Cartesian product A×B on the third line and the elements in the Cartesian product B×A on the fourth line.

Items in a set are separated by a single comma (no spaces). Each line is terminated by a single end-of-line character. Sample output, corresponding to the sample input above, is provided below.

Sample Output
Given: A={alpha,bravo} first overloaded opperator
       B={1,2,3}
Then AxB={(alpha,1),(alpha,2),(alpha,3),(bravo,1),(bravo,2),(bravo,3)} second overloaded opperator
     BxA={(1,alpha),(1,bravo),(2,alpha),(2,bravo),(3,alpha),(3,bravo)}

*/
#include <tuple>
#include <set>
#include <string>
#include <iterator>
#include <iostream>
#include <vector>
#include "string_tools.h"
using namespace std;



/////
////  FUNCTION DECLARATIONS
/////

//Template function to implement a Cartesian product, we will overload the << operator to properly display
template <typename T, typename S>
set<tuple <T,S>> cartesianProduct(const set<T> stringData, const set<S> numberData)
{
  //create my set of tuples
  set<tuple<T,S>> product;
  for (auto stringElement : stringData){
    for ( auto numberElement : numberData){
      auto cartTuple =  make_tuple( stringElement, numberElement);
      //inserting to set
      product.insert(cartTuple);
    }
  }

  return product;//set
}

///template class operator overloading for displaying one set of data
template<typename T>
ostream& operator<< (ostream &os, const set<T>& setData) //os become buffer where we push in the characters
{ int counter=0;
  for(auto setElement : setData){
    if(counter == setData.size()-1){
      os << setElement;
    }
    else{
      os << setElement << ",";
    }
    counter++;
  }


  return os; //os is a buffer that needs the data returned so the driver can do stuff with it
}
//template class operator second overloaded << operator for displaying a tuple of sets
template<typename T, typename S>
ostream& operator<< (ostream &os,const tuple <T,S>& data) //ostream is for out put only
{
  int counter=0;
  //only one for loop and get<0>(name of tuple)
  for(auto setElement : data){
    if (counter == data.size()-1) {
      os << "(" << get<0>(setElement) << ","<< get<1>(setElement)<< ")";
    } //data is a set and setElement is an element in the set which is a tuple

    else{
      os << "(" << get<0>(setElement) << ","<< get<1>(setElement)<< "),";
    }
    counter++;
  }


  return os; //os is a buffer that needs the data returned so the driver can do stuff with it
}
/////
////  DRIVING PROGRAM
/////

int main(){

  string userInputT;
  int userInputS;
  set <string> setA;
  set <int> setB;
  //tuple<typename T> pairedData;

//getline is only for strings and cin for integers
getline(cin,userInputT);

vector<string> word = split(userInputT, ' ');

for(int i = 0; i<word.size();i++)
    setA.insert(word.at(i));

    while(cin >> userInputS){
      setB.insert(userInputS);
    }


  cout << "Given: A={" << setA << "}" << endl;
  cout << "       B={" << setB <<"}" << endl;

  cout << "Then AxB={" << cartesianProduct(setA,setB) << "}" << endl;
  cout << "     BxA={" << cartesianProduct(setB,setA) << "}" << endl;

  return 0;
}
