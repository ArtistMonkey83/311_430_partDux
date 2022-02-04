#include <iostream>

using namespace std;

// PROVIDED CODE ////////////////////////////////////////////////////////

#include "Node.h" // from Carrano & Henry 7/e (2017)

// Template function to insert an item into a linked list
template< class T >
void insert( Node<T>* &headPtr , const T& entry )
{
	// Create a new node and have the next pointer point to current front
	Node<T> *newNodePtr = new Node<T>( entry , headPtr );
	// Current front now becomes this new node
	headPtr = newNodePtr;
}

// Template function to display the contents of a linked list
template< class T >
void display( Node<T> *headPtr )
{
	Node<T> *currNodePtr = headPtr;
	while( currNodePtr ) // as long as not nullptr
	{
		cout << currNodePtr->getItem() << " ";
		currNodePtr = currNodePtr->getNext();
	}
  cout << endl;
}

// LAB CODE SOLUTION ////////////////////////////////////////////////////

// Template function that calculates the sum of the contents of a
// linked list (assumes we can add them together)
template< class T >
T sum( Node<T> *headPtr )
{
  T answer=0;
	Node<T> *currNodePtr = headPtr;
  while( currNodePtr )
  {
    answer += currNodePtr->getItem();
		currNodePtr = currNodePtr->getNext();
  }
  return answer;
}

// Template function that determines the maximum of the contents of a
// linked list (assumes we can add compare with ">" operator)
template< class T >
T findMax( Node<T> *headPtr )
{
	Node<T> *currNodePtr = headPtr;
  T answer = currNodePtr->getItem();
  while( currNodePtr )
  {
		currNodePtr = currNodePtr->getNext();
    if( currNodePtr )
       answer = ( currNodePtr->getItem()>answer ? currNodePtr->getItem() : answer );
  }
  return answer;
}

// Driver to read words from standard input (via cin) inserting
// them one at a time into an initially empty linked list.
// When input is exhausted, the contents of the linked list are
// displayed one word per line to standard output (via cout).

int main()
{
	// Declare a linked list of ints
	Node<int> *listOfIntegers = nullptr;

	// Read integers and insert each one into a linked list
	int data;
	while( cin >> data )
		insert( listOfIntegers , data );

	// Display the results
  if( listOfIntegers ) // non-empty
  {
	   cout << "Contents: ";
      display( listOfIntegers );
      cout << endl;
      cout << "Sum: " << sum( listOfIntegers ) << endl;
      cout << "Maximum: " << findMax( listOfIntegers ) << endl;
  }
  else
  {
      cout << "Contents: <EMPTY>" << endl;
  }

	return 0;
}
