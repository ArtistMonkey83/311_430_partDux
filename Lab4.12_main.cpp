#include <iostream>
#include "Node.h"

using namespace std;

// Function to insert an item into the front of a linked list
template< class T >
void insert( Node<T>* &headPtr , const T& entry )
{
 // Create a new node and have the next pointer point to current front
 Node<T> *newNodePtr = new Node<T>( entry , headPtr );
 // Current front now becomes this new node
 headPtr = newNodePtr;
}

// Recursive function to remove an item from a linked list
// Returns true if the operation was done; false, otherwise
template< typename T >
bool remove( Node<T>*  &nodePtr , T target )
{
 // YOUR CODE GOES HERE
 if(nodePtr == nullptr/* || nodePtr->getNext() == nullptr*/) {return false;}  //the list is empty we are done and we didn't find the target
 if(nodePtr -> getItem() == target)
 {
	 Node<T> *temp = nodePtr; //sets the node
   //nodePtr->setNext(temp); // I am not actually deleting the target node
   nodePtr= nodePtr->getNext();

   delete temp;
   return true;            //when we get to the end of the list we then delete the node and return true
 }


  Node<T> *temp =  nodePtr->getNext();  //this holds the value of the node we are trying to relink
  bool result = remove(temp,target );    //recursive call to the next pointer in the list, this will continue till we reach the end of the linked list or find the target
  nodePtr->setNext(temp); //the recursive call sets nodePtr to the next item after the item removed
  return result; //true or false depending on if we removed.this is set by the if statement and then returned to main.
}//update previous pointer if remove actually happened
//delete the node
//use nodeptr passed by reference to use the temp copy back into nodePtr

// Recursive function to display the contents of a linked list
// in the reverse order.
template< class T >
void display( Node<T> *currNodePtr )
{
	//Node<T> *temp = currNodePtr->getNext();// what if it is empty? dereferencing a null pointer
 // YOUR CODE GOES HERE - CHECK YOUR NOTES!
 if(currNodePtr )  //while the list is NOT empty
  {
   display( currNodePtr->getNext() );// );     //recursive call to the next item in the list, this will continue till we reach the end of the linked list displaying as we go along
   cout<< " " <<currNodePtr->getItem();
   //cout << endl;
  }

}

int main()
{
 // (1) Declare an empty linked list of unsigned values
 //     based on the Node class and call it myList

 Node<unsigned > *myList = nullptr;

 // (2) Read in values from standard input. Non-negative
 //     values are inserted into myList and a negative
 //     value terminates input.

 int userInput;
 cin >> userInput;

 while(userInput>=0) //reading in input before we go into a loop we need positive values in the while
   {
     insert(myList,(unsigned)userInput);
     cin >> userInput;


   } //type cast it as unsigned when calling


 // (3) Display the contents of the linked list myList
 //     in the order they were entered (hence, the display()
 //     function displays myList in reverse order!

 cout << "Contents:"<< endl;
 display(myList);

 // (4) Read in values from standard input. Non-negative
 //     values are removed from myList and a negative
 //     value terminates input.

 cin >> userInput;
 while(userInput >= 0 ) {
   remove(myList,(unsigned)userInput);
   cin >> userInput;
   } // type cast this userInput when calling


 // (5) Display the contents of the linked list myList
 //     in the order they were entered (hence, the display()
 //     function displays myList in reverse order!

 cout << endl << "After remove() operations:"<<endl;
 display(myList);

 return 0;
}
