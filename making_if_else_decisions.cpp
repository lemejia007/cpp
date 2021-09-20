/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Programming Assignment 2
 * DUE DATE:   09/22/2021
 *
 */

/* Place Library References Here */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

/*
 * Main Program
 * Description: This program will help a cellular company bill their customers based on data 
 * usage and customer status/type.
 */


int main() {
    
    // Declare program constants
    const string SENTINEL_VALUE       = "000000"; // SENTINEL_VALUE ends the program
    const double BASE_RATE            = 12.00;    // base rate price
    const double GIGABYTES_ALLOWED    = 1.00;     // gigabytes allowed before fee
    const double FEE                  = 10.00;    // fee if gigabytes used is over 1.00
    const double RETIREE_DISCOUNT     = 0.10;     // discount for a retiree customer
    const double STUDENT_DISCOUNT     = 0.20;     // discount for a student customer 
    
    // Declare program variables
    string customerID;                            // customer's identification number
    char   customerStatus;                        // 'n'(normal), 'r'(retiree), 's'(student)
    double gigabytesUsed;                         // gigabytes consumed by the customer
    double amount;                                // amount after discount (if aplicabale)
    double totalAmount;                           // total amount of all customer schedule rates

    // Begin do-while loop
    do {

       // temporary storage for customer ID 
       string saveID;

       // Input customer ID
       cout << "Enter customer ID:" << endl;
       getline(cin, saveID);
    
       // Break out of loop if user enters sentinel value
       if(saveID == SENTINEL_VALUE) {
        break;
       }

       //-------------------------------------------------------

       // assign value of saveID to customerID
       customerID = saveID;

       // Input customer status
       cout << "Enter customer status: 'N'(normal), 'R'(retiree), 'S'(student)" << endl;
       cin >> customerStatus;

       // Input customer gigabyte consumption
       cout << "Enter customer gigabyte consumption" << endl;
       cin >> gigabytesUsed;

       //-------------------------------------------------------

       // Compute amount based on customer status and data consumption 
       if((customerStatus == 'n' || customerStatus == 'N') && (gigabytesUsed <= GIGABYTES_ALLOWED)) {
           amount = BASE_RATE;
       } else if((customerStatus == 'n' || customerStatus == 'N') && (gigabytesUsed > GIGABYTES_ALLOWED)) {
           amount = BASE_RATE + FEE;
       } else if((customerStatus == 'r' || customerStatus == 'R') && (gigabytesUsed <= GIGABYTES_ALLOWED)) {
           amount = BASE_RATE - (RETIREE_DISCOUNT * BASE_RATE);
       } else if((customerStatus == 'r' || customerStatus == 'R') && (gigabytesUsed > GIGABYTES_ALLOWED)) {
           amount = BASE_RATE - (RETIREE_DISCOUNT * BASE_RATE) + FEE;
       } else if((customerStatus == 's' || customerStatus == 'S') && gigabytesUsed <= GIGABYTES_ALLOWED) {
           amount = BASE_RATE - (STUDENT_DISCOUNT * BASE_RATE);
       } else if((customerStatus == 's' || customerStatus == 'S') && (gigabytesUsed > GIGABYTES_ALLOWED)) {
           amount = BASE_RATE - (STUDENT_DISCOUNT * BASE_RATE) + FEE;
       }

       // Compute total amount
       totalAmount += amount;

       //----------------------------------------------------------

       // Display rate schedule/ output
       cout << fixed << setprecision(2) << showpoint <<  endl;
       cout << left << setw(20) << "Customer ID:" << right << setw(9) << customerID << endl;
       cout << left << setw(20) << "Customer Status:" << right << setw(9) << customerStatus << endl;
       if(customerStatus == 'r' || customerStatus == 'R') {
           cout << left << setw(20) << "Discount (percent):" << "%" << setw(8) << right 
             << (RETIREE_DISCOUNT * 100) << endl;
       } else if(customerStatus == 's' || customerStatus == 'S') {
           cout << left << setw(20) << "Discount (percent):" << "%" << setw(8) << right 
                << (STUDENT_DISCOUNT * 100) << endl;
       } else {
           cout << left << setw(20) << "Discount (percent):" << "%" << setw(8)  << right 
                << 00.00 << endl;
       }
       cout << left << setw(20) << "Gigabytes Used:" << right << setw(9) << gigabytesUsed << endl;
       cout << left << setw(20) << "Amount:" << "$" << right << setw(8) << amount << "\n" << endl;
       cout << left << setw(20) << "Total Amount:" << "$" << right << setw(8) << totalAmount << endl;
       cout << endl;

       cin.ignore(); 
       
    } while(true); // loop until break 

    cout << "\nProgram has ended.\n";
    
  return 0;  
} 
