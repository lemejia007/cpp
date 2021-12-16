
// Implementation file for the Thermostat class.
#include "Thermostat.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

/*
* Function name: Thermostat()
*
* Parameters:    None
*/
Thermostat::Thermostat() {
  thermPtr                  = new ThermState;
  thermPtr->setTemperature  = TEMP_DEFAULT;
  thermPtr->currentMode     = OFF;
  thermPtr->realTemperature = TEMP_DEFAULT;
}

/*
* Function name: Thermostat() **overloaded**
*
* Parameters:    Float for temp
*                Status for mode
*/
Thermostat::Thermostat(float setTemp, Status mode) {
  thermPtr                  = new ThermState;
  thermPtr->setTemperature  = setTemp;
  thermPtr->currentMode     = mode;
  thermPtr->realTemperature = TEMP_DEFAULT;
}

/*
* Function name: ~Thermostat()
*
* Parameters:    None
*/
Thermostat::~Thermostat() {
  // Delete dynamically created structure 
  delete thermPtr; 
  thermPtr = nullptr;
}

/*
* Function name: setSetTemperature()
*
* Parameters:    A float
*/
void Thermostat::setSetTemperature(float temp) { 
  float validTemp;
  validTemp = temp;
  // Validate user input for temperature
  while(validTemp < TEMP_MIN || validTemp > TEMP_MAX) {
    cout << "\nPlease eneter a temperature between " << TEMP_MIN << " and " << TEMP_MAX << endl;
    cin >> validTemp;
  }
  thermPtr->setTemperature = validTemp; // Set the current set temperature
}

/*
* Function name: setMode()
*
* Parameters:    Status for mode
*/
void Thermostat::setMode (Status mode) { 
  thermPtr->currentMode = mode; // Set current mode
}

/*
* Function name: getCurrentMode()
*
* Parameters:    None
*/
Thermostat::Status Thermostat::getCurrentMode() const { 
  return thermPtr->currentMode; // Get current mode
}

/*
* Function name: getSetTemperature()
*
* Parameters:    None
*/
float Thermostat::getSetTemperature() const { 
  return thermPtr->setTemperature; // Return the current set temperature
}

/*
* Function name: showStatus()
*
* Parameters:    None
*/
float Thermostat::getRealTemperature() const { 
  return thermPtr->realTemperature; // Return real temperature
}       

/*
* Function name: showStatus()
*
* Parameters:    None
*/
void Thermostat::showStatus() {
  string status; // Temporarily holds status
  string mode;   // Temperarily holds mode

  // Assign status
  if(thermPtr->currentMode == HEAT && thermPtr->setTemperature > thermPtr->realTemperature) {
       status = "HEATING";
  } else if(thermPtr->currentMode == COOL && thermPtr->setTemperature < thermPtr->realTemperature) {
       status = "COOLING";
  } else {
       status = "IDLE";
  }

  // Convert current mode
  if       (thermPtr->currentMode == 0) {
    mode = "OFF";
  } else if(thermPtr->currentMode == 1) {
    mode = "HEAT";
  } else if(thermPtr->currentMode == 2) {
    mode = "COOL";
  }
  
  // Display current settings to user
  cout << left << setw(16) << "\nMode"             << ": " << mode                   << endl
       << left << setw(16) << "Set Temperature"    << ": " << thermPtr->setTemperature  << endl
       << left << setw(16) << "Real Temperature"   << ": " << thermPtr->realTemperature << endl
       << left << setw(16) << "Status"             << ": " << status         << "\n" << endl;
}

/*
* Function name: reset()
*
* Parameters:    None
*/
void Thermostat::reset() {
  // Reset method to reset thermostat to initial state
  thermPtr->setTemperature  = TEMP_DEFAULT;
  thermPtr->currentMode     = OFF;
  thermPtr->realTemperature = TEMP_DEFAULT;
}