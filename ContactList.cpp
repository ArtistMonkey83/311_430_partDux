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
      /* for(auto i = guidebook.begin();guidebook.end(), i++){
         if(firstName == 0) {
           return true;
         }

       }*/
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
       auto something = make_pair(newData.getLastName(),blackbookData.size()-1)//insert the pair of my new data's lastName and the lastest index of this push back
       guidebook.insert(something);

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
                      // if equal range size = 1 remove, anything else return false
       equal_range(); // used on my mutlimap
                      // use the index on my vector swap with last index and decrement size
                      // update the multimap with the new index for the last item swapped
     }

    /** Removes all record(s) with the given key from this database.
        @param aKey  The key of the record(s) to remove from the database.
        @return  True if the removal is successful, or false if not. */
     bool contactList::removeAll( const string& aKey ){
       equal_range(aKey.begin(),aKey.end(),aKey);   //finding a contact by lastName
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
//use multimap to get the indices and push those indices into the set set.insert(blackbookData[0]) example
          /*for(int i = 0 ; i <aKey.size();i++){ //blackbookData is a vector that has the contact info
            if(aKey){
              contactSubsetinsert(aKey[i]);
            }
          }*/

        }

    /** Tests if an entry matching the given key occurs in this database.
        @post  The database is unchanged.
        @param aKey  The search key of the entry to find.
        @return  True if the entry occurs in the database, or false if not. */
     bool contactList::contains( const string& aKey ) const {
       for (auto it = aKey.equal_range(aKey).first ; it!) //use the multimap to find if it exists equal_range == 0 it doesnt exist
     }

    /** Destroys object and frees memory allocated by object. */
     ~ContactList() {  }

// end Database
