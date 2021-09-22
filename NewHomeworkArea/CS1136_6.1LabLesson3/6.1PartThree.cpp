#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/*
This program reads in a companies name and calculaties the stocks
total purchase price and selling prie based on the price of 
purchase and sale and amount of stocks owned
*/

int main() {

// Declaration of all Variables and their types

string companyName;
int stocks;
double purchasePrice;
double salePrice;
const double commission = 0.035;
double costOfStock;
double totalCost;
double incomeFromStock;
double totalIncome;

// Ouputting the promps and inputting data of company name, stocks, purchase & selling price

cout << "Enter the name of the company" << endl;
getline(cin, companyName);

cout << "Enter shares of stock" << endl;
cin >> stocks;

cout << "Enter purchase price" << endl;
cin >> purchasePrice;

cout << "Enter sale price" << endl;
cin >> salePrice;

cout << endl;

// Intializing variables

costOfStock = stocks * purchasePrice; 
totalCost = (commission * costOfStock) + costOfStock;
incomeFromStock = salePrice * stocks;
totalIncome = incomeFromStock - (commission * incomeFromStock);

// Outputting the previous inputs and categorizing them as well as performing small calculations

cout << "Company: " << companyName << endl;
cout << "Shares: " << stocks << endl;
cout << endl;

cout << "Purchase/share: $" << fixed << setprecision(2) << purchasePrice << endl;
cout << "Cost of stock: $" << fixed << setprecision(2) << costOfStock << endl;
cout << "Cost of commission: $" << fixed << setprecision(2) <<  (commission * costOfStock) << endl;
cout << "Total cost: $" << fixed << setprecision(2) << totalCost << endl;
cout << endl;

cout << "Sale/share: $" << fixed << setprecision(2) <<  salePrice << endl;
cout << "Income from stock: $" << fixed << setprecision(2) << incomeFromStock << endl;
cout << "Cost of commission: $" << fixed << setprecision(2) << (commission * incomeFromStock) << endl;
cout << "Total income: $" << fixed << setprecision(2) << totalIncome << endl;
cout << endl;

cout << "Gain or loss: $" << totalIncome - totalCost << endl;

return 0;

}
