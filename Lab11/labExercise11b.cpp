/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Lab Exercise 11b
 * DUE DATE:   11/30/2021
 *
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

/*************************************************
 *          Abstract Data Structures 
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

/*
 * Function name: createArray()
 * Description:   Allocate an array of the specified type and size, 
 *                and return the pointer.
 * 
 * Parameter:     Size of array
 */
PlanetData* createArray(int size) {
  // Return null pointer if size is 0 or negative
  if(size <=0) 
    return nullptr;
  // Dynamically allocate new array
  PlanetData* newArr = new PlanetData[size];
  // Return pointer from function
  return newArr;
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

/**********************************************
 * Main Program
 * Description: Read a list of planetary data from a file into a 
 *              dynamically allocated array of structures, then 
 *              output them in the requested format. The use of
 *              functions is encouraged.
 */
int main() {

  // Global constants
  const int    PLANET_COUNT       = 11;               // Number of planets
  const int    OUTPUT_FIELD_WIDTH = 10;               // Output spacing
  const string PLANET_FILE        = "planetData.dat"; // Planet file to open

  // Create input file stream object
  ifstream inputFile; 

  // Open file to read from
  inputFile.open(PLANET_FILE);

  if(inputFile) { // If file successfully opens

    // Dynamically create an array of planet structures
    PlanetData* planets = createArray(PLANET_COUNT);

    // Read the first line in file
    string headers;             
    getline(inputFile, headers);

    // Read the second line in file
    string units;                
    getline(inputFile, units);               

    // Read file into array of structures
    int counter = 0; // Loop counter
    while(inputFile >> planets[counter].name            >> planets[counter].mass            >> planets[counter].diameter 
                    >> planets[counter].gravity         >> planets[counter].rotationPerdiod >> planets[counter].lengthOfDay 
                    >> planets[counter].distanceFromSun >> planets[counter].meanTemperature >> planets[counter].numberOfMoons 
                    >> planets[counter].ringSystem      && (counter < PLANET_COUNT))
      counter++;

    // Close input file
    inputFile.close();

    // Create output file stream object
    ofstream outputFile;

    // Open file to write into
    outputFile.open("planetData.out");

    // Write file headers
    outputFile << left << setw(OUTPUT_FIELD_WIDTH) << getTSField(headers, 1) 
               << setw(OUTPUT_FIELD_WIDTH)         << getTSField(headers, 2) 
               << setw(OUTPUT_FIELD_WIDTH)         << getTSField(headers, 3) 
               << setw(OUTPUT_FIELD_WIDTH)         << getTSField(headers, 4) 
               << setw(OUTPUT_FIELD_WIDTH)         << getTSField(headers, 5) 
               << setw(OUTPUT_FIELD_WIDTH)         << getTSField(headers, 6) 
               << setw(OUTPUT_FIELD_WIDTH)         << getTSField(headers, 7) 
               << setw(OUTPUT_FIELD_WIDTH)         << getTSField(headers, 8) 
               << setw(OUTPUT_FIELD_WIDTH)         << getTSField(headers, 9) 
               << setw(OUTPUT_FIELD_WIDTH)         << getTSField(headers, 10) << endl;

    // Write file units
    outputFile << setw(OUTPUT_FIELD_WIDTH)         << getTSField(units, 1) 
               << setw(OUTPUT_FIELD_WIDTH)         << getTSField(units, 2) 
               << setw(OUTPUT_FIELD_WIDTH)         << getTSField(units, 3) 
               << setw(OUTPUT_FIELD_WIDTH)         << getTSField(units, 4) 
               << setw(OUTPUT_FIELD_WIDTH)         << getTSField(units, 5) 
               << setw(OUTPUT_FIELD_WIDTH)         << getTSField(units, 6) 
               << setw(OUTPUT_FIELD_WIDTH)         << getTSField(units, 7) 
               << setw(OUTPUT_FIELD_WIDTH)         << getTSField(units, 8) 
               << setw(OUTPUT_FIELD_WIDTH)         << getTSField(units, 9) 
               << setw(OUTPUT_FIELD_WIDTH)         << getTSField(units, 10) << endl;

    // Write planet data
    for(int i = 0; i < PLANET_COUNT; i++) {

    outputFile << setw(OUTPUT_FIELD_WIDTH)         << planets[i].name                     
               << setw(OUTPUT_FIELD_WIDTH)         << planets[i].mass                    
               << setw(OUTPUT_FIELD_WIDTH)         << planets[i].diameter                
               << setw(OUTPUT_FIELD_WIDTH)         << planets[i].gravity                 
               << setw(OUTPUT_FIELD_WIDTH)         << planets[i].rotationPerdiod        
               << setw(OUTPUT_FIELD_WIDTH)         << planets[i].lengthOfDay             
               << setw(OUTPUT_FIELD_WIDTH)         << planets[i].distanceFromSun         
               << setw(OUTPUT_FIELD_WIDTH)         << planets[i].meanTemperature         
               << setw(OUTPUT_FIELD_WIDTH)         << planets[i].numberOfMoons           
               << setw(OUTPUT_FIELD_WIDTH)         <<(planets[i].ringSystem?"Yes":"No") << "\n" ;
    }

    // Close output file
    outputFile.close();

    // Delete dynamically allocated array from memory
    delete [] planets;

    // Give address of null pointer to planets array
    planets = nullptr;
    
  }
   else { // File could not open
    
    cout << "\nAlert: File " << PLANET_FILE << " could not open." << endl;
    exit(EXIT_FAILURE); // Indicate file failed to open

  }
  
  cout << "Program complete";
  
  return 0;
}
