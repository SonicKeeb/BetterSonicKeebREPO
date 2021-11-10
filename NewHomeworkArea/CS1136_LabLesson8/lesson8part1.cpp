#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double readSeconds() {
  double seconds;
  cout << "Enter the time (in seconds)" << endl;
  while (cin >> seconds) {
    if (seconds == 0) {
      break;
    } else if (seconds < 0) {
      cout << "The time must be zero or more" << endl;
      cout << "Enter the time (in seconds)" << endl;
    } else {
      return seconds;
    }
  }
 return seconds;
}

double calculateEarthDistance(double seconds) {
  double earthDistance = 0.5 * 9.8 * pow(seconds, 2);
  return earthDistance;
  }

double calculateMoonDistance(double seconds) {
  double moonDistance = 0.5 * 1.6 * pow(seconds, 2);
  return moonDistance;
}

void displayResults(double seconds, double earthDistance, double moonDistance) {
  cout << "The object traveled " << fixed << setprecision(4) << earthDistance << " meters in " << fixed << setprecision(2) << seconds << " seconds on Earth" << endl;
  cout << "The object traveled " << fixed << setprecision(4) <<  moonDistance << " meters in " << fixed << setprecision(2) << seconds << " seconds on the Moon" << endl;
}


int main() { 
  
 while (double seconds = readSeconds()) {
  if (seconds > 0) {
    displayResults(seconds, calculateEarthDistance(seconds), calculateMoonDistance(seconds));
  }
 }
  return 0;
}
