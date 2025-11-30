// Name:
// USC NetID:
// CSCI 455 PA5
// Spring 2025

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

// for hash function called in private hashCode method defined below
#include <functional>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
   arr = new ListType[HASH_SIZE]();
   hashSize = HASH_SIZE;
}


Table::Table(unsigned int hSize) {
   arr = new ListType[hSize]();
   hashSize = hSize;
}


int * Table::lookup(const string &key) {
   unsigned int idx = hashCode(key);
   ListType list = arr[idx];
   return listLookup(list, key);
}


bool Table::remove(const string &key) {
   unsigned int idx = hashCode(key);
   ListType &list = arr[idx];
   return listRemove(list,key);
}


bool Table::insert(const string &key, int value) {
   unsigned int idx = hashCode(key);
   return listInsert(arr[idx],key, value);
}

int Table::numEntries() const {
   int count = 0;
   for(unsigned int i = 0; i < hashSize; i++){
      ListType track = arr[i];
      while(track !=NULL){
         count++;
         track = track->next;
      }
   }
   return count;
}


void Table::printAll() const {
   for(unsigned int i = 0; i < hashSize; i++){
      ListType track = arr[i];
      while(track != NULL){
         cout << track->key << " " << track->value << endl;
         track = track->next;
      }
   }
}


void Table::hashStats(ostream &out) const {
   int non_empty = 0;
   int longest_chain = 0;
   for(unsigned int i = 0; i < hashSize; i++){
      ListType track = arr[i];
      if(track != NULL){
         non_empty++;
      }
      int chain_length = 0;
      while(track != NULL){
         chain_length++;
         track = track->next;
      }
      longest_chain = std::max(longest_chain, chain_length);
   }
   out<<"number of buckets: "<< hashSize<<endl;
   out<<"number of entries: "<< numEntries()<<endl;
   out<<"number of non-empty buckets: "<< non_empty<<endl;
   out<<"longest chain: "<<longest_chain<<endl;
}


// hash function for a string
// (we defined it for you)
// returns a value in the range [0, hashSize)
unsigned int Table::hashCode(const string &word) const {

   // Note: calls a std library hash function for string (it uses the good hash
   //   algorithm for strings that we discussed in lecture).
   return hash<string>()(word) % hashSize;

}


// add definitions for your private methods here

