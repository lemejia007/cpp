/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Programming Assignment 5
 * DUE DATE:   11/03/2021
 */

/* Library References */
#include <cstdlib>
#include <iostream>
#include <fstream> 
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

/********************************************************
 *                   Global Constants
*/
const int MAXROWS      = 1000; // Maximum number of rows
const int DATA_HEADERS = 5;    // Number of columns in file

/********************************************************
 *                  Function Definitions
*/

/*
 * Function Name: getFileFromUser()
 * Description:   This function prompts the user to eneter a 
 *                file to open and stores value in appropriate 
 *                variable.    
*/
string getFileFromUser() {
  
  string file;
  cout << "\nEnter the name of a file to open." << endl;
  getline(cin, file);

  return file;
}

/*
 * Function Name: menu()
 * Description:   This function, prompts the user to make 
 *                a selcetion, and returns their selection.
*/
string menu() {

    string selection;

    // Prompt user                  
    cout << "\nWhat would you like to do?\nEnter 'average', 'list', OR 'quit.'\n" 
         << endl;
    cin >> selection;

    return selection;
}

/*
 * Function Name: selectSex()
 * Description:   This function prompts the user to make 
 *                a selcetion to request data for either 
 *                males or females, and returns user selection.
*/
char selectSex() {

      char selectedSex;

      // Prompt user 
      cout << "\nDo you want the data for males or females?\nEnter 'm' OR 'f'.\n" 
           << endl;
      cin >> selectedSex;

      return selectedSex;  
}

/*
 * Function Name: average()
 * Description:   This function, when passed a sexList, ageList, 
 *                totalDeaths, covidDeaths, and a deathRate 
 *                array, along with an age range, calculates 
 *                and returns the average death rate of the group.     
*/
double average(double deathRateList[], char sex, int startingAge, int endingAge, int counter) {

  // Swap starting age and ending age if starting age > ending age
  if(startingAge > endingAge)
    swap(startingAge, endingAge);

  // If need be, adjust starting age
  if(startingAge < 0)
    startingAge = 0;

  // If need be, adjust ending age
  if(endingAge > 85)
    endingAge = 85;

  // Keep running total
  double totalDeathRate = 0.0;

  double averageDeathRate; // Holds average death rate

  if(sex == 'f') {

    int incrementedStartingAge = startingAge; // Holds incremented starting age

    // Add all death rates
    while(incrementedStartingAge <= endingAge) {
      totalDeathRate += deathRateList[incrementedStartingAge];
      incrementedStartingAge++; // Move up in range
    }
  
    // Calculate average death rate
    averageDeathRate = (totalDeathRate / (endingAge - startingAge +1));

  }
  else if(sex == 'm') {
    
    // Adjust starting age and ending age for males
    startingAge = (startingAge + (counter/2));
    endingAge   = (endingAge   + (counter/2));

    int incrementedStartingAge = startingAge; // Holds incremented starting age


    // Add all death rates
    while(incrementedStartingAge <= endingAge) {
      totalDeathRate += deathRateList[incrementedStartingAge];
      incrementedStartingAge++; // Move up in range
    }

    // Calculate average death rate
    averageDeathRate = (totalDeathRate / (endingAge - startingAge +1));

  }

  return averageDeathRate;

}

/*
 * Function Name: list()
 * Description:   This function, when passed a sexList, ageList, 
 *                totalDeaths, covidDeaths, and a deathRate 
 *                array, along with an age range, will 
 *                display the headers and all of the data 
 *                items in that range.
*/
void list(int ageList[], int totalDeathsList[], int covidDeathsList[], 
          double deathRateList[], string fileHeader[], char sex, 
          int startingAge, int endingAge, int counter) {

  // Swap starting age and ending age if starting age > ending age
  if(startingAge > endingAge)
    swap(startingAge, endingAge);

  // If need be, adjust starting age
  if(startingAge < 0)
    startingAge = 0;

  // If need be, adjust ending age
  if(endingAge > 85)
    endingAge = 85;

  if(sex == 'f') {

    int incrementedStartingAge = startingAge; // Holds incremented starting age

    cout << "\nData for females between the ages of " << startingAge 
         << " and " << endingAge << ":" << endl;

    // Setup headers
    cout << fixed << setprecision(9) << endl;
    cout << left << setw(7) << fileHeader[0] << setw(4) << fileHeader[1] << setw(14) << fileHeader[2] 
           << setw(16) << fileHeader[3] << setw(11) << endl;

    // Step through arrays and output data
    while(incrementedStartingAge <= endingAge) {
      cout << left << setw(7) << "Female" << right << setw(4) << ageList[incrementedStartingAge] << setw(13) 
           << totalDeathsList[incrementedStartingAge] << setw(16) << covidDeathsList[incrementedStartingAge] 
           << setw(13) << deathRateList[incrementedStartingAge] << endl;
      incrementedStartingAge++; // Move up in range
    }

  }
  else if(sex == 'm') {
    
    // Adjust starting age and ending age for males
    startingAge = (startingAge + (counter/2));
    endingAge   = (endingAge   + (counter/2));

    int incrementedStartingAge = startingAge; // Holds incremented starting age

    cout << "\nData for males between the ages of " << (startingAge - (counter/2))
         << " and " << (endingAge - (counter/2)) << ":" << endl;

    // Setup headers
    cout << fixed << setprecision(9) << endl;
    cout << left << setw(7) << fileHeader[0] << setw(4) << fileHeader[1] << setw(14) << fileHeader[2] 
           << setw(16) << fileHeader[3] << setw(11) << endl;

    // Step through arrays and output data
    while(incrementedStartingAge <= endingAge) {
      cout << left << setw(7) << "Male" << right << setw(4) << ageList[incrementedStartingAge] << setw(13) 
           << totalDeathsList[incrementedStartingAge] << setw(16) << covidDeathsList[incrementedStartingAge] 
           << setw(13) << deathRateList[incrementedStartingAge] << endl;
      incrementedStartingAge++; // Move up in range
    }

  }

}

/*******************************************************
*                     Main program
*
*  Description: This program reads covid19 related data from
                a user selected file, and continues to prompt 
                the user to select an option of either to average 
                death rate of a group, list covid19 information 
                for a selected range, or quit. 
*/

int main() {

  ifstream readFile;  // Create file stream object

  string covid19File; // Variable for CDC file containing covid-19 data

  // Obtain file to open from user
  covid19File = getFileFromUser();

  // Open file
  readFile.open(covid19File);

  if(readFile) {

    // Parallel arrays 
    bool   sexList        [MAXROWS] = {};    // Sex of age group
    int    ageList        [MAXROWS] = {};    // Age group
    int    totalDeathsList[MAXROWS] = {};    // Total deaths of age group
    int    covidDeathsList[MAXROWS] = {};    // Covid deaths of age group
    double deathRateList  [MAXROWS] = {};    // Death rate of age group

    string fileHeader[DATA_HEADERS];         // Holds each value of the first line

    // Read the first row into a seperare array
    readFile >> fileHeader[0] >> fileHeader[1] >> fileHeader[2] 
             >> fileHeader[3] >> fileHeader[4];

    // Read each column into a partial parallel arrays
    int counter = 0;
    while (readFile >> sexList[counter] >> ageList[counter] >> totalDeathsList[counter] >> 
           covidDeathsList[counter] >> deathRateList[counter] && counter < MAXROWS)
      counter++;

    // Ask user what they would like to do
    string userSelection;                   // Holds user menu choice
    userSelection = menu();

    while(userSelection != "quit") {

      char   sex;                            // Holds sex of requested data
      int    startingAge;                    // Holds starting age                     
      int    endingAge;                      // Holds ending age
      double averageDR;                      // Holds averaeg death rate

      // Compute and output requested information
      if(userSelection == "average") {

        // Ask user what sex they want the data for
        sex = selectSex();
        // Ask user for starting age
        cout << "\nWhat is the starting age?\nEnter a number between 0 and 85\n" 
             << endl;
        cin >> startingAge;
        // Ask user for ending age 
        cout << "\nWhat is the ending age?\nEnter a number between 0 and 85\n" 
             << endl;
        cin >> endingAge;
      
        // Compute average for age range
        averageDR = average(deathRateList, sex, startingAge, endingAge, counter);


        // Output average for death range
        cout << fixed << setprecision(9) << endl;
        if(sex == 'f') 
          cout << "The average death rate for females between the ages of " << startingAge 
               << " and " << endingAge << " is " << averageDR << endl;
        else if(sex == 'm')
          cout << "The average death rate for males between the ages of " << startingAge 
               << " and " << endingAge << " is " << averageDR << endl;

      }
      else if(userSelection == "list") {

        // Ask user what sex they want the data for
        sex = selectSex();
        // Ask user for starting age
        cout << "What is the starting age?\nEnter a number between 0 and 85\n" 
             << endl;
        cin >> startingAge;
        // Ask user for ending age 
        cout << "What is the ending age?\nEnter a number between 0 and 85\n" 
             << endl;
        cin >> endingAge;

        // Compute and output data for age group
        list(ageList, totalDeathsList, covidDeathsList, 
                deathRateList, fileHeader, sex, startingAge, endingAge, counter);
      }

        // Ask user what they would like to do
        userSelection = menu();
    }

  } 
  else {

    // File could not open
    cout << "\nAlert: File " << covid19File << " was unsuccessful opening." << endl;
    exit(EXIT_FAILURE); // Indicates failure

  }

  // End of program
  cout << "\nEnd of program." << endl;

  return 0;
}
