/*

In this lab, you will get to use the empirical method of algorithm analysis; in particular, you will be using the computer's system clock to determine how much time an iterative version of the algorithm took to complete a task versus a recursive version of the algorithm. We will use the Fibonacci sequence as a basis for the algorithms you will be implementing.

The Fibonacci sequence begins with 0 and then 1 follows. All subsequent values are the sum of the previous two, for example: 0, 1, 1, 2, 3, 5, 8, 13. You will implement two functions: one called fibR() that uses recursion, and one called fibI() that uses iteration, to calculate the nth value in the Fibonacci sequence. Normally, n>=0, but both functions will return -1 if n is negative.

When you implement both functions, make sure you are testing to confirm that they are calculating the same value for a given n. For example, if the value for n provided is 7 then both functions should calculate and return 13.

Your program takes a single numeric input, say n, and then determines what is the nth number in the Fibonacci sequence. Your program will use both your fibR() and fibI() functions to determine the answer, and your program will also calculate how much time each function took to calculate the answer and report which version was faster.

Note: For this lab, when comparing execution times empirically, we will keep the clock resolution at the microseconds level.

Input
As indicated above, the expected input is a single numeric value.

Sample Input
Numeric values are assumed to be integers. Refer to this input value as n.

7
Output
Your program will report the value of the nth element in the Fibonacci sequence and which one of the two algorithms was faster.

Sample Output
For the Sample Input given above, the expected output would be:

Fibonacci(7) is 13
fibI() was faster
*/


#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;
//using namespace std::chrono;

// Calculate the nth value in the Fibonacci sequence
// using recursion. DO NOT use loops!
int fibR(int n)
{

   /* Type your code here. */
   if (n == 0)
      return 0;
   if (n < 0)
      return -1;
   else if (n == 1)
      return 1;
   else
      return fibR(n - 1) + fibR(n - 2);
}

// Calculate the nth value in the Fibonacci sequence
// using iteration. Math formula Fn=(Fn−1+Fn−2), where n > 1
int fibI(int n)
{

   /* Type your code here. */
   if (n == 0)
      return 0;
   if (n < 0)
      return -1;
   int  first=0, second=1, nextTerm = 0;
   for (int i =1; i<n; i++)
   {
     nextTerm = first + second;
     first = second;
     second = nextTerm;
   }
   return nextTerm;
}


int main()
{

   /* Type your code here. */
   int userInput;
   cin>>userInput;
   // Get starting timepoint for fibR()
   auto startI = high_resolution_clock::now();

   fibR(userInput);

   // Get ending timepoint
   auto stopI = high_resolution_clock::now();

   // Get duration. Substart timepoints to
   // get durarion. To cast it to proper unit
   // use duration cast method
   auto fibRSpeed = duration_cast<microseconds>(stopI - startI);
   //printf(fibRSpeed.count());



   // Get starting timepoint for fibI()
   auto startR = high_resolution_clock::now();

   fibI(userInput);

   // Get ending timepoint
   auto stopR = high_resolution_clock::now();

   // Get duration. Substart timepoints to
   // get durarion. To cast it to proper unit
   // use duration cast method
   auto fibISpeed = duration_cast<microseconds>(stopR - startR);
   //printf(fibISpeed.count());

   //while (fibI(userInput)==fibR(userInput))
   //cout<< "Fibonacci I(" << userInput << ") is " << fibI(userInput) << endl;
   //cout<< "Fibonacci R(" << userInput << ") is " << fibR(userInput) << endl;
   //if (fibISpeed < fibRSpeed)
   //cout << "fibI() was faster";
  cout << "Fibonacci(" << userInput << ") is " << fibR(userInput) << endl;
  //cout << "fibISpeed == " << fibISpeed; << endl;
  //cout << "fibRSpeed == "<< fibRSpeed;


  if (fibRSpeed.count() < fibISpeed.count())
  cout << "fibR() was faster";
  if ((fibISpeed)==(fibRSpeed))
  cout << "fibR() and fibI() were tied";
  else
  cout << "fibI() was faster";

   return 0;
}
