/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Lab Exercise 7a
 * DUE DATE:   10/19/2021
 *
 */

/* Place Library References Here */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

/*
 * Main Program
 * Description: reads a series of gades, calculate
 * simple stats, output the stats. The grades are
 * floating point numbers.
 *
 */

/********************************************************
 *
 *       Function Prototypes are Listed Here
 * All function definitions follow the main program
 *
 *********************************************************/

/********************************************************
 * Function Name: highest(int grades[], int counter)
 * Description: Takes in an array of scores and a counter as arguments 
 *              and displays the highest score.  
 */
void highest(double grades[], int counter);

/********************************************************
 * Function Name: lowest(int grades[], int counter)
 * Description: Takes in an array of scores and a counter as arguments 
 *              and displays the lowest score.  
 */
void lowest(double grades[], int counter);

int main() {

  // Constants
  const int MAX_DATA_SIZE      = 500; // Maximum nuber of grades that can be processed
  string    gradeDataFilename;

  // Variables
  int    counter  = 0; // Loop counter
  double total    = 0; // Variable to keep running total
  double average;      // Variable to store average score of grades
  

  ifstream inFile;

  // Create an array that can hold the maximum number of
  // grades. Initialize it to 0's
  double grades[MAX_DATA_SIZE] = {};

  cout << "Enter a filname containing student grades: ";
  cin >> gradeDataFilename;
  
  // Open file
  inFile.open(gradeDataFilename);

  if(inFile) {

    // ??? Using a loop, read the data into the array
    while(counter < MAX_DATA_SIZE && inFile >> grades[counter]) {
      counter++;
    }

    // Close file
    inFile.close();

    // ??? Using another loop, calculate the average score of the grades

    for(int index = 0; index < counter; index++) {
      total += grades[index]; 
      average = total / counter;
    }

    // ??? Output the number of grades and the average score.
    cout << fixed << showpoint << setprecision(1);
    cout << "\nThere was a total number of " 
         << counter 
         << " grades read.\nThe average score for grades was " 
         << average << endl;

    // ??? Challenge (optional)

    // Output the largest grades
    highest(grades, counter);

    // Output the lowest grades
    lowest(grades, counter);

  }
  else {
    cout << "\nUnable to open file " << gradeDataFilename << "."".\n";
  }

  return 0;
  
}

/**
 *  Function name: highest()
 */
void highest(double grades[], int counter) {
  int highest;  // Highest score
  highest = grades[0];
    for (int i = 1; i < counter; i++) {
      if (grades[i] > highest) {
        highest = grades[i];
      }
    }
  cout << fixed << showpoint << setprecision(2);
  cout << "\nThe highest score is " << highest << endl;
}

/**
 *  Function name: lowest()
 */
void lowest(double grades[], int counter) {
  int lowest;  // Lowest score
  lowest = grades[0];
    for (int i = 1; i < counter; i++) {
      if (grades[i] < lowest) {
        lowest = grades[i];
      }
    }
  cout << fixed << showpoint << setprecision(2);
  cout << "\nThe Lowest score was " << lowest << endl;
}


