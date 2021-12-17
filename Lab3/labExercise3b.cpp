/*
 * CLASS ID: CIS/CSC-5-48639/48683
 *
 * STUDENT:    Luis Mejia
 * ASSIGNMENT: Lab Exercise 3b
 * DUE DATE:   09/14/2021
 *
 */

/* Place Library References Here */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
 * Main Program
 * Description:
 *   This program will read in the name, the price and the quantity of an
 *   item for sale, then output the item name, unit price, quantity purchased
 *   and total price.
 */
int main()
{
   string itemName;     // name of the item
   int    quantity;     // number of items purchased
   float  itemPrice;    // price of each item
   float  totalBill;    // total bill.

   // >>> In the code below, replace the // ??? with the requested statements 

   // 1. Set the numeric output precision to two decimal places
   //    (even if they are .00)   
      cout << left << fixed << setprecision(2) << endl;

   // 2. Write statement(s) to request and input the name of an item to purchase
   // (the item name may contain spaces; see hint in assignment)
      cout << "Enter an item you wish to purchase." << endl;
      getline(cin, itemName);
    
   // 3. Write statement(s) to request and input the number of items to buy
      cout << "How many items do you wish to purchase?" << endl;
      cin >> quantity;

   // 4. Write statement(s) to request and input the price of each item
      cout << "How much does the item cost?" << endl;
      cin >> itemPrice; 

   // 5. Write statement(s) to calculate the total amount of the bill
      totalBill = quantity * itemPrice;

   // 6. Write statements to output the item name, unit price, quantity
   //    purchased and total amount of the bill, one item per line.
      cout << "\n" << setw(14) << "Item Name:" << itemName << "\n" << endl;
      cout << setw(14) << "Unit price:  $" << right << setw(9) << itemPrice << endl;
      cout << left << setw(14) << "Quantity:" << right << setw(9) << quantity << endl;
      cout << setw(14) << "Total Price: $" << right << setw(9) << totalBill << endl;
      
     
   return 0;
}

