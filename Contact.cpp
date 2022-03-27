//The class for a contact object
//This file implements the class for one contact with the five data members
#include <iosream>
#include <string>
#include <vector>


using namespace std;
Contact(string fn, string ln,unsigned bm,unsigned bd,unsigned by){
  firstName = fn;
  lastName = ln;
  birthMonth = bm;
  birthDay = bd;
  birthYear = by;

}//constructor

string getFirstName(& const fn){
  return firstName;
}

string getLastName(& const ln){
  return lastName;
}

void setFirstName(string fn){
  firstName = fn;
}

void setLastName(string ln){
  lastName = ln;
}

int getBirthMonth(& const bm){
  return birthMonth;
}

int getBirthDay(& const bd){
  return birthDay;
}

int getBirthYear(& const by){
  return birthYear;
}

void setBirthMonth(bm){
  birthMonth = bm;
}

void setBirthDay(bd){
  birthDay = bd;
}

void setBirthYear(by){
  birthYear = by;
}
