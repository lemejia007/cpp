/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * INSTRUCTOR: Charles Locke
 * ASSIGNMENT: Lab Exercise 6c
 * STUDENT:    Luis Mejia
 * DUE DATE:   10/14/2021
 *
 */

/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

/********************************************************
 *
 *       Function Prototypes are Listed Here
 * All function definitions follow the main program
 *
 *********************************************************/

/********************************************************
 * 
 * Function Name: getUserChoice()
 * Description:   This function prompts the user for a choice
 *                and returns user's choice.
 *     
 */
char getUserChoice();

/********************************************************
 * 
 * Function Name: swap(int &x, int &y)
 * Description:   This function swaps the integer values passed
 *                into the function by reference.
 *     
 */
void swap(int &x, int &y);

/********************************************************
 * 
 * Function Name: swap(double &a, double &b)
 * Description:   This function swaps the double values passed
 *                into the function by reference.
 *     
 */
void swap(double &a, int &b);

/********************************************************
 * 
 * Function Name: displayIntegerSwap()
 * Description:   This function displays swap(int &x, int &y) 
 *                working.
 *     
 */
void displayIntegerSwap();

/********************************************************
 * 
 * Function Name: displayDoubleSwap()
 * Description:   This function displays swap(double &a, double &b) 
 *                working.
 *     
 */
void displayDoubleSwap();

/*
 * Main Program
 * Description: swap two numbers entered by the user
 */
int main() {

  char userChoice; // Holds user selecetion

  // Ask user to swap an int or a double
  userChoice = getUserChoice();

  while(userChoice != '0') {

    switch(userChoice) {
      case '1':
        displayIntegerSwap();
        break;
      case '2':
        displayDoubleSwap();
        break;
      default:
        cout << "Invalid Selection" << endl;
    }

    // Ask user to swap an int or a double
    userChoice = getUserChoice();

  }

  cout << "This program has ended.";

  return 0;
}

/*
 * Function Name: getUserChoice()
 */
char getUserChoice() {
  char choice;
  cout << "\nEnter  1  to swap two integers.\nEneter 2  to swap two doubles.\nEnter  0  to Quit." << endl;
  cin >> choice; 

  // Validate/verify user selection
	while(choice < '1' || choice > '2') {
		cout << "Please input a valid option." << endl;
		cin >> choice; 
	}

  return choice;
}

/*
 * Function Name: swap(int &x, int &y)
 */
void swap(int &x, int &y) {
  cout << "Swapping integer values passed into the function by reference." << endl;
  int xValue = x;
  int yValue = y;
  x = yValue;
  y = xValue;
}

/*
 * Function Name: swap(double &a, double &b)
 */
void swap(double &a, double &b) {
  cout << "Swapping double values passed into the function by reference." << endl;
  double aValue = a;
  double bValue = b;
  a = bValue;
  b = aValue;
}

/*
 * Function Name: displayIntegerSwap()
 */
void displayIntegerSwap() {
  int x,y; // values read by user
  
  // read x and y
  cout << "\nEnter two integer numbers separated by a space. Enter the same number twice to go back to the previous menu: ";
  cin >> x >> y;
  
  while (x != y) {

     cout << fixed << showpoint << setprecision(2);
    
    // show x y values
    cout << "Before swap: x = " << x << ";   y = " << y << endl;
    
    swap(x,y);    // swap x and y

    // show swapped values.
    cout << "After swap : x = " << x << ";   y = " << y << endl;

    // read x and y
    cout << "\nEnter two integer numbers separated by a space. Enter the same number twice to go back to the previous menu: ";
    cin >> x >> y;
  }
}

/*
 * Function Name: displayDoubleSwap()
 */
void displayDoubleSwap() {
  double a,b; // values read by user
  
  // read a and b
  cout << "\nEnter two double numbers separated by a space. Enter the same number twice to go back to the previous menu: ";
  cin >> a >> b;
  
  while (a != b) {
    
    cout << fixed << showpoint << setprecision(2);

    // show a b values
    cout << "Before swap: a = " << a << ";   b = " << b << endl;
    
    swap(a,b);    // swap a and b

    // show swapped values.
    cout << "After swap : a = " << a << ";   b = " << b << endl;

    // read x and y
    cout << "\nEnter two double numbers separated by a space. Enter the same number twice to go back to the previous menu: ";
    cin >> a >> b;

  }
}