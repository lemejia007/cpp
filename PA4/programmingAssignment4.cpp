/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Programming Assignment 4
 * DUE DATE:   10/13/2021
 */

/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

//Define global constant values
//
const string QUIT = "0";     // Ends the program

/********************************************************
 *
 *       Function Prototypes are Listed Here
 * All function definitions follow the main program
 *
 *********************************************************/

/********************************************************
 * 
 * Function Name: getFileNameFromUser()
 * Description:   Prompts the user to eneter a file to open.
 *     
 */
string getFileNameFromUser();

/********************************************************
 * 
 * Function Name: getCountryFromUser()
 * Description:   Prompts the user to eneter a country to 
 *                search or 0 to Quit.
 */
string getCountryNameFromUser();

/********************************************************
 * 
 * Function Name: searchPopulation()
 * Description:   Opens a specified file, searches the file for 
 *                a country name and returns its population.              
 */
long int searchPopulation(string fileName, string country);

/********************************************************
 * Main program
 * Description: This program will ask for a file to open. Once
 *              opened, it will ask for a country to look for in 
 *              that file. Then display the name of the country 
 *              and its population.
 */
int main() {

  string   fileName;    // Variable to store user's requested file
  string   country;     // Variable to store user's requested country 
  long int population;  // Variables to store country's population
  
  // Ask user for a data file
  fileName = getFileNameFromUser();

  // Ask user for a country
  country = getCountryNameFromUser();

  while(country != QUIT) {
    // Search for country and return country's population 
    population = searchPopulation(fileName, country);
    
    if(population < 0) {
      // Display message to user if country is not found
      cout << "The country could not be found." << endl;
    }
    else {
    // Output country name and its population
    cout << left << setw(25) << "\nCountry Name" << setw(11) << "Population" << endl;
    cout << left << setw(24) << country << right << setw(11) << population << endl;
    }

    // Ask user for a country
    country = getCountryNameFromUser();

  }

  cout << "\nThis program has ended.\n" << endl;

  return 0;
}

/*
 * Function Name: getFileNameFromUser()
 */
string getFileNameFromUser() {
  string file;
  cout << "\nEnter the name of a file to open." << endl;
  getline(cin, file);
  return file;
}

/*
 * Function Name: getCountryNameFromUser()
 */
string getCountryNameFromUser() {
  string countryName;
  cout << "\nEnter the name of a country to search OR enter 0 to Quit." << endl;
  getline(cin, countryName);
  return countryName;
}

/*
 * Function Name: searchPopulation()
 */
long int searchPopulation(string fileName, string country) {
  // Define file stream object and open file
  ifstream inputFile(fileName);

  string countryName;  // Country's name
  long int population; // Country's population,
  long int landArea;   // Country's land area

  if(inputFile.fail()) {
      return -1;
  }
  else {
    while(inputFile >> countryName >> population >> landArea) {
      if(country == countryName) {
        inputFile.close();
        return population;
      } 
    }
    inputFile.close();
    return -2;
  }
}
