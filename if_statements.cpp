/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Lab Exercise 4a
 * DUE DATE:   09/16/2021
 *
 */

/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*
 * Main Program
 * Description: <describe what main program does>
 */
int main( ) {

  // Declare program constants
  const int sentinelVal =    0; // sentinel value ends program
  const int minVal      = -100; // minimum value used in program
  const int maxVal      =  100; // maximum value used in program

  // Declare program variables
  int positiveNum;              // amount of positive numbers
  int negativeNum;              // amount of negative numbers
  int evenNum;                  // amount of even numbers
  int oddNum;                   // amount of odd numbers
  int totalNum;                 // total amount of numbers

  // 'n' is the integer value entered by the user
  int n = 0;
  
  // this statement starts a "loop"
  do {

    // Get integer from user.
    //*** Notice, there is no prompt. Do not add one ***
    // When you run the program it will stop, waiting for
    // a number to be entered
    cin >> n;

    // Break out of loop if user enters sentinel value
    if (n == sentinelVal)
      break;

    cout << endl;
    cout << "\nThe number is " << n << "\n";
	//---------------------------------------------------
        
    
	
	/***   Put your Lab Exercise code in this area   ***/
	/*** Do not change any code outside of this area ***/
	/***       unless you accept the Challenge       ***/
  
    // Find out if n is positive
    if(n > sentinelVal) {
      cout << n << " is positive" << endl;
      positiveNum += 1;
    }

    // Find out if n is negative
    if(n < sentinelVal) {
      cout << n << " is negative" << endl;
      negativeNum += 1;
    }

    // Find out if n is even
    if((n % 2) == sentinelVal) {
      cout << n << " is even" << endl;
      evenNum += 1;
    }

    // Find out if n is odd
    if((n % 2) != sentinelVal) {
      cout << n << " is odd" << endl;
      oddNum += 1;
    }
  
    // Find out if n is within bounds
    if(n < minVal || n > maxVal) {
      cout << n << " is outside the range from " << minVal << " to " << maxVal << endl;
    }

    // Calculate total amount of numbers 
    totalNum = (positiveNum + negativeNum + evenNum + oddNum);
	
	  //---------------------------------------------------
    
    } while (true); // loop until break

   /*** If you accepted the challenge, output your statistics here ***/

    // Display output
    cout << left << setw(17) << "Positive numbers:" << right << setw(7) << positiveNum << endl;
    cout << left << setw(17) << "Negative numbers:" << right << setw(7) << negativeNum << endl;
    cout << left << setw(17) << "Even numbers:" << right << setw(7) << evenNum << endl;
    cout << left << setw(17) << "Odd numbers:" << right << setw(7) << oddNum << endl;
    cout << left << setw(17) << "Total numbers:" << right << setw(7) << totalNum << endl; 
  

    cout << "\nProgram has ended.\n";
  
    return 0;
  
}


