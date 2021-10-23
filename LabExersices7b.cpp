/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Lab Exercise 7b
 * DUE DATE:   10/21/2021
 *
 */

/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/*
 * Place Global Constants Below
*/
const int    STUDENT_COUNT  =  9;                // Number of students
const int    TEST_COUNT     =  6;                // Number of grades per student

const int    FIELD_WIDTH   =  9; // Width of numeric output fields
const int    NAME_WIDTH    = 15; // Challenge only
const int    PRECISION     =  1; // Test score output precision

/***************************************************************************
 * Function Prototypes placed below and function definitions follow main()
*/

/********************************************************
 * 
 * Function Name: getFileFromUser()
 * Description:   Prompts the user to eneter a file to open 
 *                and stores value in appropriate variable.
 *     
*/
string getFileFromUser();

 /*******************************************************
 * 
 * Function name: displayArray()
 * Description:   This function displays students test scores as a table, computes 
 *                students averages, includes averages in the table and finally 
 *                computes and outputs class average.
 * 
*/
void displayArray(const double grades[][TEST_COUNT]);

/*
 * Main Program
 * Description: This Program prompts the user to enter a reads students test score's 
 *              from a file, displays the data as a table and calculates and includes 
 *              their averages and finally outputs class average.
 */
int main() {

  // Creat file stream object
  ifstream dataIn;

  string DATA_FILENAME; // File to open

  // Get file from user
  DATA_FILENAME = getFileFromUser();

  // Open data file
  dataIn.open(DATA_FILENAME);
    
  if (dataIn) { // Make sure file is open

    // Two-dimension array to hold test scores for the class
    double testScores[STUDENT_COUNT][TEST_COUNT]; 
    
    // Read the data from the file into the array
    for(int row = 0; row < STUDENT_COUNT; row++) {
      for(int col = 0; col < TEST_COUNT; col++) {
        dataIn >> testScores[row][col];
      }
    }

    // Close the input file
    dataIn.close();

    // Compute and output
    displayArray(testScores);

  }
  else {
    
    // File failed to open. Display message and exit with return code 1.
    // (Why are there '+'s instead of "<<"? Do you know why this works?)
    cout << "\nData file \"" + DATA_FILENAME + "\" failed to open. Exiting program.\n";
    
    return 1; // '1'. signals program failed
  }
  
  return 0;
  
}

/*
 * Function Name: getFileFromUser()
 */
string getFileFromUser(){
  
  string file;
  cout << "\nEnter the name of a file to open." << endl;
  getline(cin, file);
  return file;

}

/*
* Function name: displayArray()
*/
void displayArray(const double grades[][TEST_COUNT]) {

  // Setup output
  cout << fixed << setprecision(PRECISION);

  double classTotal = 0; // Keep running total for class

  // For loop for each student/row
  for(int row = 0; row < STUDENT_COUNT; row++) {

    double studentTotal = 0; // Keep running total for student

    // For loop for each score/column
    for(int col = 0; col < TEST_COUNT; col++) {
        
      // Setup output 
      cout << fixed << showpoint << setprecision(PRECISION);
      cout << setw(FIELD_WIDTH) << grades[row][col] << "  ";

      // Calculate total for each student/row
      studentTotal += grades[row][col];

    }

    // Calculate class total
    classTotal += studentTotal;

    // Output each student's average
    cout <<  setw(FIELD_WIDTH) << (studentTotal/TEST_COUNT) << endl;
  }

  // Output class average
  cout << "\nThe class average was: " << (classTotal / (STUDENT_COUNT * TEST_COUNT)) << "\n" << endl;

}
