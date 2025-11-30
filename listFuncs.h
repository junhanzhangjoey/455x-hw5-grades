// Name:
// USC NetID:
// CSCI 455 PA5
// Spring 2025


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to *not* put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include <string>
  
//*************************************************************************
// Node:
//    A single node in a singly linked list.  Each node stores a key-value
//    pair, used for chaining in the hash table.
//*************************************************************************
struct Node {
   std::string key;
   int value;

   Node *next;

   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

// listInsert:
//    Inserts (key, value) at the front of the list if key is not already present.
//    Returns true if the insert succeeds; false if the key already exists.
//    Parameter list is passed by reference so the head pointer can be modified.
bool listInsert(ListType & list, const std::string & key, int value);


// listRemove:
//    Removes the node whose key matches target.
//    Returns true if a node was removed; false if the key was not found.
//    Parameter list is passed by reference since removal may change the head.
bool listRemove(ListType & list, const std::string & target);

// listLookup:
//    Looks for a node with the matching key.
//    Returns a pointer to the node’s value field, or nullptr if not found.
int* listLookup(ListType list, const std::string & target);













// keep the following line at the end of the file
#endif