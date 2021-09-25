#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main() {

double mass;
const double earthAccel = 9.81;
const double moonAccel = 1.62;
const double venusAccel = 8.87;
double earthWeight;
double moonWeight;
double venusWeight; 

cout << "Enter the mass in kg" << endl;
cin >> mass;
cout << endl;
cout << "The mass is " << mass << " kg" << endl;

cout << "Location" << setw(14) << "Weight (N)" << endl;

earthWeight = mass * earthAccel;
moonWeight = mass * moonAccel;
venusWeight = mass * venusAccel;

cout << "Earth" <<  setw(17) << fixed << setprecision(4) << earthWeight << endl;
cout << "Moon" << setw(18) << fixed << setprecision(4) << moonWeight << endl;
cout << "Venus" << setw(17) << fixed << setprecision(4) << venusWeight << endl;

return 0;

}
