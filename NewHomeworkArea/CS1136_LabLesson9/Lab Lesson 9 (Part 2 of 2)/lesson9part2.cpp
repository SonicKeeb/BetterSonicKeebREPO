#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

unsigned int readInput(ifstream& inputFile, double& present, double& interest, int& months) {
  inputFile >> present >> interest >> months;
  interest /= 100;
  if (inputFile.eof()) { 
    return 0; 
  }
  if (!(present > 0.0 && interest > 0.0 && months > 0)) {
    return 2;
  }
  return 1;
}

double futureValue(double present, double interest, int months) {
  double future = present * pow((1 + interest), months); //
  return future;
}

void display(ofstream& outputFile, double present, double interest, int months, double future){
  outputFile << fixed << setprecision(2) << future << "\t" << present;
  outputFile << fixed << setprecision(3) << "\t" << interest * 100 << "\t" << months << std::endl;
}

int main() {
  double present = 0.0, interest = 0.0, future = 0.0;
  int months = 0;
  ifstream inputFile;
  ofstream outputFile;
  string fileName;

  cout << "Enter input file name" << endl;
  cin >> fileName;

  outputFile.open("output.xls");
  inputFile.open(fileName);

  if (!inputFile.is_open()) {
    cout << "File \"" << fileName << "\" could not be opened" << endl;
    return -1; 
  }
  if (!outputFile.is_open()) {
    cout << "File \"output.xls\" could not be opened" << endl;
    return -1; 
  }

  outputFile << "Future Value\tPresent Value\tMonthly Interest\tMonths" << endl;

  unsigned int returnType = readInput(inputFile, present, interest, months); 
  while (returnType != 0) {
    if (returnType == 1) { 
      future = futureValue(present, interest, months);
      display(outputFile, present, interest, months, future);
    }
    if (returnType == 2) { 
      cout << fixed << setprecision(2) << present << " " << setprecision(3) << interest * 100 << " " << months << endl;
      cout << "One or more of the above values are not greater than zero" << endl;
    }
    returnType = readInput(inputFile, present, interest, months);
  }

  inputFile.close();
  outputFile.close();

  return 0;
}
