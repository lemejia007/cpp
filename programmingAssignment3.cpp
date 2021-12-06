/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Programming Assignment 3
 * DUE DATE:   10/04/2021
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
 * Description: This program can help a cellular company bill their customers based on data 
 * usage and customer status/type.
 */


int main() {
    
    // Declare program constants
    const string SENTINEL_VALUE       = "000000"; // SENTINEL_VALUE ends the program
    const double BASE_RATE            = 12.00;    // base rate price
    const double GB_ALLOWED           = 1.00;     // gigabytes allowed before fee
    const double FEE                  = 10.00;    // fee if gigabytes used is over 1.00
    const double COST_PER_GB          = 5.53;     // cost per gigabyte
    const double RETIREE_DISCOUNT     = 0.10;     // discount for a retiree customer
    const double STUDENT_DISCOUNT     = 0.20;     // discount for a student customer 
    
    // Declare program variables
    string customerID;                            // customer's identification number
    char   customerStatus;                        // 'n'(normal), 'r'(retiree), 's'(student)
    int    normalCustomers            = 0;        // total number of normal customers
    int    retireeCustomers           = 0;        // total number of retiree customers
    int    studentCustomers           = 0;        // total number of student customers
    double usedGB;                                // gigabytes consumed by the customer
    double totalGB                    = 0;        // total amount of gigabytes used
    double averageEarnedPerGB;                    // average earned per gigabyte
    double profitLossValue;                       // profit or loss value
    double amount;                                // amount after discount (if aplicabale)
    double totalAmount;                           // total amount of all customer schedule rates

    // Input customer ID
      getline(cin, customerID);
    
    // Begin do-while loop
    while(customerID != SENTINEL_VALUE) {

      // Input customer status
      cout << "Enter customer status: 'N'(normal), 'R'(retiree), 'S'(student)" << endl;
      cin  >> customerStatus;

      // Input customer gigabyte consumption
      cout << "Enter customer gigabyte consumption" << endl;
      cin  >> usedGB;

      //-------------------------------------------------------

      // Compute amount based on customer status and data consumption 
      if((customerStatus == 'n' || customerStatus == 'N') && (usedGB <= GB_ALLOWED)) {
          normalCustomers++;
          amount = BASE_RATE;
      } else if((customerStatus == 'n' || customerStatus == 'N') && (usedGB > GB_ALLOWED)) {
          normalCustomers++;
          amount = BASE_RATE + FEE;
      } else if((customerStatus == 'r' || customerStatus == 'R') && (usedGB <= GB_ALLOWED)) {
          retireeCustomers++;
          amount = BASE_RATE - (RETIREE_DISCOUNT * BASE_RATE);
      } else if((customerStatus == 'r' || customerStatus == 'R') && (usedGB > GB_ALLOWED)) {
          retireeCustomers++;
          amount = (BASE_RATE + FEE) - (RETIREE_DISCOUNT * (BASE_RATE + FEE));
      } else if((customerStatus == 's' || customerStatus == 'S') && (usedGB <= GB_ALLOWED)) {
          studentCustomers++;
          amount = BASE_RATE - (STUDENT_DISCOUNT * BASE_RATE);
      } else if((customerStatus == 's' || customerStatus == 'S') && (usedGB > GB_ALLOWED)) {
          studentCustomers++;
          amount = (BASE_RATE + FEE) - (STUDENT_DISCOUNT * (BASE_RATE + FEE));
      }

      // Keep running total of gigabytes used
      totalGB += usedGB;

      // Keep running total of amount
      totalAmount += amount;

      // Compute profit/loss
      profitLossValue = totalAmount - (totalGB * COST_PER_GB);

      // Compute average earned per gigabyte
      averageEarnedPerGB = profitLossValue / totalGB;

      //----------------------------------------------------------

      // Setup output
      cout << fixed << setprecision(2) << showpoint <<  endl;

      // Display rate schedule/ output
      cout << left << setw(20) << "Customer ID:"     << right << setw(9) << customerID << endl;
      cout << left << setw(20) << "Customer Status:" << right << setw(9) << customerStatus << endl;
      if(customerStatus == 'r' || customerStatus == 'R') {
        cout   << left << setw(20) << "Discount (percent):" << "%" << setw(8) << right 
               << (RETIREE_DISCOUNT * 100) << endl;
      } else if(customerStatus == 's' || customerStatus == 'S') {
          cout << left << setw(20) << "Discount (percent):" << "%" << setw(8) << right 
               << (STUDENT_DISCOUNT * 100) << endl;
      } else {
          cout << left << setw(20) << "Discount (percent):" << "%" << setw(8)  << right 
               << 00.00 << endl;
      }
      cout << left << setw(20) << "Gigabytes Used:" << right << setw(9) << usedGB << endl;
      cout << left << setw(20) << "Amount:" << "$"  << right << setw(8) << amount << "\n" << endl;
      cout << endl;

      cin.ignore(); 

      // Input customer ID again
      getline(cin, customerID);

    } 

    // Display totals
    cout << left << setw(20) << "\nNormal Customers:"     << right << setw(11) << normalCustomers                   
         << endl;
    cout << left << setw(20) << "Retiree Customers:"    << right << setw(10) << retireeCustomers                  
         << endl;
    cout << left << setw(20) << "Student Customers:"    << right << setw(10) << studentCustomers                  
         << endl;
    cout << left << setw(20) << "Total GB Used:"        << right << setw(10) << totalGB 
         << endl;
    cout << left << setw(20) << "Total Amount Billed:"  << "$"   << right    << setw(9) << totalAmount        
         << endl;
    cout << left << setw(20) << "\nProfit/Loss Report:" 
         << endl;
    cout << left << setw(20) << "Avg Earned per GB:"    << "$"   << right    << setw(9) << averageEarnedPerGB 
         << endl;
    cout << left << setw(20) << "Cost per GB:"          << "$"   << right    << setw(9) << COST_PER_GB        
         << endl;
    cout << left << setw(20) << "Profit/Loss:"          << "$"   << right    << setw(9) << profitLossValue
         << endl;
    cout << "\nThis program has ended.\n";
    cout << endl;

  return 0;  
} 
