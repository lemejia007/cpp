/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Programming Assignment 8
 * DUE DATE:   11/21/2021
 */

/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <fstream> 
#include <string>
#include <iomanip>
#include <cmath>
#include <sstream>

using namespace std;

/********************************************************
 *                  Global Constants 
*/
  int const NCONST     = 1;         // Values used to retrive a 
  int const NAME       = 2;         // specified field
  int const BIRTH      = 3;
  int const DEATH      = 4;
  int const PROFESSION = 5;
  int const TITLES     = 6;

  string const SENTINEL_VALUE = "*"; // Value to exit program

/********************************************************
 *                  Function Definitions
*/

/*
 * Function Name: getFileFromUser()
 *
 * Description:   This function prompts the user to eneter a 
 *                file to open and stores value in appropriate 
 *                variable. 
 * 
 * Parameters:    None   
*/
string getFileFromUser() {
  string file;
  cout << "\nEnter the name of a file to open." << endl;
  getline(cin, file);
  return file;
}

/*
 * Function name: createArray()
 * Description:   Allocate an array of the specified type and size, 
 *                and return the pointer.
 * 
 * Parameter:     Size of array
 */
string* createArray(int size) {
  // Return null pointer if size is 0 or negative
  if(size <=0) 
    return nullptr;
  // Dynamically allocate new array
  string* newArr = new string[size];
  // Return pointer from function
  return newArr;
}

/*
 * Function name: readData()
 *
 * Description:   Read data from the specified stream object and read 
 *                the data from tHe object into the array.
 * 
 * Parameters:    Open stream object
 *                Pointer to a string array
 *                Size of array
 */
void readData(ifstream &input, string* array, int size) {
  for (int i = 0; i < size; i++)
    getline(input, *(array + i));
}

/*
 * Function:    getTSField(string, int, delimiter)
 * Description: extracts a selected field from a line (string) 
 *              of data.
 * Inputs:      1. string with tab separated fields
 *              2. number of feld to return (1 = first field, etc)
 *              3. delimiter character. Defaults to tab
 * Returns:     Contents of requested field or an empty string 
 *              if field is not found (request is <1 or >6)
 *
 */
string getTSField(string line, int fNum, char delimiter = '\t') {

  stringstream buffer(line); // stream buffer; initialized with input line
  string fieldVal;           // store and return field

  if (fNum > 0) {            // Is the field number copacetic?
    int count = 1;           // First field is 1 (not 0)
    while (getline(buffer, fieldVal, delimiter) ) {
      if (count == fNum)
	return fieldVal;
      count++;
    }
  }
  return "";
}

/********************************************************
*  Main program
*  Description: This program prompts the user to open a file, 
*               to enter a name of an actor to search for in said 
*               file, and returns requested actor's information.
*/

int main() {

  ifstream readFile;  // Create file stream object
  string   actorFile; // Variable to hold actor data file

  // Ask user for a file to open
  actorFile = getFileFromUser();

  // Open file
  readFile.open(actorFile);

  if(readFile) { // If file successfully opens 

    // Read and store file size
    int numActors; 
    readFile >> numActors;

    // Read file headers and clear buffer for getline()
    string fileHeaders;
    readFile.ignore();
    getline(readFile,fileHeaders);

    // Dynamically create an array of actors
    string* actorsArr = createArray(numActors);

    // Read data into array of actors
    readData(readFile, actorsArr, numActors);

    // Close actor file
    readFile.close();

    // Prompt user to enter an actor's name
    string searchValue;
    cout << "Enter an actor's name to search or '*' to quit." << endl;
    getline(cin, searchValue);

    while(searchValue != SENTINEL_VALUE) {
      // Search the array of actors with search value 
      for(int i = 0; i < (numActors - 1); i++) {
        // If an actor's name in actor's array is equal to search value
        if(getTSField(actorsArr[i], NAME) == searchValue) {
          // Read and store the actor's name, birth year, death year(or age), and profession
          string name        = getTSField(actorsArr[i],      NAME);
          int    born        = stoi(getTSField(actorsArr[i], BIRTH));
          string died        = getTSField(actorsArr[i],      DEATH);
          string profession  = getTSField(actorsArr[i],      PROFESSION);
          int    age;        

          // Setup output
          cout << left << endl;

          if(died == "\\N") {    // If actor is still alive, 
            age = (2021 - born); // calculate age
            // Display actor information
            cout << setw(13) << "\nName: "     << name << endl;
            cout << setw(12) << "Born: "       << born << endl;
            cout << setw(12) << "Age: "        << age << endl;
            cout << setw(12) << "Profession: " << profession << "\n" << endl;
          } else { // Actor has passed
              // Display actor information 
              cout << setw(12) << "\nName: "     << name << endl;
              cout << setw(12) << "Born: "       << born << endl;
              cout << setw(12) << "Died: "       << died << endl;
              cout << setw(12) << "Profession: " << profession << "\n" << endl;
          }       
        }
      }
      // Prompt user to enter an actor's name
      cout << "Enter an actor's name to search or '*' to quit." << endl;
      getline(cin, searchValue);
    }

    // Delete dynamically allocated array from memory
    delete [] actorsArr;

    // Give address of null pointer to actorsArr
    actorsArr = nullptr;
        
  }
  else {
    // File could not open
    cout << "\nAlert: File " << actorFile << " could not open." << endl;
    exit(EXIT_FAILURE); 
  }

  // End of program
  cout << "\nEnd of program." << endl;

  return 0;
}
