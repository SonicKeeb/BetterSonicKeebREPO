//
//  main.cpp
//  Bonus_CS_1336_Multiple_Average
//
//  Created by Hamilton Ngo on 9/15/21.
//

// This program takes the input of 4 numbers and finds their product and average

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   int num1;
   int num2;
   int num3;
   int num4;
   int multiple;
   double multitpleLong; // I made a different multiple variable just to handle the double numbers and the last unsigned number
   int average;
   double averageDouble; // The same applies here as above
    
   cin >> num1;
   cin >> num2;
   cin >> num3;
   cin >> num4;

    multiple = ( num1 * num2 * num3 * num4);
    multitpleLong = ( long(num1) * long(num2) * long(num3) * long(num4) );
    
    /* In order to pass the final test where the output of the multiple is
     a long long number and a decimal, you have to have the numbers
     variable in the formulas all converted into a long number or else
     they won't add up together. After that you just output the variable which
     is already determined to be a double but if it is not then you can just convert it
     in the output statement. */
    
    average = ( (num1 + num2 + num3 + num4) / 4 );
    
    averageDouble = ( (double(num1) + double(num2) + double(num3) + double(num4)) / 4.0 );
    
    
    
   cout << multiple << " ";
   cout << average<< endl;

    // ^ Outputs the top row of integer numbers that are NON-Truncated
    
    cout << fixed << setprecision(3) <<  multitpleLong << " ";
    cout << fixed << setprecision(3) << averageDouble  << endl;
    
    // ^ Handles double's and the unsigned value
    
   return 0;
}
