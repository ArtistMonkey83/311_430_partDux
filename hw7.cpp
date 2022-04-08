#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{

   //what is the table size(number of buckets) of an initially empty unordered_set after it is declared? 1 for all according to zybooks
   unsigned number;

   unordered_set<string> stringSet;
   cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;

   unordered_set<int> intSet;
   cout << "Table size for intSet: " << intSet.bucket_count() << endl;

   unordered_set<unsigned> unsignedSet;
   cout << "Table size for unsignedSet: " << unsignedSet.bucket_count() << endl;

   unordered_set<double> doubleSet;
   cout << "Table size for doubleSet: " << doubleSet.bucket_count() << endl;

   unordered_set<float> floatSet;
   cout << "Table size for floatSet: " << floatSet.bucket_count() << endl << endl;

   //what is the table size(number of buckets) of an initially empty unordered_set after a single unsigned value is inserted into it? 13
   unsignedSet.insert(1);
   cout << "Table size for unsignedSet with 1 inserted: " << unsignedSet.bucket_count() << endl;
   unsignedSet.clear();

   intSet.insert(1);
   cout << "Table size for intSet with 1 inserted: " << intSet.bucket_count() << endl;
   intSet.clear();

   doubleSet.insert(1.01);
   cout << "Table size for doubleSet with 1.01 inserted: " << doubleSet.bucket_count() << endl;
   doubleSet.clear();

   stringSet.insert("1");
   cout << "Table size for stringSet with \"1\" inserted: " << stringSet.bucket_count() << endl;
   stringSet.clear();

   floatSet.insert(-1.098);
   cout << "Table size for floatSet with -1.098 inserted: " << floatSet.bucket_count() << endl;
   floatSet.clear();

    //what is the table size(number of buckets) of an initially empty unordered_set after the unsigned values 1,2,3,4,5,6,7,8,9,10 are inserted into it (in the order listed)? 13
    unsignedSet.insert(1);
    unsignedSet.insert(2);
    unsignedSet.insert(3);
    unsignedSet.insert(4);
    unsignedSet.insert(5);
    unsignedSet.insert(6);
    unsignedSet.insert(7);
    unsignedSet.insert(8);
    unsignedSet.insert(9);
    unsignedSet.insert(10);
    cout << "Table size for unsignedSet with 1 - 10 inserted: " << unsignedSet.bucket_count() << endl << endl;
    unsignedSet.clear();


//For each case below, first insert all the values indicated (in the order listed) into an initially empty unordered set, then identify which bucket (or slot) each value was hashed into by drawing the hash table and its contents in the space provided.

    //the unsigned values 1,2,3,4,5,6,7,8,9,10
    unsignedSet.insert(1);
    cout << "1 was hashed into bucket: " << unsignedSet.bucket(1) << endl; //1
    unsignedSet.insert(2);
    cout << "2 was hashed into bucket: " << unsignedSet.bucket(2) << endl; //2
    unsignedSet.insert(3);
    cout << "3 was hashed into bucket: " << unsignedSet.bucket(3) << endl;  //3
    unsignedSet.insert(4);
    cout << "4 was hashed into bucket: " << unsignedSet.bucket(4) << endl;  //4
    unsignedSet.insert(5);
    cout << "5 was hashed into bucket: " << unsignedSet.bucket(5) << endl;  //5
    unsignedSet.insert(6);
    cout << "6 was hashed into bucket: " << unsignedSet.bucket(6) << endl;  //6
    unsignedSet.insert(7);
    cout << "7 was hashed into bucket: " << unsignedSet.bucket(7) << endl;  //7
    unsignedSet.insert(8);
    cout << "8 was hashed into bucket: " << unsignedSet.bucket(8) << endl;  //8
    unsignedSet.insert(9);
    cout << "9 was hashed into bucket: " << unsignedSet.bucket(9) << endl;  //9
    unsignedSet.insert(10);
    cout << "10 was hashed into bucket: " << unsignedSet.bucket(10) << endl << endl;  //10
    unsignedSet.clear();

    //the string values "1","2","3","4","5","6","7","8","9","10"
    stringSet.insert("1");
    cout << "\"1\" was hashed into bucket: " << stringSet.bucket("1") << endl; //9
    stringSet.insert("2");
    cout << "\"2\"  was hashed into bucket: " << stringSet.bucket("2") << endl; //12
    stringSet.insert("3");
    cout << "\"3\" was hashed into bucket: " << stringSet.bucket("3") << endl;  //9
    stringSet.insert("4");
    cout << "\"4\"  was hashed into bucket: " << stringSet.bucket("4") << endl;  //0
    stringSet.insert("5");
    cout << "\"5\"  was hashed into bucket: " << stringSet.bucket("5") << endl;  //9
    stringSet.insert("6");
    cout << "\"6\"  was hashed into bucket: " << stringSet.bucket("6") << endl;  //3
    stringSet.insert("7");
    cout << "\"7\"  was hashed into bucket: " << stringSet.bucket("7") << endl;  //6
    stringSet.insert("8");
    cout << "\"8\"  was hashed into bucket: " << stringSet.bucket("8") << endl;  //7
    stringSet.insert("9");
    cout << "\"9\"  was hashed into bucket: " << stringSet.bucket("9") << endl;  //1
    stringSet.insert("10");
    cout << "\"10\"  was hashed into bucket: " << stringSet.bucket("10") << endl << endl;  //11

    stringSet.insert("10");
    cout << "\"10\"  was hashed into bucket: " << stringSet.bucket("10") << endl << endl;
    //Can you tell what data structure is used to maintain the buckets that have multiple entries in them based on the order of the items in each bucket? If so, what data structure do you think is used? The data structure that is used to implement buckets must be a structure that is appending to the front/top of the structure. When we inserted in ascending order the items are printed back in descending order. A stack  is another structure that would bury the first element inserted to the bottom/last element. Our bucket 9 has elements that were accessed thusly 5,3,1 and since I was able to remove 3 and 1 with out issues a linked list would be capable of accessing a specific element, a stack can only have its top most element read at a time. This implies that a linked list is being used because we can insert at the head node of a linked list n times for n items pushing our first item inserted to the tail position. Due to the nature of the load factor impletmented in this data structure pushing more then
    cout << "stringSet contains:";
      for ( auto it = stringSet.begin(); it != stringSet.end(); ++it )
        cout << " " << *it;
        cout << std::endl;

      cout << "stringSet's buckets contain:\n";
      for ( unsigned i = 0; i < stringSet.bucket_count(); ++i) {
        cout << "bucket #" << i << " contains:";
        for ( auto local_it = stringSet.begin(i); local_it!= stringSet.end(i); ++local_it )
          cout << " " << *local_it;
          cout << endl;
      }
    cout << endl;
    cout << "Erasing 1 from bucket 9:" << endl;
    stringSet.erase("1");

    cout << "stringSet contains:";
      for ( auto it = stringSet.begin(); it != stringSet.end(); ++it )
        cout << " " << *it;
        cout << std::endl;

      cout << "stringSet's buckets contain:\n";
      for ( unsigned i = 0; i < stringSet.bucket_count(); ++i) {
        cout << "bucket #" << i << " contains:";
        for ( auto local_it = stringSet.begin(i); local_it!= stringSet.end(i); ++local_it )
          cout << " " << *local_it;
          cout << endl;
      }
      cout << endl;
      stringSet.clear();
    //The string values "10","9","8","7","6","5","4","3","2","1"
    stringSet.insert("10"); //ASCII value " == 34, 1 == 49, 0 == 48, " == 34 TOTAL 165
    cout << "\"10\" was hashed into bucket: " << stringSet.bucket("10") << endl; //11
    stringSet.insert("9"); //ASCII value " == 34, 9 == 57, " == 34 TOTAL 125
    cout << "\"9\"  was hashed into bucket: " << stringSet.bucket("9") << endl; //1
    stringSet.insert("8"); //ASCII value " == 34, 8 == 56, " == 34 TOTAL 124
    cout << "\"8\" was hashed into bucket: " << stringSet.bucket("8") << endl;  //7
    stringSet.insert("7"); //ASCII value " == 34, 7 == 55, " == 34 TOTAL 123
    cout << "\"7\"  was hashed into bucket: " << stringSet.bucket("7") << endl;  //6
    stringSet.insert("6"); //ASCII value " == 34, 6 == 54, " == 34 TOTAL 122
    cout << "\"6\"  was hashed into bucket: " << stringSet.bucket("6") << endl;  //3
    stringSet.insert("5"); //ASCII value " == 34, 5 == 53, " == 34 TOTAL 121
    cout << "\"5\"  was hashed into bucket: " << stringSet.bucket("5") << endl;  //9
    stringSet.insert("4"); //ASCII value " == 34, 4 == 52, " == 34 TOTAL 120
    cout << "\"4\"  was hashed into bucket: " << stringSet.bucket("4") << endl;  //0
    stringSet.insert("3"); //ASCII value " == 34, 3 == 51, " == 34 TOTAL 119
    cout << "\"3\"  was hashed into bucket: " << stringSet.bucket("3") << endl;  //9
    stringSet.insert("2"); //ASCII value " == 34, 2 == 50, " == 34 TOTAL 118
    cout << "\"2\"  was hashed into bucket: " << stringSet.bucket("2") << endl;  //12
    stringSet.insert("1"); //ASCII value " == 34, 1 == 49, " == 34 TOTAL 117
    cout << "\"1\"  was hashed into bucket: " << stringSet.bucket("1") << endl << endl;  //9
    stringSet.clear();


    //When unsigned values are inserted into an unordered set, can we determine the hash function used? If so, what is it? The hash uses unordered_set <unsigned> myset; and the hash is Key % myset.bucket_count(); This means that keys provided, divided by the number of buckets in the hash table, will be mapped to the bucket associated with the same number as the remainder.


//The file C++ reserved words contains a subset of the reserved words (keywords) of the C++ programming language. This file is available from our csci310/Code/Lab/ folder


    //Identify all the changes in the table size for an unordered set starting when it is initially empty until after all these reserved words are inserted into it. Do this by indicating which reserved word’s insertion resulted in a new and increased table size.
    stringSet.insert("and");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("and_eq");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("asm");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("auto");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("bitand");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("bitor");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("bool");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("break");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("case");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("catch");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("char");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("class");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << " Load factor: " <<   stringSet.load_factor()<< endl;
    stringSet.insert("compl");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << " Load factor: " <<   stringSet.load_factor()<< endl;
    cout << "stringSet contains:";
      for ( auto it = stringSet.begin(); it != stringSet.end(); ++it )
        cout << " " << *it;
        cout << std::endl;

      cout << "stringSet's buckets contain:\n";
      for ( unsigned i = 0; i < stringSet.bucket_count(); ++i) {
        cout << "bucket #" << i << " contains:";
        for ( auto local_it = stringSet.begin(i); local_it!= stringSet.end(i); ++local_it )
          cout << " " << *local_it;
          cout << endl;
      }
    cout << endl;
    stringSet.insert("const");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << " Load factor: "  <<  stringSet.load_factor()<< endl;
    stringSet.insert("const_cast");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("continue");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("decltype");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("default");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("delete");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("do");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("double");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("dynamic_cast");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("else");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("enum");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("explicit");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("export");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("extern");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("false");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << " Load factor: "  <<  stringSet.load_factor()<< endl;
    stringSet.insert("float");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << " Load factor: "  <<  stringSet.load_factor()<< endl;
    cout << "stringSet contains:";
      for ( auto it = stringSet.begin(); it != stringSet.end(); ++it )
        cout << " " << *it;
        cout << std::endl;

      cout << "stringSet's buckets contain:\n";
      for ( unsigned i = 0; i < stringSet.bucket_count(); ++i) {
        cout << "bucket #" << i << " contains:";
        for ( auto local_it = stringSet.begin(i); local_it!= stringSet.end(i); ++local_it )
          cout << " " << *local_it;
          cout << endl;
      }
    cout << endl;
    stringSet.insert("for");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << " Load factor: "  <<  stringSet.load_factor()<< endl;
    stringSet.insert("friend");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("goto");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("if");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("inline");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("int");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("long");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("mutable");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("namespace");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("new");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("not");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("not_eq");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("nullptr");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("operator");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("or");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("or_eq");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("private");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("protected");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("public");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("register");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("reinterpret_cast");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("return");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("short");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("signed");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("sizeof");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("static");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("static_cast");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("struct");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << " Load factor: "  <<  stringSet.load_factor()<< endl;
    stringSet.insert("switch");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << " Load factor: "  <<  stringSet.load_factor()<< endl;
    cout << "stringSet contains:";
      for ( auto it = stringSet.begin(); it != stringSet.end(); ++it )
        cout << " " << *it;
        cout << std::endl;

      cout << "stringSet's buckets contain:\n";
      for ( unsigned i = 0; i < stringSet.bucket_count(); ++i) {
        cout << "bucket #" << i << " contains:";
        for ( auto local_it = stringSet.begin(i); local_it!= stringSet.end(i); ++local_it )
          cout << " " << *local_it;
          cout << endl;
      }
    cout << endl;

    stringSet.insert("template");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << " Load factor: "  <<  stringSet.load_factor()<< endl;
    stringSet.insert("this");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("throw");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("true");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("try");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("typedef");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("typeid");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("typename");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("union");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("unsigned");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("virtual");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("void");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("volatile");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("wchar_t");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("while");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("xor");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << endl;
    stringSet.insert("xor_eq");
    cout << "Table size for stringSet: " << stringSet.bucket_count() << " Load factor: " << stringSet.load_factor()<< endl;

    cout << "stringSet contains:";
      for ( auto it = stringSet.begin(); it != stringSet.end(); ++it )
        cout << " " << *it;
        cout << std::endl;

      cout << "stringSet's buckets contain:\n";
      for ( unsigned i = 0; i < stringSet.bucket_count(); ++i) {
        cout << "bucket #" << i << " contains:";
        for ( auto local_it = stringSet.begin(i); local_it!= stringSet.end(i); ++local_it )
          cout << " " << *local_it;
          cout << endl;
      }
    cout << endl;

    //Can you identify what rule is used to increase the table size? If you can identify the rule, express it in terms of the load factor, α. when(stringSet.load_factor() > 1 ) we resize the hash table with a value computed by the equation 29 = 13x


    // What is the maximum number of entries in a bucket (and identify all the buckets that have this many entries)?


    //What bucket number is the keyword template inserted in and how many entries are in that bucket?

   return 0;
}
