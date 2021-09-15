//
//  CS 1336 Income Tax Code.cpp
//  CS 1336 Income Tax Reform
//
//  Created by Hamilton Ngo on 9/15/21.
//

#include "CS 1336 Income Tax Code.hpp"
#include <iostream>
#include <cmath>

int main() {

    // Setting constants for the married and single status expense and declaring all other variables
    
    const int deductionMarried = 24000;
    const int deductionSingle = 12000;
    int wages;
    int interest;
    int unemployment;
    int status;
    int taxes;
    int agi;
    int deduction;
    int income;
    int taxDue;
    double federalTax;
   
    // CIN
    
    std::cin >> wages >> interest >> unemployment >> status >> taxes;
    
    // settings variable agi = to what it is / calculation
    
    agi = wages + interest + unemployment;
   
    std::cout << "AGI: $" << agi << endl;
   
    // Predefining at the start of the code that if agi is ever > 120000 it'll output the error message and stop outputting anything else after that because of return -1
    
   if (agi > 120000){
      std::cout << "Error: Income too high to use this form" << std::endl;
      return - 1;
   }
   
    /* Declaring deduction rates based on whether or not the status is a single or married, if the status is 1 then we know to use the constant of single which is 12000 and if it is anything else but 1 and 2 it'll always use the constant of married */
    
   if (status == 1 ||(status != 1 && status != 2)){
      deduction = deductionSingle;
   } else {
      deduction = deductionMarried;
   }
   
   std::cout << "Deduction: $" << deduction << std::endl;
   
    // Declaring the computation and defining income
    
   income = agi - deduction;
   
    // Setting income to always output 0 if income is ever not greater than 0
    
   if (income < 0){
      income = 0;
   }
   
   std::cout << "Taxable income: $" << income << std::endl;
   
    // The following next lines of code calculate the rate of the Federal tax: depending on the parameters of income and status
    
   if (deduction == deductionMarried){
      if (income > 80000){
         federalTax = round(9200 + 0.22 * (abs(80000 - income)));
      } else if (income > 20001){
         federalTax = round(2000 + 0.12 * (abs(20000 - income)));
      } else {
         federalTax = round(0.1 * income);
      }
    } else{
      if (income > 85000){
         federalTax = round(14500 + 0.24 * (abs(85000 - income)));
      } else if (income > 40000){
         federalTax = round(4600 + 0.22 * (abs(40000 - income)));
      } else if (income > 10000 && income <= 40000) {
          federalTax = round(1000 + 0.12 * (abs(10000 - income)));
      } else {
         federalTax = round(0.1 * income);
      }
   }
   
   std::cout << "Federal tax: $" << federalTax << std::endl;
   
    // Declaring taxDue as being federaltax - taxes
    
   taxDue = federalTax - taxes;
   
    // If tax is ever less than 0 then we return the same value because that is a refund, if not then it is owed and we output the federal tax
    
    if (taxDue < 0){
      std::cout << "Tax refund: $" << abs(taxDue) << std::endl;
       } else {
      std::cout << "Taxes Owed: $" << federalTax << std::endl;
   }
   
   return 0;
}
