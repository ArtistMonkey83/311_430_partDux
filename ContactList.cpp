/** @file ContactList.cpp */

// A simple database abstract class.
// bjuliano@csuchico.edu

/**
 @file Database.h */

#include <set>
#include <algorithm>
#include <ContactList.h>

using namespace std;


/** Tests whether this database is empty.
@return True if the database is empty, or false if not. */
bool contactList::isEmpty() {
      if( blackbookData.empty()) {
        return true;
      }
      else
        return false
}

/** Determines the number of entries (records) in the database.
@return The number of entries/records in the database. */
unsigned contactList::getSize(){
       return blackbookData.size();
}

/** Adds a new record into the database.
@param newData  The new record to add to the database.
@post  The database contains the new record.
@return  True if the addition is successful, or false if not. */
bool contactList::add( const Contact& newData ){
       blackbookData.push_back(newData);//push_back into vector
       auto something = make_pair(newData.getLastName(),blackbookData.size()-1)//saving the pair of my new data's lastName and the lastest index of the push back in line 37 into container "something"
       guidebook.insert(something); //inserting the pair of data, in variable something, to the guidebook for maintaining a ContactList

       return true; //would add duplicate fn and ln entries
}

/** Removes the record with the given key from this database.
	    Returns false if duplicate records matching the key exist.
	  	Default format for aKey is the value of the key (based on index);
        otherwise, two values may be provided, separated by commas,
        to identify a particular record that matches the extended key
        (done if there are duplicates).
        @param aKey  The key of the record to remove from the database.
        @return  True if the removal is successful, or false if not. */
bool contactList::remove( const string& aKey ){
       auto removeIndex = equal_range(guidebook.begin(),guidebook.end(),aKey);
       if( removeIndex.first() - removeIndex.second() == 1){    // if equal range size = 1 remove, anything else return false because we are only expecting one contact object with a single remove() operation so our subrange would only be == 1
         guidebook.remove();
         blackbookData.remove();

                           // use the index on my vector swap with last index and decrement size
                           // update the multimap with the new index for the last item swapped
         return true;
       }
       if( removeIndex.first() - removeIndex.second() > 1)
         return false;     //we didn't find a single aKey in our contact list and therefore didn't remove a contact object, we could have found multiple aKeys but if so we don't have enough information to decide which to remove

}

/** Removes all record(s) with the given key from this database.
    @param aKey  The key of the record(s) to remove from the database.
    @return  True if the removal is successful, or false if not. */
bool contactList::removeAll( const string& aKey ){
        auto removeIndex = equal_range(guidebook.begin(),guidebook.end(),aKey);   //removeIndex will be some container that can hold the range of values that match aKey in our multimap
        if(removeIndex.first() - removeIndex.second() == 0){   //If aKey is not found the subrange length == 0
          return false;   //for loop in line 74 will not execute
        }
        for(auto it = removeIndex.first(); it != removeIndex.second(); it++){//.first() has the begining bound and .second() has the end bound.
          guidebook.remove(it); //removing a pair from my multimap
          blackbookData.remove(it->second); //removing my index from vector of contacts
        }
        return true;    //we only execute this line if we removed something
}

/** Removes all records from this database. */
void contactList::clear(){
        blackbookData.clear();    //vector.clear();
        guidebook.clear();        //multimap.clear();
}

/** Gets an entry (or entries) with the matching key from this database.
    @post  The desired entry/entries has been returned in a set, and the
        database is unchanged. If no such entry was found, an exception
        is thrown.
    @param aKey  The key of the record to locate from the database.
    @return  The set containing the entry (or entries) in the database
        that matches the given search key.
    @throw  NotFoundException if the given entry is not in the database. */
set<ItemType> contactList::getEntry( const string& aKey ) const
    throw(NotFoundException){

      set<Contact> contactSubset;
      auto getIndex = equal_range(guidebook.begin(),guidebook.end(),aKey);  //use multimap to get the indices, extracting the index range that match aKey

      for(auto it = getIndex.first(); it != getIndex.second(); it++){//the subrange of objects matching aKey start at .first() and end at .second()
      contactSubset.insert(blackbookData(it));//push those indices that match aKey into the set
      }
      return contactSubset;
}

/** Tests if an entry matching the given key occurs in this database.
    @post  The database is unchanged.
    @param aKey  The search key of the entry to find.
    @return  True if the entry occurs in the database, or false if not. */
bool contactList::contains( const string& aKey ) const {
      auto getIndex = equal_range(guidebook.begin(),guidebook.end(),aKey);  //use multimap to get the indices, extracting the index range that match aKey
      if(getIndex.first() - getIndex.second() == 0){   //If aKey is not found the subrange length == 0
        return false;   //this line is executed if we don't find the value we are searching for which is referred to locally as aKey
      }
      else //if the subrange is not == 0 we have found aKey in our contactList object
      return true;

}

/** Destroys object and frees memory allocated by object. */
~ContactList() {  }

// end Database
