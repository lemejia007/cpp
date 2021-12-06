
/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Programming Assingment 9
 * DUE DATE:   12/05/2021
 *
 */

/* Place Library References Here */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**********************************************************
*                     Enumeration types
*/
enum  Status {OFF, HEAT, COOL}; // States that thermostat can assume
enum  Day    {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};

/**********************************************************
*                    Limits and defaults
*/
const float TEMP_MIN     =   0.0; // Lowest temperature (degrees)
const float TEMP_MAX     = 110.0; // Maximum temperature (degrees);
const float TEMP_DEFAULT =  71.0; // Default temperature (degrees)

/**********************************************************
*                    Structures
*/
struct ThermState { // The following struture represents the thermostate state
  float  setTemperature  = TEMP_DEFAULT; // Target temperature
  Status currentMode     = OFF;          // Current thermostat status
  float  realTemperature = TEMP_DEFAULT; // Ambient temperature
};

/**********************************************************
 *                   Getters/ Setters
*/

/*
* Function name: setMode()
*
* Parameters:    Status enum
*                Pointer to a ThermState structure
*/
void setMode (Status mode, ThermState* therm) { 
  therm->currentMode = mode; // Set current mode
}     

/*
* Function name: getCurrentMode()
*
* Parameters:    Pointer to a ThermState structure
*/
Status getCurrentMode(ThermState* therm) { 
  return therm->currentMode; // Get current mode
}     

/*
* Function name: setSetTemperature()
*
* Parameters:    A float
*                Pointer to a ThermState structure
*/
void setSetTemperature(float temp, ThermState* therm) { 
  float validTemp;
  validTemp = temp;
  if(validTemp < TEMP_MIN || validTemp > TEMP_MAX) {
    cout << "\nPlease eneter a temperature between " << TEMP_MIN << " and " << TEMP_MAX << endl;
    cin >> validTemp;
  }
  therm->setTemperature = validTemp; // Set the current set temperature
}

/*
* Function name: getSetTemperature()
*
* Parameters:    Pointer to a ThermState structure
*/
float getSetTemperature(ThermState* therm) { 
  return therm->setTemperature; // Return the current set temperature
}

/*
* Function name: getRealTemperature()
*
* Parameters:    Pointer to a ThermState structure
*/
float getRealTemperature(ThermState* therm) { 
  return therm->realTemperature; // Return real temperature
}

/*
* Function name: showStatus()
*
* Parameters:    Pointer to a ThermState structure
*/
void showStatus(ThermState* therm) {
  string status; // Temporarily holds status
  string mode;   // Temperarily holds mode

  // Assign status
  if(therm->currentMode == HEAT && therm->setTemperature > therm->realTemperature) {
       status = "HEATING";
  } else if(therm->currentMode == COOL && therm->setTemperature < therm->realTemperature) {
       status = "COOLING";
  } else {
       status = "IDLE";
  }

  // Convert current mode
  if(therm->currentMode == 0) {
    mode = "OFF";
  } else if(therm->currentMode == 1) {
    mode = "HEAT";
  } else if(therm->currentMode == 2) {
    mode = "COOL";
  }
  
  // Display current settings to user
  cout << left << setw(16) << "\nMode"             << ": " << mode                   << endl
       << left << setw(16) << "Set Temperature"    << ": " << therm->setTemperature  << endl
       << left << setw(16) << "Real Temperature"   << ": " << therm->realTemperature << endl
       << left << setw(16) << "Status"             << ": " << status         << "\n" << endl;
}

/*
* Function name: reset()
*
* Parameters:    Pointer to a ThermState structure
*/
void reset(ThermState* therm) {
  // Reset method to reset thermostat to initial state
  therm->setTemperature  = TEMP_DEFAULT;
  therm->currentMode     = OFF;
  therm->realTemperature = TEMP_DEFAULT;
}

/*
* Function name: userChoice()
*
* Parameters:    None
*/
int userChoice() {

  int choice; // Temporarily holds user choice
  cout << "\nThermostat Control Menu"                          << endl
       << " 0 - Quit"                                          << endl
       << " 1 - Off"                                           << endl
       << " 2 - Heat"                                          << endl
       << " 3 - Cool"                                          << endl
       << " 4 - Set temperature"                               << endl
       << " 5 - Show status"                                   << endl
       << " 6 - Reset thermostat"                              << endl
       << "\nWhat would you like to do?"                       << endl
       << "Enter the number corresponding to your choice."     << endl;       
       cin >> choice;

       // Validate user input
       while(choice < 0 || choice > 6) {
         cout << "That is not a valid option, try again." << endl;
         cin >> choice;
       }

  return choice;
}

/******************************************************
 * Main Program
 * Description: Reads menu commands and manages the thermostat using the thermostat
 *              functions
 *
 * Thermostat Control Menu:
 *  0 - Quit
 *  1 - Off
 *  2 - Heat
 *  3 - Cool
 *  4 - Set temperature
 *  5 - Show status
 *  6 - Reset thermostat 
*/
int main() {

  // Assign a pointer to newly instantiated ThermState structure
  ThermState  therm    = ThermState();
  ThermState* thermPtr = nullptr;
  thermPtr             = &therm;

  // Get user thermostat control menu choice
  int choice = userChoice();

  // Present the menu, then repeatedly read commands from the user
  // until 'Quit' is entered
  while(choice != 0) {

    // Holds user temperature of choice
    float temperature;

    switch(choice) {
      
      case 1:
        setMode(OFF, thermPtr);
        break;
      case 2:
        setMode(HEAT, thermPtr);
        break;
      case 3:
        setMode(COOL, thermPtr);
        break;
      case 4:
        cout << "What temperature do you want to set the thermostat to?" << endl;
        cin >> temperature;
        setSetTemperature(temperature, thermPtr);
        break;
      case 5:
        showStatus(thermPtr);
        break;
      case 6:
        reset(thermPtr);
        break;
      default:
        cout << "You entered an invalid option" << endl;
        break;
      }

      cout << "Enter another option." << endl;
      cin >> choice;

      // Validate user input
      while(choice < 0 || choice > 6) {
        cout << "That is not a valid option, try again." << endl;
        cin >> choice;
      }

  }

  cout << "\nEnd of program." << endl;

  return 0;
}
