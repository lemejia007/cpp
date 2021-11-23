/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Programming Assignment 7
 * DUE DATE:   11/12/2021
 */

/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <fstream> 
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

/********************************************************
 *                  Global Constants 
*/
// Constant for file containing common passwords
const string COMMON_PASSWORDS = "commonPasswords.dat"; 


/********************************************************
 *                 Function Definitions
*/

/*
 * Function name: createArray()
 * Description:   Allocate an array of the specified type and size, 
 *                and return the pointer.
 * 
 * Parameter:     Size of array
 */
string* createArray(int size) {

  // Return null pointer if size is 0 or negative
  if(size <=0) 
    return nullptr;

  // Dynamically allocate new array
  string* newArr = new string[size];

  // Return pointer from function
  return newArr;

}

/*
 * Function name: readData()
 *
 * Description:   Read data from the specified stream object and read 
 *                the data from tHe object into the array.
 *
 * Parameters:    Open stream object
 *                Pointer to a string array
 *                Size of array
 */
void readData(ifstream &input, string* array, int size) {

  for (int i = 0; i < size; i++)
    input >> *(array + i);

}

/*
 * Function Name: getUserPassword()
 * Description:   Propmt the user to enetr a password to test and 
 *                return user input/said password.
 * 
 * Parameters:    None
*/
string getUserPassword() {
  
  // Holds user input
  string password;

  // Prompt user
  cout << "\nEnter a password to determine its strength ('quit' to exit):" << endl;

  // Store user input
  getline(cin, password);

  // Return user input
  return password;
}

/* 
 * Function name: linearSearch
 * Description:   Looks for and returns the position of the search value 
 *                in the array. Returns -1 if not found.
 * 
 * Parameters:    String array
 *                Size of array
 *                Search value (user input)
 */
int linearSearch(string* array, int count, string userInput) {

  int index = 0;      // Used as a subscript to search the array
  int position = -1;  // To record the position of search value
  bool found = false; // Flag to indicate if value was found

  while (index < count && !found) {

    if (array[index] == userInput) { // If the value is found
      found = true; // Set the flag
      position = index; // Record the value's subscript
    }
    index++; // Go to the next element
  }
  return position; // Return the position, or -1
}

/*
 * Function Name: calculateEntropy()
 * Description:   Calculates and returns the entropy of a given 
 *                password.
 * 
 * Parameters:    A string value
 *                Pool size
*/
int calculateEntropy(string userInput, int poolSize) {

    int l = userInput.length(); // Password length
    int r = poolSize;                 // Pool size

    // Entropy formula
    int e = (log(pow(r, l)) / log(2));

    // Return password entropy
    return e;

}

/*
 * Function Name: displayPasswordStrength()
 * Description:   Displays the password strength rating based
 *                on its entropy.
 * 
 * Parameters:   Password entropy 
 *                 
*/
void displayPasswordStrength(string userInput, int entropy) {

  if(entropy < 28)
    cout << "Password " << "'" << userInput << "'" << " stength is: Very Weak" << endl;
  else if(entropy >= 28 && entropy <= 35)
    cout << "Password " << "'" << userInput << "'" << " stength is: Weak" << endl;
  else if(entropy >= 36 && entropy <= 59)
    cout << "Password " << "'" << userInput << "'" << " stength is: Reasonable" << endl;
  else if(entropy >= 60 && entropy <= 127)
    cout << "Password " << "'" << userInput << "'" << " stength is: Strong" << endl;
  else if(entropy >= 128)
    cout << "Password " << "'" << userInput << "'" << " stength is: Very Strong" << endl;

}

/********************************************************
*  Main program
*  Description: This program performs a password strength 
*               analysis by looking up the password in a common 
*               password table and/ or calculates its strength 
*               rating by calculating the "entropy" of said 
*               password. 
*/

int main() {

  // Create file stream object
  ifstream inputFile; 

  // Open file to read from
  inputFile.open(COMMON_PASSWORDS);

  if(inputFile) { // If file successfully opens
    
    // Read and store the first value in file
    // First value in input file = data count
    int count;         
    inputFile >> count;

    // Dynamically allocate a new array
    string* commonPasswordsArr = createArray(count);

    // Call procedure to read data from the open input strean object
    readData(inputFile, commonPasswordsArr, count);

    // Close input file
    inputFile.close();

    // Ask user for a password to test and store in userPassword
    string userPassword; 
    userPassword = getUserPassword(); 

    while(userPassword != "quit") { // While user does not wish to exit the program

      // Compare user input with values stored in common passwords array
      int position = linearSearch(commonPasswordsArr, count, userPassword); 

      if(position >= 0) { // User password is a common passwords

        // Notify user and display password's position
        cout << "\nPassword " << "'" << userPassword << "'" << " ranks " << position 
             << " in common passwords list." << endl
             << "Try a more unique password." << endl;
      } 
      else if(userPassword == "") {

        // Notify user that blank is not valid
        cout << "You did not eneter a password. Please try again." << endl;

      } else { // Password is not a common password

        // Calculate password entropy and display strength rating
        displayPasswordStrength(userPassword, calculateEntropy(userPassword, 94));

      }
    
      // Ask user for a password to test and store in userPassword 
      userPassword = getUserPassword(); 

    }

    // Delete Dynamically allocated array from memory
    delete [] commonPasswordsArr;

    // Give address of null pointer to commonPasswordsArr
    commonPasswordsArr = nullptr;

  } 
  else { // File could not open
    
    cout << "\nAlert: File " << COMMON_PASSWORDS << " could not open." << endl;
    exit(EXIT_FAILURE); // Indicate file open failure

  }

  // Program has ended
  cout << "\nEnd of program." << endl;

  // Indicate program executed successfully 
  return 0;
  
}
