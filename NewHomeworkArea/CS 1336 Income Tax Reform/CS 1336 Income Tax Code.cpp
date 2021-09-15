//
//  CS 1336 Income Tax Code.cpp
//  CS 1336 Income Tax Reform
//
//  Created by Hamilton Ngo on 9/15/21.
//

#include "CS 1336 Income Tax Code.hpp"
#include <iostream>
#include <cmath>
using namespace std;

int main() {

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
   
    cin >> wages >> interest >> unemployment >> status >> taxes;
    agi = wages + interest + unemployment;
   
    cout << "AGI: $" << agi << endl;
   
   if (agi > 120000){
      cout << "Error: Income too high to use this form" << endl;
      return - 1;
   }
   
   if (status == 1 ||(status != 1 && status != 2)){
      deduction = deductionSingle;
   } else{
      deduction = deductionMarried;
   }
   
   cout << "Deduction: $" << deduction << endl;
   
   income = agi - deduction;
   
   if (income < 0){
      income = 0;
   }
   
   cout << "Taxable income: $" << income << endl;
   
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
   
   cout << "Federal tax: $" << federalTax << endl;
   
   taxDue = federalTax - taxes;
   
   if (taxDue < 0){
      cout << "Tax refund: $" << abs(taxDue) << endl;
   }else {
      cout << "Taxes Owed: $" << federalTax << endl;
   }
   
   return 0;
}
