/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Programming Assignment 5
 * DUE DATE:   10/24/2021
 */

/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <fstream> 
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

/*
 * Place Global Constants Below
*/
const int AIRLINE_COUNT = 56; // Number of airlines

/********************************************************
 *       Function Prototypes are Listed Here
 * All function definitions follow the main program
*/

/********************************************************
 * 
 * Function Name: getFileFromUser()
 * Description:   Prompts the user to eneter a file to open 
 *                and stores value in appropriate variable.    
*/
string getFileFromUser();

/********************************************************
 * 
 * Function Name: busiestAirline()
 * Description:   This fucntions accepts an array of airlines
 *                and one of KM per week values which it uses 
 *                to determine and output the busiest airline.
*/
void busiestAirline(string [], long int []);

/********************************************************
 * 
 * Function Name: safestAirline()
 * Description:   This function accepts three parrallel arrays 
 *                (one for names of airlines, another for KM 
 *                per week, and a third one for fatal accidents), 
 *                calculates an airline's fatal accident index,
 *                and then outputs the airline with the highest
 *                fatal accident index (safest airline).
*/
void safestAirline(string [], long int [], int []);

/********************************************************
 * 
 * Function Name: leastSafeAirline()
 * Description:   This function accepts three parrallel arrays 
 *                (one for names of airlines, another for KM 
 *                per week, and a third one for fatal accidents), 
 *                calculates an airline's fatal accident index,
 *                and then outputs the airline with the lowest
 *                fatal accident index (least safest airline).
*/
void leastSafeAirline(string [], long int [], int []);

/********************************************************
 * 
 * Function Name: averageNumFatalaties()
 * Description:   This function accepts two parallel arrays, 
 *                computes average number of fatalaties for 
 *                all airlines, and outputs the results
*/
void averageNumFatalaties(string [], int []);
 
/********************************************************
*  Main program
*  Description: In order to demonstrate the use of functions to 
*               modularize code, read data into arrays and access  
*               arrays to collect statistical data, this program 
*               reads from a file containing Airline Safety 
*               data collected from 2000 to 2014, and outputs a 
*               report of which airline is the busiest, safest, 
*               least safe, and average number of fatalities for 
*               all airlines.
*/

int main(){

  ifstream inputFile;       // Create file stream object

  string airlineSafetyFile; // File containing Airline Safety Data

  // Obtain file to open from user
  airlineSafetyFile = getFileFromUser();

  // Open file
  inputFile.open(airlineSafetyFile);

  if(inputFile) { // Validate if file was able to open 

    string   airlines[AIRLINE_COUNT];       // Airline names
    long int kmPerWeek[AIRLINE_COUNT];      // Seat KM per week
    int      incidents[AIRLINE_COUNT];      // Reported incidents
    int      fatalAccidents[AIRLINE_COUNT]; // Fatal accidents
    int      fatalities[AIRLINE_COUNT];     // Fatalitites 

    string fileHeader;                      // Holds first line of file (column headers)

    getline(inputFile, fileHeader);         // Skip first line in file

    // Loop to continue reading data from the file and into appropriate arrays
    for(int i = 0; i < AIRLINE_COUNT; i++)
      inputFile >> airlines[i] >> kmPerWeek[i] >> incidents[i] 
                >> fatalAccidents[i] >> fatalities[i];

    // Compute and output the busiest airline
    busiestAirline(airlines, kmPerWeek);

    // Compute and output the safest airline
    safestAirline(airlines, kmPerWeek, fatalAccidents);

    // Compute and output the least safe airline
    leastSafeAirline(airlines, kmPerWeek, fatalAccidents);
    
    // Compute and output average number of fatalaties 
    averageNumFatalaties(airlines, fatalities);

    // Close file
    inputFile.close();

  }
  else {

    // File could not open. Notify user and return 1.
    // (Using '+' instead of '<<' here works because we are doing string concatenation.)
    cout << "\nData file \"" + airlineSafetyFile + "\" failed to open. Exiting program.\n";

    return 1; // '1' signals program failed
  }

  return 0; // '0' signals program successfully executed 
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
 * Function Name: busiestAirline()
 */
void busiestAirline(string airlines[], long int kmPerWeek[]) {

  // Index postion of a paralell array
  int index;

  // Higest KM per week
  long int highest = kmPerWeek[0];

  for (int i = 0; i < AIRLINE_COUNT; i++) {
    if (kmPerWeek[i] > highest) {
      highest = kmPerWeek[i];
      index = i;
    }
  }

  // Output result
  cout << "\nThe busiest airline is " << airlines[index] 
       << " flying " << highest << " km seats." << endl;

}

/*
 * Function Name: safestAirline()
 */
void safestAirline(string airlines[], long int kmPerWeek[], int fatalAccidents[]) {

  // Index postion of a paralell array
  int position = 0;

  // Safest determined by fatal accident index 
  long int safest;

  // Because fatalAccidents is our dividend, we cannot 
  // divide by 0
  for(int i = 0; i < AIRLINE_COUNT; i++)
    if(fatalAccidents[i] == 0) 
      fatalAccidents[i] = 1;
      
  // Set the first airline as the safest
  safest = (kmPerWeek[0] / fatalAccidents[0]);

  // For loop to determine which airline is safer
  for(int ii = 1; ii < AIRLINE_COUNT; ii++) {
    if((kmPerWeek[ii] / fatalAccidents[ii]) > safest) {

      safest = (kmPerWeek[ii] / fatalAccidents[ii]);
      position = ii;

    }
  }
  
  // Output result
  cout << "\nThe safest airline is " << airlines[position] << " having a fatal accident index of " 
       << safest << "." << endl;

}

/*
 * Function Name: leastSafeAirline()
 */
void leastSafeAirline(string airlines[], long int kmPerWeek[], int fatalAccidents[]) {

  // Index postion of a paralell array
  int position = 0;

  // Least safe determined by fatal accident index 
  long int leastSafe;

  // Because fatalAccidents is our dividend, we cannot 
  // divide by 0
  for(int i = 0; i < AIRLINE_COUNT; i++)
    if(fatalAccidents[i] == 0) 
      fatalAccidents[i] = 1;
      
  // Set the first airline as the least safe
  leastSafe = (kmPerWeek[0] / fatalAccidents[0]);

  // For loop to determine which airline is least safe
  for(int ii = 1; ii < AIRLINE_COUNT; ii++) {
    if((kmPerWeek[ii] / fatalAccidents[ii]) < leastSafe) {

      leastSafe = (kmPerWeek[ii] / fatalAccidents[ii]);
      position = ii;

    }
  }
  
  // Output result
  cout << "\nThe least safe airline is " << airlines[position] << " having a fatal accident index of " 
       << leastSafe << "." << endl;

}

/*
 * Function Name: averageNumFatalaties()
 */
void averageNumFatalaties(string airlines[], int fatalaties[]) {

  // Keep running total
  int total = 0;

  // Variable to hold average fatalaties
  int average;

  for(int i = 0; i < AIRLINE_COUNT; i++)
    total += fatalaties[i];

  //compute average
  average = (total/ AIRLINE_COUNT);

  // Output result
  cout << "\nThe average number of fatalaties for all airlines is " << average << ".\n" << endl;

}
