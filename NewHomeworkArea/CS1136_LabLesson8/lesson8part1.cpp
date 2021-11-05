#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double readSeconds() {
  double seconds;
  cout << "Enter the time (in seconds)" << endl;
  while (cin >> seconds) {
    if (seconds < 0) {
      cout << "The time must be zero or more" << endl;
      cout << "Enter the time (in seconds)" << endl;
    } else if (seconds > 0) {
      cout << "Enter the time (in seconds)" << endl;
    } else {
      break;
    }
    return seconds;
  }
  return seconds;
}

double calculateEarthDistance(double seconds) {
  double g = 9.8 * (seconds * seconds);
  double earthDistance = 0.5 * g;
  return earthDistance;
  }

double calculateMoonDistance(double seconds) {
  double g = 1.6 * (seconds * seconds);
  double moonDistance = 0.5 * g;
  return moonDistance;
}

void displayResults(double seconds, double earthDistance, double moonDistance) {
  cout << "The object traveled " << earthDistance << " meters in " << seconds << " seconds on Earth" << endl;
  cout << "The object traveled " << moonDistance << " meters in " << seconds << " seconds on the Moon" << endl;
}


int main() { 
  
  cout << fixed << setprecision(4);
  cout << calculateEarthDistance(readSeconds());
  cout << calculateMoonDistance(readSeconds());

  return 0;
}
