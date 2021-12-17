
/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Lab Exercise 5a
 * DUE DATE:   09/28/2021
 *
 */

/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

/*
 * Main Program
 * Description: Uses a loop to calculate the value of a 
 * convergent series.
 */
int main() {
  
  const int     n    = 70000;    // number of iterations
        int     k    = 0;        // loop counter
        double  sum  = 0;        // summation of series

    
  // Begin while loop
  while(k <= n) {
      sum += (8/(16*pow(k, 2) + 16*k + 3));
      k++;
  }
    
    cout << sum << endl;

  return 0;  

}
