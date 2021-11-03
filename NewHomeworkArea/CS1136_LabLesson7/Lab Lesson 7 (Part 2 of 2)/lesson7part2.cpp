#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

int main() {

  string fileName;
  double totalCount, invalidCount, validCount = 0;
  double nums, sum;

  cout << "Enter input file name" << endl;
  cin >> fileName;

  ifstream inputFile;
  inputFile.open(fileName);
  if (!inputFile.is_open()) {
    cout << "File " "\"" << fileName << "\" could not be opened" << endl;
    exit(2);
  }

  ofstream outputFile;
  outputFile.open("invalid-values.txt");
  if (!outputFile.is_open()) {
    cerr << "Output file didn't open!" << endl;
    exit(1);
  }

  while (inputFile >> nums) {
    totalCount = totalCount +1;
    if (!(nums < 0 || nums > 105)) {
      sum += nums;
      validCount = validCount + 1;
    } else {
      outputFile << fixed << setprecision(5) << nums << endl;
      invalidCount = invalidCount + 1;
      continue;
    }
    if (inputFile.fail()) { // If the file fails and it is the end of the file exit
      if (inputFile.eof()) {
        outputFile << "End of the file!" << endl;
      } else {
        outputFile << "Unkown Error!" << endl;
      }
      exit(1);
    }
  }

  if (inputFile.is_open()) {
    cout << "Reading from file " << "\"" << fileName << "\"" << endl;
  }

  cout << "Total values: " << floor(totalCount) << endl;
  cout << "Invalid values: " << floor(invalidCount) << endl;
  cout << "Valid values: " << floor(validCount) << endl;
  if (validCount == 0) {
    cout << "An average cannot be calculated" << endl;
  } else {
    cout << "Average of valid values: " << fixed << setprecision(4) << double(sum / int(validCount)) << endl;
  }

  if (outputFile.fail()) {
    outputFile << "Writing to output file failed!" << endl;
    exit(1);
  }

  inputFile.close();
  outputFile.close();

  return 0;
}
