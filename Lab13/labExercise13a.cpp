
/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Lab Exercise 13a
 * DUE DATE:   12/02/2021
 *
 */

/* Place Library References Here */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Circle class specification

class Circle {

   // Private members
   private: 
      float x = 0.0; // Circle's X coordinate
      float y = 0.0; // Circle's Y coordinate
      float r = 1.0; // Circle's radius

   // Public members
   public:
      void  setCenter(float x, float y); // Sets  a circle's center
      void  setRadius(float r);          // Sets  a circle's radius
      float getX()      const;           // Gets  a circl's  X coordinate
      float getY()      const;           // Gets  a circl's  Y coordinate
      float getRadius() const;           // Gets  a circle's radius
      float getArea()   const;           // Gets  a circle's area
};

// Circle class implementation

/*
* Function name: setCenter()
*
* Parameters:    Circles center (x.y)
*/
void Circle::setCenter(float xX, float yY) {
   x = xX; // Set x
   y = yY; // Set y
}

/*
* Function name: setRadius()
*
* Parameters:    Circle's radius
*/
void Circle::setRadius(float radius) {
   r = radius; // Set r
}

/*
* Function name: getX()
*
* Parameters:    None
*/
float Circle::getX() const {
   return x; // Return x
}

/*
* Function name: getY()
*
* Parameters:    None
*/
float Circle::getY() const {
   return y; // Return y
}

/*
* Function name: getRadius()
*
* Parameters:    None
*/
float Circle::getRadius() const {
   return r; // Return radius
}

/*
* Function name: getArea()
*
* Parameters:    None
*/
float Circle::getArea() const {
   return M_PI*pow(r,2); // Return area 
}
/*
 * Main Program
 * Description: This program creates a simple Circle object to 
 *              demonstrate basic knowledge in declaring a class 
 *              specification, writing method implementations, 
 *              creating a class instance, and using class methods.
 *              
 */

int main () {  

   // Dynamically create a Circle object
   Circle* C = nullptr;
   C = new Circle;

   // Set circle parameters using mutator member functions
   C->setCenter(1.2, 3.4);

   // Set circle radius using mutator member functions
   C->setRadius(5.0);

   // Demonstrate accessor functions
   cout << "Radius = " << C->getRadius() << endl
        << "X      = " << C->getX()      << endl
        << "Y      = " << C->getY()      << endl
        << "Area   = " << C->getArea()   << endl;

   // Delete Circle object from memory
   delete C;
   C = nullptr;

   return 0;
}
