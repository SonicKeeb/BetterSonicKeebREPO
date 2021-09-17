//
//  main.cpp
//  CS1336_Bonus_Balance
//
//  Created by Hamilton Ngo on 9/16/21.
//

/*

Now we want to convert the following pseudocode into a program

Display "Enter the starting balance"
Input balance
Display "Enter total deposits"
Input deposits
Display "Enter total withdrawals"
Input withdrawals
Store the value of balance plus deposits minus withdrawals in variable endingBalance
Display "The ending balance is " endingBalance

 */


// This progam calculates the user's ending balance
#include <iostream>
using namespace std;

int main()
{
   double balance, deposits, withdrawals, endingBalance;

   // Get the starting balance
   
   cout << "Enter the starting balance" << endl;
   cin >> balance;

   // Get the deposits
   
   cout << "Enter total deposits" << endl;
   cin >> deposits;

   // Get the withdrawals
   
   cout << "Enter total withdrawls" << endl;
    cin >> withdrawals;
   //**** add the read into variable withdrawals here

   // Calculate the ending balance
   endingBalance = balance + deposits - withdrawals;
   
   cout << "Your ending balance is $" << endingBalance << endl;

   
   return 0;
}
