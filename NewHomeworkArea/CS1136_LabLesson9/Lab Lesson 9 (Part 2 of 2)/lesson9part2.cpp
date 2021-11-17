#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

unsigned int read(unsigned int& rValue, istream& inputFile, double& presentValue, double& interestRate, int& months) {
  while (inputFile >> presentValue >> interestRate >> months) {
    if (presentValue <= 0 || interestRate <= 0 || months <= 0) {
      cout << fixed << setprecision(2) << presentValue << " " << fixed << setprecision(3) << interestRate << " " << months << endl;
      cout << "One or more of the above values are not greater than zero" << endl;
      rValue = 2;
    } else {
      interestRate = interestRate / 100;
      rValue = 1;
    }
  }
  return rValue;
}

double futureValue(double presentValue, double interestRate, int months) {
  double f = presentValue * pow((1 + interestRate), months);
  return f;
}

void output(ostream& outputFile, istream& inputFile, unsigned int rValue, double presentValue, double interestRate, int months) {
  outputFile << "Future Value\tPresent Value\tMonthly Interest\tMonths" << endl;
  if (rValue != 1) {
    return;
  } else {
    outputFile << fixed << setprecision(2) << futureValue(presentValue, interestRate, months);
    outputFile << "\t" << fixed << setprecision(2) << presentValue << "\t" << fixed << setprecision(3) << interestRate * 100 << "\t" << months << endl;
  }
}



int main() {
  double presentValue, interestRate;
  int months;
  unsigned int rValue;
  string fileName;

  cout << fixed << setprecision(2);
  cout << "Enter input file name" << endl;
  cin >> fileName;

  ifstream inputFile;
  inputFile.open(fileName);
  if (!inputFile.is_open()) {
    cout << "File " "\"" << fileName << "\" could not be opened" << endl;
    exit(2);
  }

  ofstream outputFile;
  outputFile.open("output.xls");
  if (!outputFile.is_open()) {
    cerr << "Output file didn't open!" << endl;
    exit(1);
  }

  while (inputFile) {
    read(rValue, inputFile, presentValue, interestRate, months);
    futureValue(presentValue, interestRate, months);
    output(outputFile, inputFile, rValue, presentValue, interestRate, months);
  }

  return 0;
}
