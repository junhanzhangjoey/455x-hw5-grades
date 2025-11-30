// Name:
// USC NetID:
// CSCI 455 PA5
// Spring 2025

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

using namespace std;
void printCommandSum(){
   cout << "insert name score" << endl;
   cout << "change name newscore" << endl;
   cout << "lookup name" << endl;
   cout << "remove name" << endl;
   cout << "print" << endl;
   cout << "size" << endl;
   cout << "stats" << endl;
   cout << "help" << endl;
   cout << "quit" << endl;
}
int main(int argc, char * argv[]) {


   Table * grades;  // Table is dynamically allocated below, so we can call
                     // different constructors depending on input from the user.
   
   // optionally gets the hash table size from the command line
   if (argc > 1) {
      int hashSize = atoi(argv[1]);  // atoi converts c-string to int
      
      if (hashSize < 1) {
         cout << "Command line argument (hashSize) must be a positive number" 
              << endl;
         return 1;
      }

      grades = new Table(hashSize);

   }
   else {   // no command line args given -- use default table size
      grades = new Table();
   }


   grades->hashStats(cout);

   // add more code here
   // Reminder: use -> when calling Table methods, since grades is type Table*
   cout<<"cmd> ";
   string cmd;
   while(cin >> cmd){
      if(cmd == "insert"){
         string name;
         int score;
         cin >> name >> score;
         if(!grades->insert(name, score)){
            cout<<"ERROR: name already exists"<<endl;
         }
      }else if(cmd == "change"){
         string name;
         int newscore;
         cin >> name >> newscore;
         int* score = grades->lookup(name);
         if(score == nullptr){
            cout<<"ERROR: the name is not present in table"<<endl;
         }else{
            *score = newscore;
         }
      }else if(cmd == "lookup"){
         string name;
         cin >> name;
         int* score = grades->lookup(name);
         if(score == nullptr){
            cout<<"ERROR: the name is not present in table"<<endl;
         }else{
            cout<<name<<": "<<*score<<endl;
         }
      }else if(cmd == "remove"){
         string name;
         cin>>name;
         if(!grades->remove(name)){
            cout<<"ERROR: the name is not present in table"<<endl;
         }
      }else if(cmd == "print"){
         grades->printAll();
      }else if(cmd == "size"){
         cout<<grades->numEntries()<<endl;
      }else if(cmd == "stats"){
         grades->hashStats(cout);
      }else if(cmd == "help"){
         printCommandSum();
      }else if(cmd == "quit"){
         break;
      }else{
         cout<<"ERROR: invalid command"<<endl;
         printCommandSum();
      }
      cout<<"cmd>: ";
   }
   return 0;
}
