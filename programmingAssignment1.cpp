/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Programming Assignment 1
 * DUE DATE:   09/12/2021
 *
 */

/* Place Library References Here */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

/*
 * Main Program
 * Description: This program will help users calculate a circle's diameter, 
 * circumference, area, and radius after inputting the circle's radius. 
 */


int main() {
    
    // Variables
    double radius, diameter, circumference, area, volume;
    
    // Gather user input.
       cout << "Enter the radius of a circle: " << endl;
       cin >> radius; 
    
    // Calculate the diameter of a circle.
       diameter =  2*radius;
        
    // Calculate the circumference of a circle.
       circumference = 2*M_PI*radius;
       
    // Calculate the area of a circle.
       area = M_PI*pow(radius, 2);
        
    // Calculate the volume of a sphere.
       volume = (4*M_PI*pow(radius, 3))/3;
       
    // Output results to console.
       cout << "The radius of the circle is " << radius << "\n"
            << "The diameter of the circle is " << diameter << "\n"
            << "The circumference of the circle is " << circumference << "\n"
            << "The area of the circle is " << area << endl;
       cout << "The volume of a sphere with radius " << radius << " is " 
            << volume << endl;

  return 0;  
} 
