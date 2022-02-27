
/*
15.1 PROG 1: What type of sorting algorithm is used by the built-in C++ template function?
This lab will be available until May 31st, 11:59 PM PDT
Overview
The goal of this programming assignment is to confirm the efficiency of the sorting algorithm used by C++ in its built-in sort() template function that is included in the algorithm header of the C++ Standard Library. In order to do this, you will conduct a careful empirical study of the relative performance of sorting algorithms using three datasets (e.g. random, sorted in ascending order, sorted in descending order).
Your work will include the following tasks:
Implement two (2) fundamental and one (1) advanced sorting algorithm we discussed in class. You may use the code given in our zyBooks subscription to do this, or any other C++ implementation you find online, as long as you reference/acknowledge your source(s) in your code and in your report.
Conduct experiments to compare the actual execution times of the sorting algorithms in comparison with the sort() template function. Use the chrono header file to determine the actual execution times.
Plot the results of your experiments, showing the performance of all four(4) implementations on a single chart, and draw conclusions regarding the sort() template function and how it may be implemented.
alt text
There will be two (2) required deliverables for this programming assignment:
your fully documented (with comments) C++ code you used to conduct your experiments, submitted through this zyLab; and
a detailed report, in PDF, showing the results of your experiments, charts/plots showing the relative performance of the four (4) sorting algorithm implementations you are comparing, and any conclusions you made based on these results --- this report will be submitted through Gradescope.
For full credit, your PDF report must, at the least, include the following:
The title of your report (you can use the title of this PROG).
Your name, our course prefix and number, and the date of your submission.
Identify and briefly describe the features of the two (2) fundamental and the one (1) advanced sorting algorithm you selected for this experiment. Reference all sources for the implementations you are using.
Explain your experimental design (what type of data are you using; identify any limitations) and how you plan to determine the type of algorithm you believe the sort() template function is using. Provide a hypothesis.
Present a chart showing a plot of the actual execution times for all four (4) implementations based on varying values for N.
Provide your conclusions and support them with your results.
For information on how to create charts, you may refer to the following:
"Create a chart from start to finish," Microsoft Support pages.
"How to create a graph in Google Sheets," J. Lloyd, WikiHow.
You can use the numeric datasets provided in this zyLab for your experiments or generate and use your own.
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    //To use sort()
#include <chrono>       //To keep track of time in nanoseconds
#include <fstream>      //To read from a file

using namespace std;
using namespace std::chrono;

//////////////////////////
//////////////////////
//////////////////
//////////////            SORTING ALGORITHM FUNCTION PROTOTYPES
//////////
//////
///

void SelectionSort(int* numbers, int numbersSize);      // Selection Sort implementation source Zybooks 5.5 c++: Selection sort
void InsertionSort(int* numbers, int numbersSize);      // Insertion Sort source Zybooks 5.3 c++: Insertion sort

int RadixGetLength(int value);                          // RadixSort implementation source Zybooks 5.12 c++: Radix sort
int RadixGetMaxLength(int* numbers, int numbersSize);   // Returns the maximum length, in number of digits, out of all array elements source Zybooks 5.12 c++: Radix sort
void RadixSort(int* numbers, int numbersSize);          // Source Zybooks 5.12 c++: Radix sort

//////////////////////////
//////////////////////
//////////////////
//////////////            DRIVING FUNCTION FOR PROG1
//////////
//////
///

int main() {

   ifstream sortfile;          // Create an input output object
   string dataFromFile;        // Create a string to read numbers into
   int dataArray[1000000];          // An array capable of holding 1 million integers, required for C++ sorting algorithms
   int i =0;                   // Accumulator for number of items in an array, must start at 0!
   int temp;                   // Holds converted to integer values from a string
   vector<int> dataVector;     // Vector to hold our data for use in the sort()

//////////////////////////
//////////////////////
//////////////////
//////////////            RANDOM ORDER TEXT FILE PROCESS
//////////
//////
///

   sortfile.open( "random order.txt", ios::in);   // Linking the sortfile object to a file of integers

   if(sortfile.is_open()){                        // If we correctly opened the above file then......

     while (!sortfile.eof()){                     // While we are not at the end of the linked file in line 86.....

       sortfile >> dataFromFile;                  // Read an element from the linked file in line 86 to a string

       temp = stoi(dataFromFile);                 // Convert the element read in line 92 to an integer and save it temporarily
       dataArray[i]=temp;                         // Store the converted element to our dataArray at index i
       dataVector.push_back(temp);                // Store the converted element to our dataVector, required to run sort()!

       i++;                                       // Increment our index so we know how many elements are in our dataArray
    }
   }
    sortfile.close();                             // When while loop is done processing our data from files we close the object

///////////SELECTION SORT
        auto startSS = high_resolution_clock::now();                    // Get starting timepoint for Selection Sort
        SelectionSort(dataArray, i);                                    // Passing dataArray and i which holds the number of elements contained
        auto stopSS = high_resolution_clock::now();                     // Get the ending timepoint for Selection Sort
        auto SSspeed = duration_cast<nanoseconds>(stopSS - startSS);    // Calculate the duration of Selection Sort
//cout << "Random ss! "<< SSspeed.count() <<endl;                         // Print to the screen the time elapsed in nanoseconds

//////////INSERTION SORT
        auto startIS = high_resolution_clock::now();                    // Get starting timepoint for Insertion Sort
        InsertionSort(dataArray, i);                                    // Passing data array and i which holds the number of elements contained
        auto stopIS = high_resolution_clock::now();                     // Get the ending timepoint for Insertion Sort
        auto ISspeed = duration_cast<nanoseconds> (stopIS - startIS);   // Calculate the duration of Insertion Sort
//cout << "Random is! "<< ISspeed.count() <<endl;                         // Print to the screen the time elapsed in nanoseconds

//////////RADIX SORT
        auto startRS = high_resolution_clock::now();                    // Get starting timepoint for Radix Sort
        RadixSort(dataArray, i);                                        // Passing data array and i which holds the number of elements contained
        auto stopRS = high_resolution_clock::now();                     // Get the ending timepoint for Radix Sort
        auto RSspeed = duration_cast<nanoseconds> (stopRS - startRS);   // Calculate the duration of Radix Sort
//cout << "Random rs! "<< RSspeed.count() <<endl;                         // Print to the screen the time elapsed in nanoseconds

//////////C++ SORT
        auto startCS = high_resolution_clock::now();                    // Get starting timepoint for C++ Sort
        sort(dataVector.begin(),dataVector.end());                      // Passing the beginning and end of our dataVector
        auto stopCS = high_resolution_clock::now();                     // Get the ending timepoint for C++ Sort
        auto CSspeed = duration_cast<nanoseconds> (stopCS - startCS);   // Calculate the duration of C++ Sort
//cout << "Random cs! "<< CSspeed.count() <<endl;                         // Print to the screen the time elapsed in nanoseconds

        i = 0;           // Resetting our index variable to 0
//////////////////////////
//////////////////////
//////////////////
//////////////            ASCENDING ORDER TEXT FILE PROCESS
//////////
//////
///

sortfile.open( "ascending order.txt", ios::in); // Linking the sortfile object to a file of integers

if(sortfile.is_open()){                        // If we correctly opened the above file then......

  while (!sortfile.eof()){                     // While we are not at the end of the linked file in line 141.....

    sortfile >> dataFromFile;                  // Read an element from the linked file in line 141 to a string

    temp = stoi(dataFromFile);                 // Convert the element read in line 147 to an integer and save it temporarily
    dataArray[i]=temp;                         // Store the converted element to our dataArray at index i
    dataVector.push_back(temp);                // Store the converted element to our dataVector, required to run sort()!

    i++;                                       // Increment our index so we know how many elements are in our dataArray
 }
}
 sortfile.close();                             // When while loop is done processing our data from files we close the object

///////////SELECTION SORT
     startSS = high_resolution_clock::now();                    // Get starting timepoint for Selection Sort
     SelectionSort(dataArray, i);                               // Passing dataArray and i which holds the number of elements contained
     stopSS = high_resolution_clock::now();                     // Get the ending timepoint for Selection Sort
     SSspeed = duration_cast<nanoseconds>(stopSS - startSS);    // Calculate the duration of Selection Sort
//cout << "Random ss! "<< SSspeed.count() <<endl;                         // Print to the screen the time elapsed in nanoseconds

//////////INSERTION SORT
     startIS = high_resolution_clock::now();                    // Get starting timepoint for Insertion Sort
     InsertionSort(dataArray, i);                               // Passing dataArray and i which holds the number of elements contained
     stopIS = high_resolution_clock::now();                     // Get the ending timepoint for Insertion Sort
     ISspeed = duration_cast<nanoseconds> (stopIS - startIS);   // Calculate the duration of Insertion Sort
//cout << "Random is! "<< ISspeed.count() <<endl;                         // Print to the screen the time elapsed in nanoseconds

//////////RADIX SORT
     startRS = high_resolution_clock::now();                    // Get starting timepoint for Radix Sort
     RadixSort(dataArray, i);                                   // Passing dataArray and i which holds the number of elements contained
     stopRS = high_resolution_clock::now();                     // Get the ending timepoint for Radix Sort
     RSspeed = duration_cast<nanoseconds> (stopRS - startRS);   // Calculate the duration of Radix Sort
//cout << "Random rs! "<< RSspeed.count() <<endl;                         // Print to the screen the time elapsed in nanoseconds

//////////C++ SORT
     startCS = high_resolution_clock::now();                    // Get starting timepoint for C++ Sort
     sort(dataVector.begin(),dataVector.end());                 // Passing the beginning and end of our dataVector
     stopCS = high_resolution_clock::now();                     // Get the ending timepoint for C++ Sort
     CSspeed = duration_cast<nanoseconds> (stopCS - startCS);   // Calculate the duration of C++ Sort
//cout << "Random cs! "<< CSspeed.count() <<endl;                         // Print to the screen the time elapsed in nanoseconds

      i = 0;             // Resetting our index variable to 0
//////////////////////////
//////////////////////
//////////////////
//////////////            DESCENDING ORDER TEXT FILE PROCESS
//////////
//////
///

sortfile.open( "descending order.txt", ios::in);   // Linking the sortfile object to a file of integers

if(sortfile.is_open()){                        // If we correctly opened the above file then......

  while (!sortfile.eof()){                     // While we are not at the end of the linked file in line 86.....

    sortfile >> dataFromFile;                  // Read an element from the linked file in line 194 to a string

    temp = stoi(dataFromFile);                 // Convert the element read in line 200 to an integer and save it temporarily
    dataArray[i]=temp;                              // Store the converted element to our data array at index i
    dataVector.push_back(temp);                // Store the converted element to our dataVector, required to run sort()!

    i++;                                       // Increment our index so we know how many elements are in our data array
  }
}
  sortfile.close();                             // When while loop is done processing our data from files we close the object

///////////SELECTION SORT
      startSS = high_resolution_clock::now();                    // Get starting timepoint for Selection Sort
      SelectionSort(dataArray, i);                               // Passing dataArray and i which holds the number of elements contained
      stopSS = high_resolution_clock::now();                     // Get the ending timepoint for Selection Sort
      SSspeed = duration_cast<nanoseconds>(stopSS - startSS);    // Calculate the duration of Selection Sort
//cout << "Random ss! "<< SSspeed.count() <<endl;                         // Print to the screen the time elapsed in nanoseconds

//////////INSERTION SORT
      startIS = high_resolution_clock::now();                    // Get starting timepoint for Insertion Sort
      InsertionSort(dataArray, i);                               // Passing dataArray and i which holds the number of elements contained
      stopIS = high_resolution_clock::now();                     // Get the ending timepoint for Insertion Sort
      ISspeed = duration_cast<nanoseconds> (stopIS - startIS);   // Calculate the duration of Insertion Sort
//cout << "Random is! "<< ISspeed.count() <<endl;                         // Print to the screen the time elapsed in nanoseconds

//////////RADIX SORT
      startRS = high_resolution_clock::now();                    // Get starting timepoint for Radix Sort
      RadixSort(dataArray, i);                                   // Passing dataArray and i which holds the number of elements contained
      stopRS = high_resolution_clock::now();                     // Get the ending timepoint for Radix Sort
      RSspeed = duration_cast<nanoseconds> (stopRS - startRS);   // Calculate the duration of Radix Sort
//cout << "Random rs! "<< RSspeed.count() <<endl;                         // Print to the screen the time elapsed in nanoseconds

//////////C++ SORT
      startCS = high_resolution_clock::now();                    // Get starting timepoint for C++ Sort
      sort(dataVector.begin(),dataVector.end());                 // Passing the beginning and end of our dataVector
      stopCS = high_resolution_clock::now();                     // Get the ending timepoint for C++ Sort
      CSspeed = duration_cast<nanoseconds> (stopCS - startCS);   // Calculate the duration of C++ Sort
//cout << "Random cs! "<< CSspeed.count() <<endl;                         // Print to the screen the time elapsed in nanoseconds
//cout << "Number of integers in file" << i << endl;                      // Calculate how many values are in our list
   return 0;
}

////////////
////////
/////        THE SORTING ALGORITHMS, SOURCE ZYBOOKS 2022
///
//

//Selection Sort implementation source Zybooks 5.5 c++: Selection sort
void SelectionSort(int* numbers, int numbersSize) {
   for (int i = 0; i < numbersSize - 1; i++) {        // For loop to iterate through all the elements in dataArray

      int indexSmallest = i;                          // Find index of smallest remaining element in dataArray
      for (int j = i + 1; j < numbersSize; j++) {     // Comparing the i+1 (next) element in dataArray with current smallest
         if (numbers[j] < numbers[indexSmallest]) {   // If we find a number that is < current smallest
            indexSmallest = j;                        // Update the value in our indexSmallest variable to properly reflect the smallest value
         }
      }

      int temp = numbers[i];                          // Swap numbers[i] and numbers[indexSmallest]
      numbers[i] = numbers[indexSmallest];
      numbers[indexSmallest] = temp;
   }
}

//Insertion Sort source Zybooks 5.3 c++: Insertion sort
void InsertionSort(int* numbers, int numbersSize) {
   for (int i = 1; i < numbersSize; i++) {              // For loop to iterate through all the elements in dataArray
      int j = i;                                        // Variable for holding the comparison index
      while (j > 0 && numbers[j] < numbers[j - 1]) {    // While j is a valid dataArray index AND element at j is less then the one at previous index....

         int temp = numbers[j];                         // Swap numbers[j] and numbers [j - 1]
         numbers[j] = numbers[j - 1];
         numbers[j - 1] = temp;
         j--;
      }
   }
}

//RadixSort implementation source Zybooks 5.12 c++: Radix sort
int RadixGetLength(int value) {             // This function finds the number of iterations Radix needs to perform to sort elements
   if (value == 0) { return 1; }            // If the length of an element is 0 we don't have a valid element we are done!

   int digits = 0;                          // digits accumulates the number of places an element in dataArray has
   while (value != 0) {                     // While we are accessing a valid element in dataArray......
      digits++;                             // Increment digits to reflect the maximum place value of elements in dataArray
      value /= 10;                          // We are using base ten values so we divide by 10!
   }
   return digits;                           // Return the maximum number of value places an element in dataArray contains
}

int RadixGetMaxLength(int* numbers, int numbersSize) {  // Returns the maximum length, in number of digits, out of all dataArray elements
   int maxDigits = 0;                                   // maxDigits holds the element found with the most value places
   for (int i = 0; i < numbersSize; i++) {              // For loop to iterate through the entire dataArray
      int digitCount = RadixGetLength(numbers[i]);      // Function call returns the value found in process starting on line 280
      if (digitCount > maxDigits) {                     // If the next element in dataArray has more place values than previous digitCount.....
         maxDigits = digitCount;                        // Update maxDigits to correctly reflect the maximum place values Radix will manage
      }
   }
   return maxDigits;                                    // maxDigits holds the highest number of place values found in dataArray
}

void RadixSort(int* numbers, int numbersSize) {   // RadixSort is a bucket sorting algorithm that using place values to determine
   vector<vector<int>*> buckets;                  // Declaring the buckets for a base ten 0-9 RadixSort
   for (int i = 0; i < 10; i++) {                 // For loop which will iterate through all ten buckets
      vector<int>* bucket = new vector<int>();    // Creating a bucket to hold multiple values of the same assessed integer
      buckets.push_back(bucket);                  // This allows us to have multiple elements with the same assessed integer value in a group
   }

   int copyBackIndex = 0;

   int maxDigits = RadixGetMaxLength(numbers, numbersSize);             // Find the max length, in number of digits

   int pow10 = 1;                                                       // Start at the ones value place, this is a base ten RadixSort
   for (int digitIndex = 0; digitIndex < maxDigits; digitIndex++) {     // For loop that iterates while our element is less than maxDigits
      for (int i = 0; i < numbersSize; i++) {                           // For loop to put numbers into buckets
         int num = numbers[i];                                          // num holds the current element being assessed
         int bucketIndex = (abs(num) / pow10) % 10;                     // bucketIndex assigns the value of the particular place value we are assessing
         buckets[bucketIndex]->push_back(num);                          // Push the current element being assessed into the proper bucket
      }

      copyBackIndex = 0;                                                // Copy buckets back into numbers array
      for (int i = 0; i < 10; i++) {                                    // This is base ten RadixSort so i ranges from 0-9
         vector<int>& bucket = *buckets[i];
         for (int j = 0; j < bucket.size(); j++) {                      // Starting at 0 we copy the element back into the dataArray which is
            numbers[copyBackIndex] = bucket[j];                         // Known as numbers locally in the RadixSort algorithm
            copyBackIndex++;                                            // Increment the bucket index to move to next bucket to copy back
         }
         bucket.clear();
      }

      pow10 *= 10;                                                      // Base 10, we will properly assess next place value with *=10
   }

   vector<int> negatives;                                               // RadixSort bucket sort doesn't differentiate between negative values
   vector<int> nonNegatives;                                            // nonNegatives will contain non negative values for RadixSort to assess
   for (int i = 0; i < numbersSize; i++) {                              // For loop that will iterate through dataArray, locally known as numbers
      int num = numbers[i];                                             // Local variable to hold the value of an element in dataArray
      if (num < 0) { negatives.push_back(num); }                        // If the element being assessed is negative..... Push that item into the appropriate vector negatives
      else { nonNegatives.push_back(num); }                             // Otherwise the element being assessed is pushed into nonNegatives vector
   }

   copyBackIndex = 0;                                                   // Copy sorted content to array - negatives in reverse, then non-negatives
   for (int i = negatives.size() - 1; i >= 0; i--) {                    // For loop to iterate through the negatives values first
      numbers[copyBackIndex] = negatives[i];                            // Assigning dataArray, locally known as numbers, with negative values first
      copyBackIndex++;                                                  // Increment index to travers through all elements in dataArray/numbers
   }
   for (int i = 0; i < nonNegatives.size(); i++) {                      // For loop to iterate through the non negative values next
      numbers[copyBackIndex] = nonNegatives[i];                         // Assigning dataArray, locally known as numbers, with non negative values next
      copyBackIndex++;                                                  // Increment index till we arrive at the end of nonNegatives vector
   }

   for (int i = 0; i < 10; i++) { delete buckets[i]; }                  // Free each dynamically allocated bucket
}
