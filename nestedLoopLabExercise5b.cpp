
/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Lab Exercise 5c
 * DUE DATE:   09/30/2021
 *
 */

/* Place Library References Here */
#include <iostream>

using namespace std;

/*
 * Main Program
 * Description: 
 *   1. Prints a symbol n times when the user repeatedly enters a positive integers n.
 *   2. n must be >= min and <= max.
 *   3. Program ends when the number is out of range.
 */
int main() {

  // Use these constants and variables in the program
  const int  MIN    =   0; // smallest value the user can enter
  const int  MAX    =  40; // largest number user can enter
  const char SYMBOL = '%'; // output symbol; can change to any character
  int        n      =   0; // positive integer entered by user.

  // Begin while loop
  while(n >= MIN && n <= MAX) {
      
    // Obtain new n
    cin >> n;

    // Break out of loop if n is less than min or greater than max
    if(n < MIN || n > MAX) {
      cout << "Your number is out of range." << endl;
      break;
    }

    // Challenge
    // cout << n << "|";

    for(int i = 1; i <= n; i++) {
      cout << SYMBOL;
    }

    cout << endl;
  }


  
  return 0;
}
