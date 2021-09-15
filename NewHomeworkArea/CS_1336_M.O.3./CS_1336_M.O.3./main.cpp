//
//  main.cpp
//  CS_1336_M.O.3.
//
//  Created by Hamilton Ngo on 9/15/21.
//

// Write a program that takes in three integers as inputs and outputs the largest value.

// Ex: If the input is:
// 1 2 3
// The output is 3

#include <iostream>
using namespace std;

int main() {
    int val1;
    int val2;
    int val3;
    int max;

    /* Type your code here */

    std::cin >> val1;
    std::cin >> val2;
    std::cin >> val3;
    
    
    /* The next set of code are if else statements to check whether or not the 3 inputed numbers are greater than each other ( it checks whether or not one number is greater than the other two ) and then it outputs the greatest number of the 3 */
    
    if ( (val1 > val2) && (val1 > val3) ) {
        max = val1;
        std::cout << max << std::endl;
    } else if ( (val2 > val1) && (val2 > val3) ) {
        max = val2;
        std::cout << max << std::endl;
    } else {
        max = val3;
        std::cout << max << std::endl;
    }
    
 
    
    return 0;
}
