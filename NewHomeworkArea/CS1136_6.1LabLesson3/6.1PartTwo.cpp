#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// This program takes in the input of any amount of dollars and then converts them into Yen, Euros, and Pesos

int main () {

// Delcaration of dollars and the constant Conversion values for the othe currencies

double dollars;
const double pesos = 19.73;
const double euros = 0.84;
const double yen = 113.27;

// Outputting Prompt for the read

cout << "Enter the amount in dollars" << endl;

// Inputting dollars

cin >> dollars;

// Outputting the first table string of the currency names
// Outputting the bottom row of the table with the converted currencies and set the decimal place to two places

cout << "        Dollars            Yen          Euros          Pesos" << endl;
cout << "" << setw(15) << fixed << setprecision(2) << dollars << "" << setw(15) << (dollars * yen) << "" << setw(15) << (euros * dollars) << "" << setw(15) << (pesos * dollars) << endl;

return 0;

}
