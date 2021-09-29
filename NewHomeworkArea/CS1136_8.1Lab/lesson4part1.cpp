//This program takes in a user's inputted mass in Kilograms and calculates
// the weight in Newton's of Earth, Moon, Venus.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main() {

//Declaration of variables and types

double mass;
const double earthAccel = 9.81;
const double moonAccel = 1.62;
const double venusAccel = 8.87;
double earthWeight;
double moonWeight;
double venusWeight; 

//Outputting prompt statements, followed up by user input

cout << "Enter the mass in kg" << endl;
cin >> mass;
cout << "The mass is " << fixed << setprecision(4) << mass << " kg" << endl;

//For if mass is every 0 or less

if (mass <= 0) {
	cout << "The mass must be greater than zero" << endl;
	return -1;
} else { 
	;
}

//Outputting location and weight prompt

cout << "Location" << setw(14) << "Weight (N)" << endl;

//Inititalization of variables and what they are to become

earthWeight = mass * earthAccel;
moonWeight = mass * moonAccel;
venusWeight = mass * venusAccel;

//Final output of prompt statements and calculations

cout << "Earth" <<  setw(17) << fixed << setprecision(4) << earthWeight << endl;
cout << "Moon" << setw(18) << fixed << setprecision(4) << moonWeight << endl;
cout << "Venus" << setw(17) << fixed << setprecision(4) << venusWeight << endl;

//Light or heavy
if (earthWeight < 5) {
	cout << "The object is light" << endl;
} else if (earthWeight >= 1500) {
	cout << "The object is heavy" << endl;
}

return 0;

}
