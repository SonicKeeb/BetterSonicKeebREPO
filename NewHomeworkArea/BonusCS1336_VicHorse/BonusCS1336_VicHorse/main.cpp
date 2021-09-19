//
//  main.cpp
//  BonusCS1336_VicHorse
//
//  Created by Hamilton Ngo on 9/18/21.
//

/*
  Description: This program is used to display the daily costings of the probiotic supplement required by the horses.
  Author: <Your name>
  Section: <Insert section>
  Date: <Insert Date>
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double pricePerPound;
    double costPerDay;
    double costPerDay10;
    double costPerDay20;
    double TotalPrice10;
    double TotalPrice20;
    
    cout << "Enter price per lb: $";
    cin >> pricePerPound;
    
    TotalPrice10 = pricePerPound * 10;
    TotalPrice20 = pricePerPound * 20;
    
    costPerDay = (pricePerPound * 1.00) / 16.00;
    costPerDay10 = (((TotalPrice10) - (TotalPrice10 * 0.10)) / 160);
    costPerDay20 = (((TotalPrice20) - (TotalPrice20 * 0.15)) / 320);
    
    cout << setprecision(2) << fixed << pricePerPound << endl;
    cout << endl;
    
    cout << "Buying option" << setw(16) << "1 lb" << setw(6) << "10 lb" << setw(6) << "20 lb" << endl;
    
    cout << endl;
    
    cout << "Cost per day ($)" << setw(13) << costPerDay << setw(6) << costPerDay10 << setw(6) << costPerDay20 << endl;
    
    return 0;
}
