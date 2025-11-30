// Name:
// USC NetID:
// CSCI 455 PA5
// Spring 2025


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}




//*************************************************************************
// put the function definitions for your list functions below
bool listInsert(ListType & list, const string & key, int value){
   ListType track = list;
   while(track!=NULL){
      if(track->key == key){
         return false;
      }
      track = track->next;
   }
   ListType node = new Node(key, value, list);
   list = node;
   return true;
}

bool listRemove(ListType & list, const string & target){
   ListType track = list;
   ListType prev = NULL;
   while(track!=NULL){
      if(track->key == target){
         if(prev == NULL){
            list = track->next;
         }else{
            prev->next = track->next;
         }
         delete track;
         return true;
      }
      prev = track;
      track = track->next;
   }
   return false;
}

int* listLookup(ListType list, const string & target){
   ListType track = list;
   while(track!=NULL){
      if(track -> key == target){
         return &track->value;
      }
      track = track->next;
   }
   return NULL;
}