// Name:
// USC NetID:
// CSCI 455 PA5
// Spring 2025

/*
 * listFuncs.cpp
 * --------------
 * Implementation of linked list helper functions used by the Table class.
 * These functions operate on ListType (a Node*), which represents the head
 * of a singly linked list.  All lists store (key, value) pairs.
 *
 * Functions implemented:
 *   - listInsert : insert a new key/value at the front of the list (if key not present)
 *   - listRemove : remove a node with the given key
 *   - listLookup : find a node with the given key and return pointer to its value
 */

#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

//*************************************************************************
// Node constructors

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

//*************************************************************************
// listInsert
//    Inserts a new node at the front of the list.
//    If a node with the same key already exists, the list is unchanged.
// 
// arguments:
//    list  — reference to the head pointer of the list
//    key   — key to insert
//    value — value to associate with the key
//
// returns:
//    true  — if insertion succeeded
//    false — if the key already exists
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

//*************************************************************************
// listRemove
//    Removes the node whose key matches target.
// 
// arguments:
//    list   — reference to the head pointer of the list
//    target — key to remove
//
// returns:
//    true  — if removal happened
//    false — if key not found
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

//*************************************************************************
// listLookup
//    Searches the list for the given key.
// 
// arguments:
//    list   — head pointer of list (passed by value)
//    target — key to search for
//
// returns:
//    pointer to the value stored in the matching node
//    nullptr if key not found
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