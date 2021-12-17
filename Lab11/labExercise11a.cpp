/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Lab Exercise 11a
 * DUE DATE:   11/18/2021
 *
 */

/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

/*************************************************
 *                  Structures 
*/
struct PlanetData {

  string   name;            // Planet name
  double   mass;            // Planet mass
  long int diameter;        // Planet diameter
  double   gravity;         // Planet gravity
  double   rotationPerdiod; // Planet rotation period
  double   lengthOfDay;     // Planet length of day
  double   distanceFromSun; // Planet distance from sun
  float    meanTemperature; // Planet mean temperature
  int      numberOfMoons;   // Planet number of moons
  bool     ringSystem;      // Planet ring system

};

/*************************************************
 *              Function Definitions
*/
void displayPlanets(const PlanetData* planets, int SIZE ) {

  for(int i = 0; i < SIZE; i++) {

    cout << left << setw(20) << "Name:"              << planets[i].name                    << endl 
         << left << setw(20) << "Mass:"              << planets[i].mass                    << endl
         << left << setw(20) << "Diameter:"          << planets[i].diameter                << endl
         << left << setw(20) << "Gravity:"           << planets[i].gravity                 << endl
         << left << setw(20) << "Rotation Perdiod:"  << planets[i].rotationPerdiod         << endl
         << left << setw(20) << "Length of Day:"     << planets[i].lengthOfDay             << endl
         << left << setw(20) << "Distance from Sun:" << planets[i].distanceFromSun         << endl
         << left << setw(20) << "Mean Temperature:"  << planets[i].meanTemperature         << endl
         << left << setw(20) << "Number of Moons:"   << planets[i].numberOfMoons           << endl
         << left << setw(20) << "Ring System?:"      << (planets[i].ringSystem?"Yes":"No") << "\n" << endl;
  }
}

/*
 * Main Program
 * Description: This program reads planet data into an array of structures
 *              and displays displays read data for the user. 
 */
int main() {

  // Create file stream object
  ifstream inputFile; 

  const string PLANET_FILE = "planetData.dat";

  // Open file to read from
  inputFile.open(PLANET_FILE);

  if(inputFile) { // If file successfully opens

    const int  NUM_PLANETS = 10;     // Number of planets
    PlanetData planets[NUM_PLANETS]; // Array of structures
    int        counter = 0;          // Loop counter

    string     units;                // Holds units    
    string     headers;              // Holds file headers

    getline(inputFile, units);       // Grab the first line in file
    getline(inputFile, headers);     // Grab the second line in file

    // Read file into array of structures
    while(inputFile >> planets[counter].name            >> planets[counter].mass            >> planets[counter].diameter 
                    >> planets[counter].gravity         >> planets[counter].rotationPerdiod >> planets[counter].lengthOfDay 
                    >> planets[counter].distanceFromSun >> planets[counter].meanTemperature >> planets[counter].numberOfMoons 
                    >> planets[counter].ringSystem      && (counter < NUM_PLANETS))
      counter++;
          
    // Display planets
    displayPlanets(planets, NUM_PLANETS);
    
  }
   else { // File could not open
    
    cout << "\nAlert: File " << PLANET_FILE << " could not open." << endl;
    exit(EXIT_FAILURE); // Indicate file open failure

  }
  
  return 0;  
}
