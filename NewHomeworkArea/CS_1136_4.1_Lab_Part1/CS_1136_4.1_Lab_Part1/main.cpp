//
//  main.cpp
//  CS_1136_4.1_Lab_Part1
//
//  Created by Hamilton Ngo on 9/15/21.
//

/* This Program takes the purchase price of an object and calculates the total sales tax of said object, the totalSalesTax will change depending on whatever the purchasePrice, countySalesTaxRate, and stateSalesTaxRate are. */

#include <iostream>

int main() {
    
// This section declares all the variable and variable types
    
    int purchasePrice = 95;
    double stateSalesTaxRate = 0.06;
    double countySalesTaxRate = 0.02;
    double totalSalesTax = purchasePrice * (stateSalesTaxRate + countySalesTaxRate);
    
/* Line 24 does the final calculation by taking the state and county tax rates and adds them together to then be multiplied into the purchase price which gives us the totalSalesTax */
    
    std::cout << totalSalesTax << std::endl;
    
// Line 28 outputs the result of line 24
    
    return 0;
    
}
