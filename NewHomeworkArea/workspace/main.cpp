// This program takes in an input in fahrenheit and converts it into celsius
// Dillan Nguyen
// COSC 1436.900
// 1/28/2022
#include <iostream>
using namespace std; // namespace std makes it so that I don't have to use std:: over and over again

int main() {

int fahrenheit, celsius; // Declaration of integer variables

cout << "Enter a temperature in fahrenheit "; // Output of prompt statement of the program
cin >> fahrenheit; // Takes the input of the integer variable Fahrenheit
celsius = (fahrenheit - 32) / 1.8; // Initializing celsius as the formula for making fahrenheit turn into celsius
cout << fahrenheit << " degrees Fahrenheit = " << celsius << " degrees Celsius" << endl; // outputting computation
// and output statement

  return 0;
}
