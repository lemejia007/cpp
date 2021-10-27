
/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Lab Exercise 8a
 * DUE DATE:   10/26/2021
 *
 */

/* Place Library References Here */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

/* Function name: linearSearch
 * Description: given an array of strings, an array size and a 
 *                keyword to search, return the position of the 
 *                search key in the array
 *              Returns -1 if not found;
 */
int linearSearch(string wordList[], const int SIZE, string searchValue);

// ??? Write a linear search here or following the main progrm that will look up
// the specified word n the word list and return its value, or -1 if the word is
// not found.
int linearSearch(string wordList[], const int SIZE, string searchValue) {

  int index         = 0;          // Used to search the array
  int position      = -1;         // Holds location/position of wanted element/word in array
  bool wordWasFound = false;      // Flag to indicate if word was found

  while(index < SIZE && !wordWasFound) {

    if(wordList[index] == searchValue) {

      wordWasFound = true; // Flag that the word was found
      position = index;    // Record the position in the array where wprd was found
    }

    index++;
  }

  return position;
}


/* Function name: binary Search
 * Description: given an array of strings, an array size and a 
 *                keyword to search, return the position of the 
 *                search key in the array
 *              Returns -1 if not found;
 */
int binarySearch(string wordList[], const int SIZE, string searchValue);

// ??? Write a binary search here or following the main progrm that will look up
// the specified word in the word list and return its value, or -1 if the word is
// not found.
int binarySearch(string wordList[], const int SIZE, string searchValue) {

  int  first = 0,            // First element/word in array
       middle,               // Middle element/word in array
       last = SIZE -1,       // Last element/ word in array
       position = -1;        // Holds location/position of wanted eleemnt/word in array 

  bool wordWasFound = false; // Flag to indicate if word was found

  while(!wordWasFound && first <= last) {

    // Calculate and assign middle element of array
    middle = (first + last) / 2;

    // If element/word is in the middle of array
    if(wordList[middle] == searchValue) {

      wordWasFound = true; // Flag that the word was found
      position = middle;  // Set position to middle 
    } 
      // If element/word was found in first half of array
    else if(wordList[middle] > searchValue)
      last = middle - 1;
    
    else 
      // If element/word was found in last half of array
      if(wordList[middle] < searchValue)
        first = middle + 1;
    
  }

  return position;
}


/*
 * Main Program
 * Description: Reads integers and seraches for them as requested by the user
 *
 */
int main() {

   string fileName;

   const  int    MAXWORDS           = 5000;
          string wordList[MAXWORDS] = {};
   
   string wordFileName;
   
   cout << "\nEnter name of a text file: ";
   cin >> wordFileName;

   ifstream word;
   word.open(wordFileName);

   if (word) {  // file is open

     // Read the words into a partial array
     int counter = 0;
     while (word >> wordList[counter] && counter < MAXWORDS)
       counter++;

     word.close();

     // This is test code to output word list. - do not turn in program with thsi code uncommented
     // for (int i = 0; i < counter; i++)
     //   cout << wordList[i] << " ";

     // ??? Write a loop and code that will ask the operator for a word,
     // then search for that word in the list using each of the two searches,
     // then list the word and it's position. Exit when the operatore enters "DoNe".

     string wordToSearch; // Variable to hold what word to search

     // Ask user for a word to search
     cout << "\nEnter a word to search:";
     cin >> wordToSearch;

     while(wordToSearch != "DoNe") {
     
     // Output the word the user wanted to search
     cout << "The word is " << "'" << wordToSearch << "'." << endl;

     // Compute and output binary search position
     if(binarySearch(wordList, counter, wordToSearch) > -1)
      cout << "Binary Search: position " << binarySearch(wordList, counter, wordToSearch) << endl;
     else 
      cout << "Binary Search: " << "Word Was Not Found." << endl;

     // Compute and output linear search position
     cout << "Linear Search: position " << linearSearch(wordList, counter, wordToSearch) << endl;
    
     // Ask user for a word to search
     cout << "\nEnter a word to search";
     cin >> wordToSearch;

     }

   }
   else {  // file open failed
     cout << "File '" << fileName << "' failed to open.";
     exit (1);
   }

   

  return 0;  
}
