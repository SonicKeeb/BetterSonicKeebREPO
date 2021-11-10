#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double futureValue() {
  cout << "Enter future value" << endl;
  double future;
  while (cin >> future) {
    if (future <= 0) {
      cout << "The future value must be greater than zero" << endl;
      cout << "Enter future value" << endl;
    } else {
      return future;
    }
  }
}

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

double presentValue(double futureValue, double interestRate, int numberYears) {
  return futureValue / pow(1 + interestRate, numberYears);
}

void display(double& presentValue, double& futureValue, double& interestRate, int& numberYears) {
  cout << "Present value: $" << fixed << setprecision(2) << presentValue << endl;
  cout << "Future value: $" << fixed << setprecision(2) << futureValue << endl;
  cout << "Annual interest rate: " << fixed << setprecision(3) << interestRate * 100 << '%' << endl;
  cout << "Years: " << numberYears << endl;
}

int main() {

  double future = futureValue();
  double interest = interestRate();
  int num = numberYears();
  double p = presentValue(future, interest, num);
  display(p, future, interest, num);

  return 0;
}
