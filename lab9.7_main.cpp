/*

9.7 LAB: Counting occurrences of words
Specifications
The objectives of this lab are:

to introduce you to the C++ map and multimap container classes;
to provide you with the experience of using a binary search tree data structure to solve a problem; and
to provide you with the opportunity to use iterators with the C++ associative containers to traverse the structure in the appropriate/required ways.
You will write a program that counts the number of occurrences of words in an unknown amount of text provided through standard input. The word frequencies will be reported with the highest frequency words first down to the lowest frequency words.

Note: Yes, this is the same problem we discussed in class as an example of how associative containers can be used to solve problems.

Input
There is an unknown amount of text provided from standard input.

Sample Input
we the people of the united states in order to form a more perfect union establish
justice insure domestic tranquility provide for the common defence promote the
general welfare and secure the blessings of liberty to ourselves and our posterity do
ordain and establish this constitution for the united states of america
Output
The output starts with the following heading: "Word Frequencies Report" which is then followed by the word frequencies and the corresponding word, separated by a single space character. Word frequencies should be displayed in descending order, with the highest frequency words appearing first. Words that have the same frequency must be displayed in ascending order.

Sample output, corresponding to the sample input above, is provided below.

Sample Output
Word Frequencies Report
6 the
3 and
3 of
2 establish
2 for
2 states
2 to
2 united
1 a
1 america
1 blessings
1 common
1 constitution
1 defence
1 do
1 domestic
1 form
1 general
1 in
1 insure
1 justice
1 liberty
1 more
1 ordain
1 order
1 our
1 ourselves
1 people
1 perfect
1 posterity
1 promote
1 provide
1 secure
1 this
1 tranquility
1 union
1 we
1 welfare
Note that due to the lexicographical ordering of strings (so uppercase characters come before lowercase characters), we will ignore case and any punctuation marks and leave them as part of a word. In the example above, all punctuation was removed and all characters were converted to lowercase.

Clearly, this problem can be solved with vectors and the use of the C++ sort function. The main point of this lab is to gain practice using the C++ associative containers.


if(!dictionary.insert(pair < string, int> (word, number)){                           //If we can't insert the word into the dictionary it already exists
  //number++;                                             //Increment a number and push that into the multimap?
  number = it -> first +1;
  wordCount.insert(pair <int,string>(number, word));      //Input is inserted into the multimap, multiple occurrences will be inserted
}



*/

#include <iostream>
#include <utility>    //pair and make_pair
#include <map>
#include <string>

using namespace std;

int main (){

  string word;                        //word holds the input from cin
  //int number;                         //no idea what this does..accumulate maybe.. its a number
  map<string, unsigned> dictionary;                     //This only holds a unique string and is a LIST OF FREQUENCIES
  multimap<unsigned,string,greater<int>> wordCount;     //This holds multiple strings, not unique, key represents the number of occurrences this is the OUTPUT

  while (cin >> word){          //While we have standard input save it to word

    if (dictionary.count(word)){                //check to see if the word already exists in the dictionary map
      dictionary[word] = dictionary[word]+1;   //increment the integer value in pair to reflect the number of occurences this line executes because the word is already in the map
    }//it -> second ++ look at notes
    else
      dictionary.insert(pair <string,int> (word, 1));  //Input is also inserted into the map, with 1 because it is the first occurence

  }

  for(auto it = dictionary.begin(); it != dictionary.end();it++){   //Populate the multimap using the beginging and end iterators

    wordCount.insert(pair<int,string>(it -> second,it ->first));    //insert the values from map into the multimap second holds the occurence and first holds the word

  }


  cout << "Word Frequencies Report" << endl;                  //Print the title of the output
  for(auto it = wordCount.rbegin(); it != wordCount.rend(); it++){ //Iterate through dictionary to print word? or do we iterate through wordCount and print occurrences and words?

    if (it->first == next(it)->first){     //while the current element's occurence count is equal to the next elements occurence count, print alphabetically
      while (it->second > next(it)->second){    //condition checking what comes first in alphabetic order

        cout  << next(it)->first << " " << next(it)->second << endl;
        it= next(it);

        if (it->second < next(it)->second){
        cout << it->first << " " << it->second<< endl;
        }
      }
    }
    else
    cout << it->first << " " << it->second << endl;           //Print the first element in wordCount which is the number of occurences, and the second which is the word
  }

  return 0;
}
