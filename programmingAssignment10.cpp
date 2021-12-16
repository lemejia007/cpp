
/********************************************************
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Programming Assingment 10
 * DUE DATE:   12/12/2021
 *
 */

/********************************************************
 *                 Library References 
*/
#include "Thermostat.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;    

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

  // Assign a pointer to newly instantiated Thermostat object
  Thermostat* therm = new Thermostat();

  // Get user thermostat control menu choice
  int choice = userChoice();

  // Present the menu, then repeatedly read commands from the user
  // until 'Quit' is entered
  while(choice != 0) {

    // Holds user temperature of choice
    float temperature;

    switch(choice) {
      
      case 1:
        therm->setMode(Thermostat::OFF);
        break;
      case 2:
        therm->setMode(Thermostat::HEAT);
        break;
      case 3:
        therm->setMode(Thermostat::COOL);
        break;
      case 4:
        cout << "What temperature do you want to set the thermostat to?" << endl;
        cin >> temperature;
        therm->setSetTemperature(temperature);
        break;
      case 5:
        therm->showStatus();
        break;
      case 6:
        therm->reset();
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

  // Delete object from memory
  delete therm;
  therm = nullptr;

  cout << "\nEnd of program." << endl;

  return 0;
}
