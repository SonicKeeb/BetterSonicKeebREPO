//
//  main.cpp
//  BonusCS1336_EmployeePaidEveryYear
//
//  Created by Hamilton Ngo on 9/17/21.
//

#include <iostream>

int main() {
    
    double grossIncome = 2000.00;
    double netIncome;
    int payPeriods = 12;
    const double tax = 0.062;
    double annualGrossIncome;
    double annualNetIncome;
    
    std::cout << grossIncome << std::endl;
    
    netIncome = grossIncome * tax;
    
    std::cout << netIncome << std::endl;
    
    annualGrossIncome = (payPeriods * grossIncome) - (payPeriods * grossIncome * tax);
    
    std::cout << annualGrossIncome << std::endl;
    
    annualNetIncome = grossIncome * payPeriods;
    
    std::cout << annualNetIncome << std::endl;
    
}
