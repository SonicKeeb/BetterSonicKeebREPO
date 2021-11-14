#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double interestRate() {
  cout << "Enter annual interest rate" << endl;
  double interest;
  while (cin >> interest) {
    if (interest <= 0) {
      cout << "The annual interest rate must be greater than zero" << endl;
      cout << "Enter annual interest rate" << endl;
    } else {
      return interest / 100;
    }
  }
}

int numberYears() {
  cout << "Enter number of years" << endl;
  int num;
  while (cin >> num) {
    if (num <= 0) {
      cout << "The number of years must be greater than zero" << endl;
      cout << "Enter number of years" << endl;
    } else {
      return num;
    }
  }
}

double futureValue(double presentValue, double interestRate, int months)

int main() {
  return 0;
}
