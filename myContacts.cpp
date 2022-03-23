#include <iostream>
#include <fstream>

using namespace std;

int main() {
string userInput; //Variable to hold from standard in the name of the file a user wants to process
vector <vector<string>> stringFromFile;   //Holds the value of a getline() from a linked file
char caseID;            //string to hold a line from file containing the operation to be performed on a contact list
string command;           //String variable that will hold just the command (element[0]) part of the string.    
ifstream listOfContacts,  //Stream class object to link contact list files to read from
         listOfCommands;  //Stream class object to link command list files to read from


cout << "Enter a file with extension for proessing: ";    //Prompt for the name of the file we want to process
cin >> userInput;                                         //Save from standard input the name the user wants to process


listOfContacts.open("userInput");  //Linking the ifstream object to the proper contact list file for processing
if(listOfContacts.is_open()){    //Returns true if there is a stream object (contact list) associated with an open file

  while(!listOfContacts.eof()){        //While we are not at the end of the linked file..
    stringFromFile.push_back(split(getline(listOfContacts),','); //Tokenize a line from the linked file stopping at a space, and save it into a vector of strings
                                                                  //The input files have five data elements seperated by , so we pass that delimiter to the split function. Inputs are first name, last name, birth month, birth day, and birth year.
                                                                  //The result is stringFromFile[0,5,10] == FN stringFromFile[1,6,11] == LN stringFromFile[2,7,12] == BM stringFromFile[3,8,13] == BD stringFromFile[4,9,14] ==BY etc...



  } //After this while loop ends we have successfully pushed back all contacts one line at a time, each contact contains five data elements for one contact
  cout << "Enter a command file with extension for performing work on the file of contacts: ";
  cin >> userInput;

  listOfCommands.open("userInput");   //Linking the ifstream object to the proper command file to perform work on a contact list
  if(listOfCommands.is_open()){       //Returns true if thre is a stream object (command list) associated with an open file
    while(!listOfCommands.eof()){     //While we are not at the end of the commands list...
      caseID= split(getline(userInput),',');  //Tokenize a line from the linked file stopping at a space and splitting at commas WILL THIS ACTUALY WORK?
      caseID= get() ///This will extract one character from the file, could I use this?

//processing each instruction in the commands file
      switch(tolower(caseID))
      {
        case a:                     /*
                                    A record : Add a new record to the contact list. A new record will be provided using the same format as a record  in the input data file (see above); for example: A Alice,Barber,3,14,1993
                                    */


        case d:                   /*
                                  D key : Delete the unique record from the contact list with a key value (last name) indicated by key. Display the matching record that is deleted. If multiple records match the given key, display all such records but do not delete any of them. Display an error message if the record is not found. Compare with Remove below. Per the description of the remove operation in the Database abstract class, the key can have two values, separated by commas, indicating the last name and the first name of a particular contact to delete (just in case there are duplicate records with the same last name). Examples:
                                        D Garcia
                                        D Garcia,Bobby
                                  */


        case f:                   /*
                                  F key : Find the record(s) from the contact list with a key value (last name) indicated by key. Display the record(s) that match the given key; otherwise, display an error message if no record(s) match the given key. Example:
                                      F Smith
                                  */


        case r:                   /*
                                  R key : Remove all records from the contact list with a key value (last name) indicated by key. Display all matching records that are deleted. Display an error message if no record matches the given key. Compare with Delete above. Example:
                                      R Wright
                                  */


        case s:                   /*
                                  S : Show all the contacts. The contacts will be displayed based on the ordering managed by the balanced binary search tree index of the contacts' last names. If multiple contacts have the same last name, these contacts are displayed in order by their first name. Example:
                                        S
                                  */


      }

    }
  }

//save to contacts.out
ofstream contactsOut;  //stream class object to write to file
contactsOut.open("contacts.out");
countactsOut << stringFromFile;
contactsOut.close();
listOfContacts.close();
listOfCommands.close();

}

   return 0;
}
