
/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Lab Exercise 13a
 * DUE DATE:   12/07/2021
 *
 */

/* Place Library References Here */

#include <math.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/* 
 * Put class definitions here
 */

// ??? 1. Add two (2) constructors to the Circle class.
// The first is the default constructor that initializes
// x, y, and r to 0.0, 0.0, and 1.0, respectuvely[46, 47]
// and the alternate constructor has three parameters that
// are assigned to x, y, and r. [53-55]

// Circle class specification
class Circle {
private:
  float x, y, r;
public:
  Circle() { // Default constructor
    x = 0.0;
    y = 0.0;
    r = 1.0;
  }  
  Circle(float xX, float yY, float radius) { // Overloaded constructor
    x = xX;
    y = yY;
    r = radius;
  }
  void setCenter(float, float);
  void setRadius(float);
  float getX() const;
  float getY() const;
  float getRadius() const;
  // ??? 2. Make getArea an inline member function
  float getArea() {
    return M_PI * pow(r,2);
  }
};

// class implementation

void Circle::setCenter(float X, float Y){
  x = X; y = Y;
}

void Circle::setRadius(float R) {
  r = R;
}

float Circle::getX() const {
  return x;
}

float Circle::getY() const {
  return y;
}

float Circle::getRadius() const {
  return r;
}

/*
 * Main Program
 * Description: This program creates two Circle instances to 
 *              demonstrate in-line methods and the use of 
 *              overloaded constructors. 
 */

int main () {

  // ??? 3. Define an instance of Circle called C1 that uses the
  // default constructor. (The 'C' in 'C1' is a capital letter.)
  
  // Pointer to a circle
  Circle* C1 = new Circle;

  // Display default constructore initiaization values
  cout << "\nRadius = " << C1->getRadius() << endl;
  cout << "X      = " << C1->getX()      << endl;
  cout << "Y      = " << C1->getY()      << endl;
  cout << "Area   = " << C1->getArea()    << endl;

  
  // ??? 4. Define an instance of Circle called C2 that uses
  // the second constructor and initilazates x, y, and r to
  // 1.2, 3.4 and 5.6, respectively. (The 'C' in 'C2' is a capital letter.)

  // Pointer to a circle
  Circle*  C2 = new Circle(1.2, 3.4, 5.6); 
  
  // Display second constructor initiaization values
  cout << endl;
  cout << "Radius = " << C2->getRadius()  << endl;
  cout << "X      = " << C2->getX()       << endl;
  cout << "Y      = " << C2->getY()       << endl;
  cout << "Area   = " << C2->getArea()    << endl;

  // Delete objects from memory
  delete C1;
  delete C2;

  C1  = nullptr;
  C2  = nullptr;

  return 0;
}
