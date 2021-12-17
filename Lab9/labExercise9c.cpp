
/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Lab Exercise 9C
 * DUE DATE:   11/09/2021
 *
 */

/* Place Library References Here */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

const string FILENAME = "scores.dat";

/*
 * Function name: createArray
 * Description:   Allocate an array of the specified type and size, 
 *                and return the pointer.
 * Parameter:     size of array
 *
 */
float* createArray(int size) {

  // Return null pointer if size is 0 or negative
  if(size <=0) 
    return nullptr;

  // Dynamically allocate new array
  float* newArr = new float[size];

  return newArr;

}

/*
 * Function name: readArray
 *
 * Description:   Read data from the specified stream object and read 
 *                the data from te object nto the array.
 *
 * Parameters:    open stream object
 *                pointer to a float array
 *                size of array
 */
void readArray(ifstream &dataIn, float array[], int size) {
  for (int i = 0; i < size; i++)
    dataIn >> array[i];
}

/*
 * Function name: writeArray
 *
 * Description:   write data from the array to the screen. The precision, 
 *                field width, and itemsPerRow are given default values.
 *
 * Parameters:    pointer to a float array
 *                size of array
 *                precision of output
 *                field width of output values
 *                number of items displayed per row
 */
void writeArray(float array[], int size, int precision = 2, int width = 7, int itemsPerRow = 12) {
  cout << fixed << setprecision(precision);
  
  cout << "Displaying " << size << " items." << endl;

  for (int i = 0; i < size; i++) {
    cout << setw(width) << array[i];
    if ((i + 1) % itemsPerRow == 0)
      cout << endl;
  }
}

/**
 *  Function name: lowest()
 */
void lowest(float scores[], int counter) {
  float lowest;  // Lowest score
  lowest = scores[0];
    for (int i = 1; i < counter; i++) {
      if (scores[i] < lowest) {
        lowest = scores[i];
      }
    }
  cout << fixed << showpoint << setprecision(2);
  cout << left << setw(9) << "Lowest:" << lowest << endl;
}

/**
 *  Function name: highest()
 */
void highest(float scores[], int counter) {
  float highest;  // Highest score
  highest = scores[0];
    for (int i = 1; i < counter; i++) {
      if (scores[i] > highest) {
        highest = scores[i];
      }
    }
  cout << fixed << showpoint << setprecision(2);
  cout << left << setw(9) << "Highest:" << highest << endl;
}

/*
 * Main Program
 * Description: This lab exercise will dynamically allocate an 
 *              array in a function and return the pointer.
 */
int main() {
  
  ifstream dataInput(FILENAME);

  int count; // First value in input file = data count
  dataInput >> count;

  // Call the createArray function and assign the pointer it returns to "fPtr"
  float *fPtr = createArray(count);

  // Call procedure to read array from the open input strean object
  readArray (dataInput, fPtr, count);

  dataInput.close(); // close the input stream

  // Output the array
  writeArray (fPtr, count);

  // Challenge
  cout << "\n";
  lowest(fPtr, count);
  highest(fPtr, count);

  // Delete Dynamically allocated memory
  delete [] fPtr;

  // Give address of null pointer to fPtr
  fPtr = nullptr;
  
  
  return 0;
}
