/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Lab Exercise 3a
 * DUE DATE:   09/09/2021
 *
 */

/* Place Library References Here */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


/*
 * Main Program
 *
 * Description: The goal of this exercise is to practice and 
 * demonstrate output formatting using stream manipulators
 * such as fixed, setprecision, setw, showpoint, left and right.
 */


int main() {
    
    // Variables 
    string Ruler    = "1234567890";
    string Name     = "Luis";
    double Pi       = 3.141592654;
    double Phi      = 1.6180339887;
    double PhiPrime = 1 + 1/Phi;
    double Midway   = 17.5;
    
    // Console output
    cout << Ruler << endl;
    cout << right << setw(10) << Name << endl;
    cout << left << setw(6) << "-14" << right << "X" << endl;
    cout << fixed << setprecision(4)
         << right << setw(10) << Pi << endl;
    cout << fixed << setprecision(3)
         << left  << setw(9) << Phi << right << "X" << endl;
    cout << fixed << setprecision(3)
         << right << setw(7) << PhiPrime << endl;
    cout << fixed << setprecision(4)
         << right << setw(10) << Midway << endl;

  return 0;  
}
