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

    unsigned birthMonth,
             birthDay,
             birthYear;
  public:
    Contact(string fn, string ln,unsigned bm,unsigned bd,unsigned by);  //Constructor
    string getFirstName();   //getters
    string getLastName();


    unsigned getBirthMonth(); //getters non negative
    unsigned getBirthDay();
    unsigned getBirthYear();

    void setFirstName(string firstName);   //setters
    void setLastName(string lastName);
    void setBirthMonth(unsigned birthMonth); //setters
    void setBirthDay(unsigned birthDay);
    void setBirthYear(unsigned getBirthYear);


};

#endif
