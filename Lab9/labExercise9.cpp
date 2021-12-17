/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Lab Exercise 8b
 * DUE DATE:   10/28/2021
 *
 */

/* Place Library References Here */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/* Function name: showList
 * Description: a template function for displaying items from an array of the
 *              caller specified type.
 * Call:   showList<type>showList(itemTypeList, sizeOfList, fieldWidth, items per line);
 *    parameters fieldWidth and itemsPerList default to shown alues.
 */
template <class itemType>
void showList(itemType array[], const int SIZE, int fieldWidth = 15, int itemsPerLine = 5) {
  std::ios_base::fmtflags f( cout.flags() ); // save state of cout
  cout << std::left;
  for (int i = 0; i < SIZE; i++) {
    cout << setw(fieldWidth) << array[i];
    if (!(i % itemsPerLine))
      cout << endl;
  }
  cout.flags( f );  // retore state of cout
}


/* Function name: linearSearch
 * Description: given an array of strings, an array size and a 
 *                keyword to search, return the position of the 
 *                search key in the array
 *              Returns -1 if not found;
 */
int linearSearch ( string wordList[], const int SIZE, string searchValue) {

  int index = 0;      // Used as a subscript to search the array
  int position = -1;  // To record the position of search value
  bool found = false; // Flag to indicate if value was found

  while (index < SIZE && !found) {

    if (wordList[index] == searchValue) { // If the value is found
      found = true; // Set the flag
      position = index; // Record the value's subscript
    }
    index++; // Go to the next element
  }
  return position; // Return the position, or -1
}


/* Function name: binary Search (recursive)
 * Description: given an array of strings, an array size and a 
 *                keyword to search, return the position of the 
 *                search key in the array or returns -1 if not found;
 */
int binarySearch(string array[], int start, int end, string value) {
  int middle = (start + end) / 2;
  if (end < start)
    return -1;

  if (value == array[middle])
    return middle;

  if (value < array[middle])
    return binarySearch(array, start, middle - 1, value);

  else
    return binarySearch(array, middle + 1, end, value);

}

/* Function name: binarySearch
 * Description: This is the binary search function header that matches
 * the linear search header. It imediately calls the recursive binary
 * search function to do the the actual searching.
 */
int binarySearch ( string wordList[], const int SIZE, string searchValue) {
  
  // Formulate a call to the recursive bniary search function
  return binarySearch ( wordList, 0, SIZE-1, searchValue);
  
}


/* Function name: sortList
 * Description: Given an array of strings, and the array size
 *              sort the listinto ascending order.
 */
void sortList(string array[], const int size)
{
  int    minIndex;
  string minValue;

  for (int start = 0; start < (size - 1); start++)
    {
      minIndex = start;
      minValue = array[start];
      for (int index = start + 1; index < size; index++)
	{
	  if (array[index] < minValue)
	    {
	      minValue = array[index];
	      minIndex = index;
	    }
	}
      swap(array[minIndex], array[start]);
    }
}

/*
 * Main Program
 * Description: Reads words and seraches for them as requested by the user
 *
 */
int main() {

  string fileName;

  const  int WORDCOUNT = 1749;
  string *wordList = nullptr;
  wordList = new string[WORDCOUNT];

  
  // ??? Part 2. Change the above statement to dynamically allocate wordList
  // then make any necessary changes to the program to use the new wordlist.
  // Be sure to delete array Wordlist it when it is no longer needed.
  
  string wordFileName;

  cout << "Enter name of a text file: ";
  cin >> wordFileName;

  ifstream word;
  word.open(wordFileName);

  if (word) {  // file is open

    // Read the words into the dynamically allocated wordList array

    int *counter = nullptr;
    counter      = new int;

    // ??? Part 1. Change the above statement to dynamically allocate
    // the counter variable then make any necessary changes to the progra
    // to use the dynamically allocated counter. Be sure to delete
    // counter when it is no longer needed.

      
    // Input the list of words to sort
    while (word >> wordList[*counter])
      (*counter)++;
    
    word.close();

    
    // Display unsorted list. FOR TESTING ONLY.
    // Do not turn in code with this uncommented!
    // cout << "\nUNSORTED LIST:" << endl;
    // showList<string>(wordList, *counter);
    
    // alphabetical order. We are using a partial arry, so don't forget to
    // use the proper variable to specify the actual number of elements being
    // used in the array, not MAXWORDS!

    sortList(wordList, *counter);

    // Display sorted list. FOR TESTING ONLY.
    // Do not turn in code with this uncommented!
    // cout << "\nSORTED LIST:" << endl;
    // showList<string>(wordList, *counter);

    
    // Write a loop and code that will ask the operator for a word,
    // then search for that word in the list using each of the two searches,
    // then list the word and it's position. Exit when the operatore enters "DoNe".

    string usersWord;
    int    position;

    cout << "\nEnter a word ('DoNe' to quit): ";
    cin >> usersWord;

    while (usersWord != "DoNe") {

      position = binarySearch(wordList, *counter, usersWord);

      cout << endl;
      cout << "The word is '" << usersWord << "'." << endl;

      cout << "Binary Search: ";
      if (position >= 0)
	cout << " position " << position << endl;
      else
	cout << "not found." << endl;

      position = linearSearch(wordList, *counter, usersWord);

      cout << "Linear Search: ";
      if (position >= 0)
	cout << "position " << position << endl;
      else
	cout << "not found." << endl;

      cout << "\nEnter another word to search ('DoNe' to quit): ";
      cin >> usersWord;

      // Free dynamically allocated memory
      delete counter;

    }

   
  }
  else {  // file open failed
    cout << "File '" << fileName << "' failed to open.";
    exit (1);
  }

  // Free dynamically allocated memory
  delete [] wordList; 

  return 0;
  
}
