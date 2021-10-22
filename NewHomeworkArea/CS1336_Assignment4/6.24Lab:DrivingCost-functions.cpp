#include <iostream>
#include <iomanip>               // For setprecision
using namespace std;

/* Define your function here */ 

double DrivingCost(double milesPerGallon, double dollarsPerGallon, double milesDriven) {
  double result = (milesDriven / milesPerGallon) * dollarsPerGallon;
  return result;
}

int main() {
  /* Type your code here */
 
  double milesPerGallon;
  double dollarsPerGallon;

  cin >> milesPerGallon >> dollarsPerGallon;
  
  double tenMiles = DrivingCost(milesPerGallon, dollarsPerGallon, 10);
  cout << fixed << setprecision(2) << tenMiles << " ";

  double fiftyMiles = DrivingCost(milesPerGallon, dollarsPerGallon, 50);
  cout << fixed << setprecision(2) << fiftyMiles << " ";

  double fourHundredMiles = DrivingCost(milesPerGallon, dollarsPerGallon, 400);
  cout << fixed << setprecision(2) << fourHundredMiles;

  cout << endl;

  return 0;
}
