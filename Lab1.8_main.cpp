// In this zyLab, you will design a couple of template functions
// that will be used to work for linked lists of different types.
// We will be using the predefined Node class (Carrano & Henry, 2017)
// to create and maintain our linked lists.

#include <iostream>
#include <string>

using namespace std;

#include "Node.h" // from Carrano & Henry 7/e (2017)

// Template function to insert an item into a linked list
// by inserting it at the front/head of the list.

//////////// Insert your code here
template <class T>
void insert(Node<T>* &list, const T& insertValue) ///to pass address use & to pass by reference
{
  //Create a node to hold the insertvalue we pass dont forget the types!
Node<T> *newNode = new Node<T>(insertValue,list);
//newNode->setNext = (*list);        //this takes the starting address value for the linked list and moves it to the "next node in list" position
list = newNode;               //this moves the address of the head of the list to the new node we created, updating the list to the proper headptr
}


// Template function to display the contents of a linked list
// one item per line.

// Insert your code here
template<typename T>
 T printList(Node<T>* list)  //the function takes the pointer to a list for printing & will screw it up!
 {
   Node<T>* currNode = list;
   while(currNode != nullptr) //as long as there is a node
   { cout << currNode -> getItem() << endl;
     currNode = currNode -> getNext();
   }
   //else
   //cout << "This is an empty list. \n";
 }

// Driver to read words from standard input (via cin) inserting
// them one at a time into an initially empty linked list.
// When input is exhausted, the contents of the linked list are
// displayed one word per line to standard output (via cout).

int main()
{
	// 1) Declare a linked list of integers called iList
	//    and initialize it to nullptr.

   // Insert your code here
Node<int>* iList = nullptr;     //declaring a pointer to a node of type integer named iList


	// 2) Declare a linked list of strings called sList
	//    and initialize it to nullptr.

   // Insert your code here
Node<string>* sList = nullptr;   //declaring a pointer to a node of type string class named sList

	// 3) Read integers from standard input (cin) and use
	//    the insert() function above to insert them into iList.
	//    Input will be of the form N x1 x2 x3 ... xN where
	//    N is the number of integers followed by the N integers
	//    x1, x2, x3, ..., xN.

   // Insert your code here
int idata,numInts,numStrings;
cin >> numInts;
//cout << "numInts ==" << numInts <<endl;

//while (cin >>idata)
//for ( int i = 0; i == numInts; i++){insert(iList,idata);}

do {
  cin >> idata;
  insert(iList,idata);
  numInts-=1;
} while(numInts>0);  // Keeps reading values from cin into data
 //Insert that data into the integer list

cin >>numStrings;
//cout << "numStrings=="<< numStrings <<endl;
	// 4) Display the message "Integers:" on a single line
	//    followed by the contents of iList.

   // Insert your code here

//if (iList->getItem == nullptr) {break;} // if the list is empty don't print Integers title
cout << "Integers: "<< endl;       // beginning of the integer list
printList(iList);
//while(iList != nullptr) //while there is an item in the linked list execute this loop
//{
//  int iresults = iList->getItem();
//  cout << iresults << endl;
//}
	// 5) Read strings from standard input (cin) and use
	//    the insert() function above to insert them into sList.
	//    Input will be of the form M s1 s2 s3 ... sM where
	//    M is the number of strings followed by the M strings
	//    s1, s2, s3, ..., sM.

   // Insert your code here
string sdata;

while( cin >> sdata)   // Keeps reading values from cin into data
{
  insert(sList,sdata); //Insert that data into the string list

}
	// 6) Display the message "Strings:" on a single line
	//    followed by the contents of iList.
cout << "Strings:" << endl;
printList(sList);
   // Insert your code here
//if (sList->getItem() == nullptr) {return 0;} // if the list is empty don't print Integers title
//cout << "Integers: \n";       // beginning of the integer list
//while(sList!= nullptr) //while there is an item in the linked list execute this loop
//{
  //string sresults = sList->getItem();
  //cout << sresults << endl;
//}

	return 0;
}
