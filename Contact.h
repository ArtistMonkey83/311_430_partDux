//This file implements the class for one contact with the five data members
#ifndef CONTACT
#define CONTACT

#include <iosream>
#include <string>
#include <vector>

using namespace std;

class Contact {
  private:
    string firstName,
           lastName;

    int    birthMonth,
           birthDay,
           birthYear;
  public:
    string getFirstName(& const ),   //getters
           getLastName(& const);


    int    getBirthMonth(& const ), //getters
           getBirthDay(& const),
           getBirthYear(& const);

    void   setFirstName(string firstName),   //setters
           setLastName(string lastName),
           setBirthMonth(int birthMonth), //setters
           setBirthDay(int birthDay),
           setBirthYear(int getBirthYear);

//Am I supposed to define the command operations here?

};

#endif
