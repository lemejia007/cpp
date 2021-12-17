/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Lab Exercise 5c
 * DUE DATE:   09/05/2021
 *
 */

/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <fstream> // Needed for file I/O
#include <string>
using namespace std;

/*
 * Main program
 * Description: Count the lines in a file
 *
 * Challenge: Ask the user for a keyword, then display every line
 * containing the keyword and the total number of lines contining the 
 * keyword.
 *
 */
int main(int argc, char** argv) {

   // The following variables will be used in the program.
   string filename        = "";      // File name entered by the user
   string line            = "";     // A line read from the file
   int    totalCount      =  0;    // Total count of lines read

   // NOTE: Refer to lecture slides 109-120

   // Create a file stream object
   ifstream inputFile;
   
   // Ask the user to enter the filename
   cout << "Enter the name of a file to open:" << endl;
   getline(cin, filename);

   // Open the file
   inputFile.open(filename);

   // If the file is open,
   if(inputFile) {
    // read and count the lines in the file 
    while(getline(inputFile,line)) {
      totalCount++;
    }
   } else { 
      // otherwise,
      // print a file not open message
      cout << "ERROR: The file could not be opened";
   }

   inputFile.close();
   cout << "Total lines read: " << totalCount << endl;
   
   return 0;
}

