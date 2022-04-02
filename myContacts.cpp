#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include "ContactList.h"
#include "Conact.h"

using namespace std;

int main() {
string userInput; //Variable to hold from standard in the name of the file a user wants to process
vector <vector<string>> stringFromFile;   //Holds the value of a getline() from a linked file

int counter = 0;        //Variable to hold the number of contacts loaded into a contact list object
char caseID;            //string to hold a line from file containing the operation to be performed on a contact list
string command;           //String variable that will hold just the command (element[0]) part of the string.
set<contact> foundData;   //Object to hold found contacts
ifstream listOfContacts,  //Stream class object to link contact list files to read from
         listOfCommands;  //Stream class object to link command list files to read from
Contactlist blackbook;
//Contact newContact;

cout << "Enter a file with extension for proessing: ";    //Prompt for the name of the file we want to process
cin >> userInput;                                         //Save from standard input the name the user wants to process


listOfContacts.open(userInput);  //Linking the ifstream object to the proper contact list file for processing
if(listOfContacts.is_open()){    //Returns true if there is a stream object (contact list) associated with an open file

  while(!listOfContacts.eof()){        //While we are not at the end of the linked file..
    stringFromFile.push_back(split(getline(listOfContacts),','); //Tokenize a line from the linked file stopping at a space, and save it into a vector of strings
                                                                  //The input files have five data elements seperated by , so we pass that delimiter to the split function. Inputs are first name, last name, birth month, birth day, and birth year.
                                                                  //The result is stringFromFile[0,5,10] == FN stringFromFile[1,6,11] == LN stringFromFile[2,7,12] == BM stringFromFile[3,8,13] == BD stringFromFile[4,9,14] ==BY etc...
    Contact newContact = stringFromFile;                    //Populating Conact object with data from standard input that is saved to stringFromFile
    blackbook.insert(newContact)//Inserting the newContact to our contactList object blackbook
    blackbook.guidebook(stringFromFile[0]);   //Adding the lastName to the multimap associated with our contactList object blackbook
    counter++;    //Increamenting the counter for tracking how many contacts are in the contact list container

  } //After this while loop ends we have successfully pushed back all contacts one line at a time, each contact contains five data elements for one contact

  cout << "Loaded " << counter << " records into the contact list." << endl;
  //save to contacts.out
  ofstream contactsOut;  //stream class object to write to file
  contactsOut.open(userInput + ".out"); //This will append the .out extension, will be able to find the orginal input file as its extension will be included
  countactsOut << stringFromFile;

  cout << "Enter a command file with extension for performing work on the file of contacts: ";
  cin >> userInput;

  listOfCommands.open(userInput);   //Linking the ifstream object to the proper command file to perform work on a contact list
  if(listOfCommands.is_open()){       //Returns true if thre is a stream object (command list) associated with an open file
    while(!listOfCommands.eof()){     //While we are not at the end of the commands list...
      getline(cin, command);          //Cin the line from linked command file object, this line caputures input up to a white space!
      caseID = command[0];            //Since the operation is the [0] element in the string command we set the char variable caseID to this element. This extracts just the operation to be performed.
      stringFromFile = split(command, ',');    //Splits the current line in command up by commas.
                                          //stringFromFile[1] == LN stringFromFile[2] == BM stringFromFile[3] == BD stringFromFile[4] ==BY
//processing each instruction in the commands file one getline() at a time
      switch(tolower(caseID))
      {
        case a:                     /*
                                    A record : Add a new record to the contact list. A new record will be provided using the same format as a record  in the input data file (see above); for example: A Alice,Barber,3,14,1993
                                    */
                    for(int it = 1; it < stringFromFile.size(); it++)    //Starting at elemnt[1] till the last element in the string...
                    blackbook.add(stringFromFile[it]);       //Add the elements [1]-[4] by dereferencing an iterator (pointer) of the stringFromFile variable.
                    cout << "New contact added "<< endl << "  " << stringFromFile[1] << " " << stringFromFile[2] << ", " << stringFromFile[3] << "/" << stringFromFile[4] <<  stringFromFile[5] << endl;
                    //or do I cout << getEntry(it)?
                    stringFromFile.clear(); //Reset our vector after processing the line
                    break;

        case d:                   /*
                                  D key : Delete the unique record from the contact list with a key value (last name) indicated by key. Display the matching record that is deleted. If multiple records match the given key, display all such records but do not delete any of them. Display an error message if the record is not found. Compare with Remove below. Per the description of the remove operation in the Database abstract class, the key can have two values, separated by commas, indicating the last name and the first name of a particular contact to delete (just in case there are duplicate records with the same last name). Examples:
                                        D Garcia
                                        D Garcia,Bobby
                                  */
                    for(int it =1; it < stringFromFile.size(); it++)    //Starting at elemnt[1] till the last element in the string...
                    blackbook.remove(it)       //Remove the elements [1]-[4] by dereferencing an iterator (pointer) of the stringFromFile variable.
                    if(blackbook.remove(it)==true){ //this if statement is executed if we find only one contact with the last name provided by the user
                      cout << "Delete " << "\"" << stringFromFile[2] << "\""<< endl;
                      cout << "  " << stringFromFile[1] << " " << stringFromFile[2] << ", " << stringFromFile[3] << "/" << stringFromFile[4] << "/" << stringFromFile[5] << endl;
                      cout << "Done." << endl;
                    }

                    if(blackbook.remove(it)==false){    //this if statement is executed if we find more then one contact with the last name provided by the user
                      foundData.insert( blackbook.getEntry(stringFromFile[2]));   //Set that holds a subset of our contact list that match the last name currently in stringFromFile[1]
                      cout << "Delete " << "\"" << stringFromFile[2] << "\""<< endl;
                      cout << "Multiple matches for \"" << stringFromFile[2] << "\""<< endl;
                      for(int i = 0; i < foundData.size(); i++){  //We need to iterate through our set to print out all the entries we found that match the current last name in stringFromFile[1]
                        cout << " " << foundData[i].getFirstName() << " " << foundData[i].getLastName() << ", " << foundData[i].getBirthMonth() << "/" << foundData[i].getBirthDay() << "/" << foundData[i].getBirthYear() << endl;

                      }
                      cout << " Not done." << endl;
                    }
                    stringFromFile.clear(); //Reset our vector after processing the line
                    break;

        case f:                   /*
                                  F key : Find the record(s) from the contact list with a key value (last name) indicated by key. Display the record(s) that match the given key; otherwise, display an error message if no record(s) match the given key. Example:
                                      F Smith
                                  */
                    cout << "Find \"" << stringFromFile[2] << "\"" << endl;

                    for(int i = 0; i < blackbook.size(); i++){    //Starting at elemnt[0] till the last element in the contact list object...

                      if (foundData.insert(blackbook.getEntry(stringFromFile[2]))){       //Set that holds a subset of our contact list that matches the last name currently in
                        cout << "Found." << endl;
                        for(int i = 0; i < foundData.size(); i++){  //We need to iterate through our set to print out all the entries we found that match the current last name in stringFromFile[1]
                          cout << " " << foundData[i].getFirstName() << " " <<  foundData[i].getLastName() << ", " << foundData[i].getBirthMonth() << "/" <<  foundData[i].getBirthDay() << "/" << foundData[i].getBirthYear() << endl;

                        }
                      }
                    }
                    if (!foundData.insert(blackbook.getEntry(stringFromFile[2]))){ //This if statement is executed if the insert function is
                      cout << " Not found." << endl;
                    }
                    stringFromFile.clear(); //Reset our vector after processing the line
                    break;

        case r:                   /*
                                  R key : Remove all records from the contact list with a key value (last name) indicated by key. Display all matching records that are deleted. Display an error message if no record matches the given key. Compare with Delete above. Example:
                                      R Wright
                                  */
                   cout << "Remove \"" << stringFromFile[2] << "\"" << endl;

                   blackbook.removeAll(stringFromFile[2])       //remove all last names matching stringFromFile[2] from the contact list.
                   stringFromFile.clear(); //Reset our vector after processing the line
                   break;

        case s:                   /*
                                  S : Show all the contacts. The contacts will be displayed based on the ordering managed by the balanced binary search tree index of the contacts' last names. If multiple contacts have the same last name, these contacts are displayed in order by their first name. Example:
                                        S
                                  */


      }

    }
  }

contactsOut.close();
listOfContacts.close();
listOfCommands.close();

}

   return 0;
}
