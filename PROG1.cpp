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




//Function Prototypes

//Selection Sort implementation source Zybooks 5.5 c++: Selection sort
void SelectionSort(int* numbers, int numbersSize);

//insertion Sort source Zybooks 5.3 c++: Insertion sort
void InsertionSort(int* numbers, int numbersSize);

///RadixSort implementation source Zybooks 5.12 c++: Radix sort
int RadixGetLength(int value);

// Returns the maximum length, in number of digits, out of all array elements source Zybooks 5.12 c++: Radix sort
int RadixGetMaxLength(int* numbers, int numbersSize);

//source Zybooks 5.12 c++: Radix sort
void RadixSort(int* numbers, int numbersSize);

//Driving Function
int main() {

   ifstream sortfile;          // Create an input output object
   string dataFromFile;        // Create a string to read numbers into
   int data[1000000];          // An array capable of holding 1 million integers, required for C++ sorting algorithms
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
       data[i]=temp;                              // Store the converted element to our data array at index i
       dataVector.push_back(temp);                // Store the converted element to our dataVector, required to run sort()!

       i++;                                       // Increment our index so we know how many elements are in our data array
    }
   }
    sortfile.close();                             // When while loop is done processing our data from files we close the object

///////////SELECTION SORT
        auto startSS = high_resolution_clock::now();                    // Get starting timepoint for Selection Sort
        SelectionSort(data, i);                                         // Passing data array and i which holds the number of elements contained
        auto stopSS = high_resolution_clock::now();                     // Get the ending timepoint for Selection Sort
        auto SSspeed = duration_cast<nanoseconds>(stopSS - startSS);    // Calculate the duration of Selection Sort

//cout << "Random ss! "<< SSspeed.count() <<endl;                         // Print to the screen the time elasped in nanoseconds

//////////INSERTION SORT
        auto startIS = high_resolution_clock::now();                    // Get starting timepoint for Insertion Sort
        InsertionSort(data, i);                                         // Passing data array and i which holds the number of elements contained
        auto stopIS = high_resolution_clock::now();                     // Get the ending timepoint for Insertion Sort
        auto ISspeed = duration_cast<nanoseconds> (stopIS - startIS);   // Calculate the duration of Insertion Sort
//cout << "Random is! "<< ISspeed.count() <<endl;                         // Print to the screen the time elasped in nanoseconds

//////////RADIX SORT
        auto startRS = high_resolution_clock::now();                    // Get starting timepoint for Radix Sort
        RadixSort(data, i);                                             // Passing data array and i which holds the number of elements contained
        auto stopRS = high_resolution_clock::now();                     // Get the ending timepoint for Radix Sort
        auto RSspeed = duration_cast<nanoseconds> (stopRS - startRS);   // Calculate the duration of Radix Sort
//cout << "Random rs! "<< RSspeed.count() <<endl;                         // Print to the screen the time elasped in nanoseconds

//////////C++ SORT
        auto startCS = high_resolution_clock::now();                    // Get starting timepoint for C++ Sort
        sort(dataVector.begin(),dataVector.end());                      // Passing the begining and end of our dataVector
        auto stopCS = high_resolution_clock::now();                     // Get the ending timepoint for C++ Sort
        auto CSspeed = duration_cast<nanoseconds> (stopCS - startCS);   // Calculate the duration of C++ Sort
//cout << "Random cs! "<< CSspeed.count() <<endl;                         // Print to the screen the time elasped in nanoseconds

//////////////////////////
//////////////////////
//////////////////
//////////////            ASCENDING ORDER TEXT FILE PROCESS
//////////
//////
///

   sortfile.open( "ascending order.txt", ios::in);   //linking the sortfile object to a file

   if(sortfile.is_open()){

     while (!sortfile.eof()){

     sortfile >> dataFromFile;

    temp = stoi(dataFromFile);

     data[i]=temp;
     dataVector.push_back(temp);
     i++;

    }
   }
    sortfile.close();

     //SELECTION SORT
        //Get starting timepoint for Selection Sort
        startSS = high_resolution_clock::now();
        // Call the SelectionSort function
        SelectionSort(data, i); //pass vector with the info here
        //Get the ending timepoint for Selection Sort
        stopSS = high_resolution_clock::now();
        //Calculate the duration of Selection Sort
        SSspeed = duration_cast<nanoseconds>(stopSS - startSS);

cout << "Ascending ss! "<< SSspeed.count() <<endl;

//////////INSERTION SORT
        //Get starting timepoint for Insertion Sort
        startIS = high_resolution_clock::now();
        // Call the Insertion Sort function
        InsertionSort(data, i);
        //Get the ending timepoint for Insertion Sort
        stopIS = high_resolution_clock::now();
        //Calculate the duration of Insertion Sort
        ISspeed = duration_cast<nanoseconds> (stopIS - startIS);
cout << "Ascending is! "<< ISspeed.count() <<endl;

//////////RADIX SORT
        //Get starting timepoint for Radix Sort
        startRS = high_resolution_clock::now();
        // Call the RadixSort function
        RadixSort(data, i);
        //Get the ending timepoint for Radix Sort
        stopRS = high_resolution_clock::now();
        //Calculate the duration of Radix Sort
        RSspeed = duration_cast<nanoseconds> (stopRS - startRS);
cout << "Ascending rs! "<< RSspeed.count() <<endl;

//////////C++ SORT
        //Get starting timepoint for C++ Sort
        startCS = high_resolution_clock::now();
        // Call the C++ Sort function
        sort(dataVector.begin(),dataVector.end());
        //Get the ending timepoint for C++ Sort
        stopCS = high_resolution_clock::now();
        //Calculate the duration of C++ Sort
        CSspeed = duration_cast<nanoseconds> (stopCS - startCS);
        cout << "Ascending cs! "<< CSspeed.count() <<endl;

//////////////////////////
//////////////////////
//////////////////
//////////////
//////////
//////
///
//Descending Text File


   sortfile.open( "descending order.txt", ios::in);   //linking the sortfile object to a file

   if(sortfile.is_open()){

     while (!sortfile.eof()){

     sortfile >> dataFromFile;

    temp = stoi(dataFromFile);

     data[i]=temp;
     dataVector.push_back(temp);
     i++;

    }
   }
    sortfile.close();

     //SELECTION SORT
        //Get starting timepoint for Selection Sort
        startSS = high_resolution_clock::now();
        // Call the SelectionSort function
        SelectionSort(data, i); //pass vector with the info here
        //Get the ending timepoint for Selection Sort
        stopSS = high_resolution_clock::now();
        //Calculate the duration of Selection Sort
        SSspeed = duration_cast<nanoseconds>(stopSS - startSS);

cout << "Descending ss! "<< SSspeed.count() <<endl;

//////////INSERTION SORT
        //Get starting timepoint for Insertion Sort
        startIS = high_resolution_clock::now();
        // Call the Insertion Sort function
        InsertionSort(data, i);
        //Get the ending timepoint for Insertion Sort
        stopIS = high_resolution_clock::now();
        //Calculate the duration of Insertion Sort
        ISspeed = duration_cast<nanoseconds> (stopIS - startIS);
cout << "Descending is! "<< ISspeed.count() <<endl;

//////////RADIX SORT
        //Get starting timepoint for Radix Sort
        startRS = high_resolution_clock::now();
        // Call the RadixSort function
        RadixSort(data, i);
        //Get the ending timepoint for Radix Sort
        stopRS = high_resolution_clock::now();
        //Calculate the duration of Radix Sort
        RSspeed = duration_cast<nanoseconds> (stopRS - startRS);
cout << "Descending rs! "<< RSspeed.count() <<endl;

//////////C++ SORT
        //Get starting timepoint for C++ Sort
        startCS = high_resolution_clock::now();
        // Call the C++ Sort function
        sort(dataVector.begin(),dataVector.end());
        //Get the ending timepoint for C++ Sort
        stopCS = high_resolution_clock::now();
        //Calculate the duration of C++ Sort
        CSspeed = duration_cast<nanoseconds> (stopCS - startCS);
        cout << "Descending cs! "<< CSspeed.count() <<endl;

   return 0;
}



////////////
////////
/////        THE SORTING ALGORITHMS USED
///
//


//Selection Sort implementation source Zybooks 5.5 c++: Selection sort
void SelectionSort(int* numbers, int numbersSize) {
   for (int i = 0; i < numbersSize - 1; i++) {
      // Find index of smallest remaining element
      int indexSmallest = i;
      for (int j = i + 1; j < numbersSize; j++) {
         if (numbers[j] < numbers[indexSmallest]) {
            indexSmallest = j;
         }
      }

      // Swap numbers[i] and numbers[indexSmallest]
      int temp = numbers[i];
      numbers[i] = numbers[indexSmallest];
      numbers[indexSmallest] = temp;
   }
}

////////////
////////
/////
///
//Insertion Sort source Zybooks 5.3 c++: Insertion sort
void InsertionSort(int* numbers, int numbersSize) {
   for (int i = 1; i < numbersSize; i++) {
      int j = i;
      while (j > 0 && numbers[j] < numbers[j - 1]) {
         // Swap numbers[j] and numbers [j - 1]
         int temp = numbers[j];
         numbers[j] = numbers[j - 1];
         numbers[j - 1] = temp;
         j--;
      }
   }
}

////////////
////////
/////
///
///
///RadixSort implementation source Zybooks 5.12 c++: Radix sort
///
int RadixGetLength(int value) {
   if (value == 0) {
      return 1;
   }

   int digits = 0;
   while (value != 0) {
      digits++;
      value /= 10;
   }
   return digits;
}

// Returns the maximum length, in number of digits, out of all array elements
int RadixGetMaxLength(int* numbers, int numbersSize) {
   int maxDigits = 0;
   for (int i = 0; i < numbersSize; i++) {
      int digitCount = RadixGetLength(numbers[i]);
      if (digitCount > maxDigits) {
         maxDigits = digitCount;
      }
   }
   return maxDigits;
}

void RadixSort(int* numbers, int numbersSize) {
   vector<vector<int>*> buckets;
   for (int i = 0; i < 10; i++) {
      vector<int>* bucket = new vector<int>();
      buckets.push_back(bucket);
   }

   int copyBackIndex = 0;

   // Find the max length, in number of digits
   int maxDigits = RadixGetMaxLength(numbers, numbersSize);

   int pow10 = 1;
   for (int digitIndex = 0; digitIndex < maxDigits; digitIndex++) {
      // Put numbers into buckets
      for (int i = 0; i < numbersSize; i++) {
         int num = numbers[i];
         int bucketIndex = (abs(num) / pow10) % 10;
         buckets[bucketIndex]->push_back(num);
      }

      // Copy buckets back into numbers array
      copyBackIndex = 0;
      for (int i = 0; i < 10; i++) {
         vector<int>& bucket = *buckets[i];
         for (int j = 0; j < bucket.size(); j++) {
            numbers[copyBackIndex] = bucket[j];
            copyBackIndex++;
         }
         bucket.clear();
      }

      pow10 *= 10;
   }

   vector<int> negatives;
   vector<int> nonNegatives;
   for (int i = 0; i < numbersSize; i++) {
      int num = numbers[i];
      if (num < 0) {
         negatives.push_back(num);
      }
      else {
         nonNegatives.push_back(num);
      }
   }

   // Copy sorted content to array - negatives in reverse, then non-negatives
   copyBackIndex = 0;
   for (int i = negatives.size() - 1; i >= 0; i--) {
      numbers[copyBackIndex] = negatives[i];
      copyBackIndex++;
   }
   for (int i = 0; i < nonNegatives.size(); i++) {
      numbers[copyBackIndex] = nonNegatives[i];
      copyBackIndex++;
   }

   // Free each dynamically allocated bucket
   for (int i = 0; i < 10; i++) {
      delete buckets[i];
   }
}
