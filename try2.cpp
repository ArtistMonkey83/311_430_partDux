/*
In this lab, you will try to determine how to implement a linked list operation recursively. In particular, you will implement the following operations recursively:
display() will display the contents of a linked list in reverse order; since the provided insert() functions inserts items at the front of the list, the items will be in reverse order, so to print them in the correct order the list will be displayed in reverse; and
remove() will remove a target value from the linked list if it is in the list; otherwise, it does nothing to the list.
The function prototypes for these functions are provided in main.cpp below. Instructions for this zyLab are also provided as comments in main.cpp below.
Design your function main() so that input is provided as two lists of unsigned integers terminated by a negative value. Hence, the following input:
1 2 3 4 5 -1 1 3 5 -1
means the list will contain the values 1, 2, 3, 4, 5 and the values 1, 3, and 5 will be removed from the list, resulting in the list containing the values 2, 4.
Your function main() should display the original list, perform the removes, and then display the list again after all the remove operations have completed. So, for the sample input above, your program's output should be:
Contents:
 1 2 3 4 5
After remove() operations:
 2 4
*/


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
	if(nodePtr == nullptr) {return false;}  //the list is empty we are done and we didn't find the target
	else{
		if(nodePtr -> getItem() == target)
		{
			nodePtr->setNext(nodePtr ->getNext());
			return true;												//when we get to the end of the list we then delete the node and return true
		}
	}
	return remove( nodePtr->getNext(),target );				//recursive call to the next pointer in the list, this will continue till we reach the end of the linked list or find the target
	//return false;
}

// Recursive function to display the contents of a linked list
// in the reverse order.
template< class T >
void display( Node<T> *currNodePtr )
{
	// YOUR CODE GOES HERE - CHECK YOUR NOTES!
	if(currNodePtr )		//while the list is NOT empty
		{
			cout<< currNodePtr->getItem();
			display( currNodePtr->getNext() );					//recursive call to the next item in the list, this will continue till we reach the end of the linked list displaying as we go along
		}
}

int main()
{
	// (1) Declare an empty linked list of unsigned values
	//     based on the Node class and call it myList
	Node<unsigned> *myList = nullptr;


	// (2) Read in values from standard input. Non-negative
	//     values are inserted into myList and a negative
	//     value terminates input.
	//int removeItems = 0;
	unsigned userInput;
	cin >> userInput;

	if(userInput>=0) //reading in input before we go into a loop we need positive values in the while
			{insert(myList,userInput);}

	//do { insert(myList,userInput;) } while (userInput>=0)



/*		if(userInput < 0)	//we want to terminate adding to the list if it is a negative number
		{
				removeItems +=;//we don't manipulate the list but we need to know if we need to remove or not
		}
		else if(removeItems == 0)	//we have not recieved the first negative value from user so keep adding to list
			myList->setItem(userInput); //if userInput is a non negative number we add it to the list
		else if (removeItems > 0 && removeItems < 3)		//we arrive at this line if we have completed added to myList, and the user has passed a negative number
		{
			remove(myList, userInput);	//we execute this line when we have already populated myList and need to remove an item
		}
		*/




	// (3) Display the contents of the linked list myList
	//     in the order they were entered (hence, the display()
	//     function displays myList in reverse order!
	cout << "Contents: /n";
	display(myList);


	// (4) Read in values from standard input. Non-negative
	//     values are removed from myList and a negative
	//     value terminates input.
	cin >> userInput;
	if(userInput >= 0 ) { remove(myList,userInput);}
	//do { remove(myList,userInput); } while (userInput>=0);

	// (5) Display the contents of the linked list myList
	//     in the order they were entered (hence, the display()
	//     function displays myList in reverse order!
	cout << "After remove() operations:/n";
	display(myList);



	return 0;
}
