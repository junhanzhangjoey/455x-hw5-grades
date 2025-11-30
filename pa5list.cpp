// Name:
// USC NetID:
// CS 455 PA5
// Spring 2025

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"

void printList(ListType list){
   ListType track = list;
   while(track!=NULL){
      cout<<track->value<<" ";
      track=track->next;
   }
   cout<<endl;
}
int main() {
   ListType list = NULL;
   listInsert(list, "joey", 100);
   listInsert(list, "luyi", 99);
   printList(list);
   //listRemove(list,"joey");
   printList(list);
   cout<<*listLookup(list,"joey")<<endl;

   return 0;
}
