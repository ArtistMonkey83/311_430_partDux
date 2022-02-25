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
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono:




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

string ArrayToString(int* array, int arraySize) {
   // Special case for empty array
   if (0 == arraySize) {
      return string("[]");
   }

   // Start the string with the opening '[' and element 0
   string result = "[" + to_string(array[0]);

   // For each remaining element, append comma, space, and element
   for (int i = 1; i < arraySize; i++) {
      result += ", ";
      result += to_string(array[i]);
   }

   // Add closing ']' and return result
   result += "]";
   return result;
}

//insertion Sort source Zybooks 5.3 c++: Insertion sort
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

string ArrayToString(int* array, int arraySize) {
   // Special case for empty array
   if (0 == arraySize) {
      return string("[]");
   }

   // Start the string with the opening '[' and element 0
   string result = "[" + to_string(array[0]);

   // For each remaining element, append comma, space, and element
   for (int i = 1; i < arraySize; i++) {
      result += ", ";
      result += to_string(array[i]);
   }

   // Add closing ']' and return result
   result += "]";
   return result;
}

///
///RadixSort implementation source Zybooks 5.12 c++: Radix sort
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

string ArrayToString(int* array, int arraySize) {
   // Special case for empty array
   if (0 == arraySize) {
      return string("[]");
   }

   // Start the string with the opening '[' and element 0
   string result = "[" + to_string(array[0]);

   // For each remaining element, append comma, space, and element
   for (int i = 1; i < arraySize; i++) {
      result += ", ";
      result += to_string(array[i]);
   }

   // Add closing ']' and return result
   result += "]";
   return result;
}


//selection sort main
int main() {
   // Creat a string to read numbers into
   string dataFromFile;

   fstream sortfile;
   sortfile.open( "numbers-50k-random.txt", ios::in);

   if(sortfile.is_open()){                  //check that we have valid file open
     while(getline(sortfile,dataFromFile)){ //do stuff with the file's data if it is open

     //SELECTION SORT
        //Get starting timepoint for Selection Sort
        auto startSS = high_resolution_clock::now();
        // Call the SelectionSort function
        SelectionSort(sortfile, sortfile.size());
        //Get the ending timepoint for Selection Sort
        auto stopSS = high_resolution_clock::now();
        //Calculate the duration of Selection Sort
        auto SSspeed = duration_cast<microseconds>(stopSS - startSS);

     //INSERTION SORT
        //Get starting timepoint for Insertion Sort
        auto startIS = high_resolution_clock::now();
        // Call the Insertion Sort function
        InsertionSort(sortfile,  sortfile.size());
        //Get the ending timepoint for Insertion Sort
        auto stopIS = high_resolution_clock::now();
        //Calculate the duration of Insertion Sort
        auto ISspeed = duration_cast<microseconds> (stopIS - startIS);

     //RADIX SORT
        //Get starting timepoint for Radix Sort
        auto startRS = high_resolution_clock::now();
        // Call the RadixSort function
        RadixSort(sortfile,  sortfile.size());
        //Get the ending timepoint for Radix Sort
        auto stopRS = high_resolution_clock::now();
        //Calculate the duration of Radix Sort
        auto RSspeed = duration_cast<microseconds> (stopRS - startRS);

     }

     sortfile.close();


   }
   return 0;
}
