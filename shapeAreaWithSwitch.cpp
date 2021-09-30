/*
 * A menu drive program demonstration that will ask the user to select
 * one of several shapes, ask the user for the parameters of that
 * shape, then will calulate and output the area of that shape.
 *
 */

/* 
 * File:   shapeAreaLab4c.cpp
 * Author: Luis Mejia
 * Created on September 23, 2020
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

/*
 * Main Program
 * 
 * Present a menu of shapes to the user. The user will select one of
 * the objects and enter the appropriate parameters. The paramters
 * and the area of the shape will be displayed. 
 *
 * The menu selections are:
 *
 *    0 Quit
 *    1 Triangle
 *    2 Square
 *    3 Rectangle
 *    4 Circle
 *    5 Ellipse 
 *    6 Regular Polygon 
 */
int main() {
  
  // 1. Put variable declarations here
  int selection = 0;                    // variable to hold user selection - do not change
  double length;                        // shape's length
  double width;                         // shape's width
  double base;                          // shape's base
  double height;                        // shape's height
  double radius;                        // shape's radius
  double side;                          // shape's side
  double sideA;                         // shape's Major radius
  double sideB;                         // shape's Minor radius
  double sideLength;                    // shape's side length
  double sideCount;                     // shape's number of sides
  double perimeter;                     // shape's perimeter
  double area;                          // shape's area
  
  
  while (true)
    {
       
      // 2. Output the menu menu and get the user's selection  [113] 
      cout << endl;
      cout << left << "Menu Options:" << endl;
      cout << "----------------------------------------" << endl;
      cout << right << setw(10) << "0 - Quit" << endl;
      cout << right << setw(10) << "1 - Triangle" << endl;
      cout << right << setw(10) << "2 - Square" << endl;
      cout << right << setw(10) << "3 - rectangle" << endl;
      cout << right << setw(10) << "4 - Circle" << endl;
      cout << right << setw(10) << "5 - Ellipse" << endl;
      cout << right << setw(10) << "6 - Regular Polygon" << endl;
      cout << endl;
      cout << left << "Enter the corresponding number for the shape you wish to get the area of:" << endl;
      cout << endl;

      selection = cin.get();

      // This will exit the loop if the user's selection is 0 (quit) - do not change
      if (selection == '0')
	      break; // exit the loop

      // Set output parameters
      cout << fixed << setprecision(2) << endl;

      // 3. Use switch statements here to calculate the areas of the shapes [119]
      switch(selection) {
          case '1':
            cout << "Enter the Triangle's base" << endl;
            cin >> base;
            cout << "Enter the Triangle's height" << endl;
            cin >> height; 
            area = (base * height)/2; 
            cout << endl;
            cout << "Shape: Triangle" << endl;
            cout << "Base = " << base << endl;
            cout << "Height = " << height << endl; 
            cout << "Area = " << area << endl;
            break;
         case '2':
            cout << "Enter the Square's side" << endl;
            cin >> side;
            area = side * side; 
            cout << endl;
            cout << "Shape: Square" << endl;
            cout << "Side = " << side << endl;
            cout << "Area = " << area << endl;
            break;
         case '3':
            cout << "Enter the Triangle's length" << endl;
            cin >> length; 
            cout << "Enter the Rectangle's's width" << endl;
            cin >> width;
            area = length * width; 
            cout << endl;
            cout << "Shape: Rectangle" << endl;
            cout << "Length = " << length << endl;
            cout << "Width = " << width << endl; 
            cout << "Area = " << area << endl;
            break;
         case '4':
            cout << "Enter the Circle's radius" << endl;
            cin >> radius;
            area = M_PI * pow(radius, 2); 
            cout << endl;
            cout << "Shape: Circle" << endl;
            cout << "Radius = " << radius << endl;
            cout << "Diameter = " << (radius * 2) << endl; 
            cout << "Area = " << area << endl;
            break;
         case '5':
            cout << "Enter the Ellipse's Major radius" << endl;
            cin >> sideA;
            cout << "Enter the Ellipse's Minor radius" << endl;
            cin >> sideB; 
            area = M_PI * sideA * sideB; 
            cout << endl;
            cout << "Shape: Ellipse" << endl;
            cout << "Major radius = " << sideA << endl;
            cout << "Minor radius = " << sideB << endl;
            cout << "Area = " << area << endl;
            break;
         case '6':
            cout << "Enter Regular Polygon's side length" << endl;
            cin >> sideLength;
            cout << "Enter the Regular Polygon's number of sides" << endl;
            cin >> sideCount;
            perimeter = sideLength * sideCount;
            area = ((pow(sideLength, 2) * sideCount)/(4 * tan(M_PI / sideCount))); 
            cout << endl;
            cout << "Shape: Regular Polygon" << endl;
            cout << "Number of sides = " << sideCount << endl;
            cout << "Side Length = " << sideLength << endl;
            cout << "Perimeter = " << perimeter << endl;
            cout << "Area = " << area << endl;
            break;
         default:
            cout << "You entered an invalid option.";
            cout << endl;
            break;
      }

    cin.ignore();

    } // end of while loop
  
  return 0;

}
