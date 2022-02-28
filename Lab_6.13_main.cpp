/*

6.13 Using a user-defined Binary Search Tree class
This lab will be available until March 1st, 11:59 PM PST
In this lab, you will work with a user-defined Binary Search Tree (BST) class.

Specifications
Make sure you spend some time reading the documentation provided in the BinarySearchTree class provided in the file BinarySearchTree.h below. You will use the provided binary search tree operations to accomplish the following:

Declare a BinarySearchTree object that can contain integers.
Read in an unknown number of integers, from standard input, terminated by a zero value. Each integer should be inserted into your BST object.
Display the following BST information about your BST object:
height of the tree
the number of nodes in the tree
the results of the three binary tree traversals (only if the tree is non-empty)
the sum of all the nodes in the tree
The output should be followed by a blank line. Next, your program will read in an unknown number of integers from standard input, and each integer should be deleted from your BST object.

After all the deletions are completed, your program should report the number of successful remove() operations performed followed by the BST information displayed before the deletes (see above).

Next, you need to double the value of each node in the BST object, display the message "Doubling tree node values …" and then, for the last time, the BST information displayed twice earlier.

Input
There are two sets of input: integers to be inserted into an initially empty BST object, and integers to be deleted from this same BST object. These integers are separated by a 0.

Sample Input
In the sample provided below, the integers 10, 20, 30, 40, 50, 60, 70, and 80 are inserted into an initially empty BST object.

10 20 30 40 50 60 70 80 0 20 25 35 40 55 60 80
The integers 20, 25, 35, 40, 55, 60, and 80 are deleted from the same BST object.

Output
Per the specifications provided above, the only output your program produces are the BST information indicated above. This information is displayed right after all the integers have been inserted into the BST object, and then again after all the remove() operations have been performed and the number of successful remove()'s are reported.

Next, the message "Doubling tree node values …" is displayed, then after the value of each node in the BST object is doubled, for the final time, the BST information is displayed once more.

Sample Output
For the sample input provided above, the output should be:

Tree height = 7
Number of nodes: 8
 10 20 30 40 50 60 70 80
 10 20 30 40 50 60 70 80
 80 70 60 50 40 30 20 10
Sum of node values = 360

4 successful remove() operations performed.
Tree height = 3
Number of nodes: 4
 10 30 50 70
 10 30 50 70
 70 50 30 10
Sum of node values = 160

Doubling tree node values ...
Tree height = 3
Number of nodes: 4
 20 60 100 140
 20 60 100 140
 140 100 60 20
Sum of node values = 320
Notice that although there are 7 remove() operations requested from the input, only 4 of them are applicable to the BST object and so only 4 are successful.

Other requirements
To fulfill the requirements of this lab, you must also implement the following template functions that are to be used as the visit() function passed as a parameter to the tree traversal operations:

display(): function that displays a space character followed by the value of the parameter passed;
addThis(): function that adds the value of the parameter passed to a running total; and
doubleThis(): function that doubles the value of the parameter passed.
Carefully consider how you would implement the addThis() function. It needs to be used when calculating the sum of all the nodes in the BST object.

*/
#include <iostream>
#include "BinaryNodeTree.h"
#include "BinarySearchTree.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcep.h"

//Global Variable to pass into visit functions
int sum= 0,
    removeCount = 0;
//user defined visit function to print item
template< class ItemType>
void display(ItemType& data)
{
  cout << " " << data;
}

//user defined visit function to add this item
template< class ItemType>
void addThis(ItemType& data)
{
  //int sum;
  //cout << accumulator << "accumulator " <<endl;
  //cout << data << "data" << endl;
  sum = sum + data;
  //cout << accumulator << "total is " <<endl;
}


//user defined visit function to double this item
template< class ItemType>
void doubleThis(ItemType& data)
{
  data = data *2;
  //cout << " " << data * 2;
}

using namespace std;

int main()
{
//Declare a BinarySearchTree object that can contain integers.
  BinarySearchTree<int> cedar;

  int userInput;
  int cased=0;
  cin >> userInput;

//Read in an unknown number of integers, from standard input, terminated by a zero value. Each integer should be inserted into your BST object.
  if (userInput == 0) { cased += 1;}
  else if (userInput!=0) cased += 2;
//cout << cased;
    while(userInput != 0)
    {
      cedar.add(userInput);
      cin >> userInput;
    }


/*Display the following BST information about your BST object:
//height of the tree
//the number of nodes in the tree
//the results of the three binary tree traversals (only if the tree is non-empty)
//the sum of all the nodes in the tree
//The output should be followed by a blank line.

Tree height = 7
Number of nodes: 8
 10 20 30 40 50 60 70 80 inorder
 10 20 30 40 50 60 70 80 preorder
 80 70 60 50 40 30 20 10 postorder
Sum of node values = 360

*/
if (cased==1){

          cout << "Tree height = " << (cedar.getHeight() - 1) << endl;
          cout << "Number of nodes: " << cedar.getNumberOfNodes() << endl;
          cedar.preorderTraverse(display);

          cedar.inorderTraverse(display);

          cedar.postorderTraverse(display);

          cedar.inorderTraverse(addThis);
          cout << "Sum of node values = " << sum << endl <<endl;

          sum = 0;

  //Read in an unknown number of integers from standard input, and each integer should be deleted from your BST object.
            if (userInput == 0)
            {
              while (cin >> userInput)
              if(cedar.remove(userInput))
              {removeCount++;}

            }
  //After all the deletions are completed, your program should report the number of successful remove() operations performed followed by the BST information displayed before the deletes (see above).
  /*
  4 successful remove() operations performed.
  Tree height = 3
  Number of nodes: 4
   10 30 50 70
   10 30 50 70
   70 50 30 10
  Sum of node values = 160

  */
            cout << removeCount << " successful remove() operations performed." <<endl;

            cout << "Tree height = " << (cedar.getHeight() - 1) << endl;
            cout << "Number of nodes: " << cedar.getNumberOfNodes() << endl;
            cedar.preorderTraverse(display);

            cedar.inorderTraverse(display);

            cedar.postorderTraverse(display);

            cedar.inorderTraverse(addThis);
            cout << "Sum of node values = " << sum << endl<<endl;

            sum = 0;
//Next, you need to double the value of each node in the BST object, display the message "Doubling tree node values …" and then, for the last time, the BST information displayed twice earlier.

/*
Doubling tree node values ...
Tree height = 3
Number of nodes: 4
 20 60 100 140
 20 60 100 140
 140 100 60 20
Sum of node values = 320

*/

            cout << "Doubling tree node values ..." <<endl;

            cout << "Tree height = " << (cedar.getHeight() - 1) << endl;
            cout << "Number of nodes: " << cedar.getNumberOfNodes() << endl;
            cedar.preorderTraverse(doubleThis);
            cedar.preorderTraverse(display);

    //cedar.inorderTraverse(doubleThis);
            cedar.inorderTraverse(display);
    //cedar.inorderTraverse(display);

    //cedar.postorderTraverse(doubleThis);
            cedar.postorderTraverse(display);

            cedar.inorderTraverse(addThis);
            cout << "Sum of node values = " << sum << endl << endl;

}

if(cased ==2)
{
    cout << "Tree height = " << (cedar.getHeight() - 1) << endl;
    cout << "Number of nodes: " << cedar.getNumberOfNodes() << endl;
    cedar.preorderTraverse(display);
    cout << endl;
    cedar.inorderTraverse(display);
    cout << endl;
    cedar.postorderTraverse(display);
    cout << endl;
    cedar.inorderTraverse(addThis);
    cout << "Sum of node values = " << sum << endl <<endl;

    sum = 0;

    //Read in an unknown number of integers from standard input, and each integer should be deleted from your BST object.
      if (userInput == 0)
      {
        while (cin >> userInput)
        if(cedar.remove(userInput))
        {removeCount++;}

      }
  //After all the deletions are completed, your program should report the number of successful remove() operations performed followed by the BST information displayed before the deletes (see above).
  /*
  4 successful remove() operations performed.
  Tree height = 3
  Number of nodes: 4
   10 30 50 70
   10 30 50 70
   70 50 30 10
  Sum of node values = 160

  */
      cout << removeCount << " successful remove() operations performed." <<endl;

      cout << "Tree height = " << (cedar.getHeight() - 1) << endl;
      cout << "Number of nodes: " << cedar.getNumberOfNodes() << endl;
      cedar.preorderTraverse(display);
      cout << endl;
      cedar.inorderTraverse(display);
      cout << endl;
      cedar.postorderTraverse(display);
      cout << endl;
      cedar.inorderTraverse(addThis);
      cout << "Sum of node values = " << sum << endl<<endl;

      sum = 0;
//Next, you need to double the value of each node in the BST object, display the message "Doubling tree node values …" and then, for the last time, the BST information displayed twice earlier.

/*
Doubling tree node values ...
Tree height = 3
Number of nodes: 4
 20 60 100 140
 20 60 100 140
 140 100 60 20
Sum of node values = 320

*/

      cout << "Doubling tree node values ..." <<endl;

      cout << "Tree height = " << (cedar.getHeight() - 1) << endl;
      cout << "Number of nodes: " << cedar.getNumberOfNodes() << endl;
      cedar.preorderTraverse(doubleThis);
      cedar.preorderTraverse(display);
      cout << endl;
    //cedar.inorderTraverse(doubleThis);
      cedar.inorderTraverse(display);
    //cedar.inorderTraverse(display);
      cout << endl;
    //cedar.postorderTraverse(doubleThis);
      cedar.postorderTraverse(display);
      cout << endl;
      cedar.inorderTraverse(addThis);
      cout << "Sum of node values = " << sum << endl << endl;

    }







   return 0;
}
