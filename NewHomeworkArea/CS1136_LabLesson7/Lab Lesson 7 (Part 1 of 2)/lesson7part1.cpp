#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <filesystem>
#include <type_traits>
using namespace std;

string starOutput(int stars) {
  char output = '*';
  string emptyString = "";
  for (int i = 0; i < stars; i++) {
    emptyString += output;
  }
  return emptyString;
}

int main() {

  cout << "Enter input file name" << endl;

  string fileName;
  cin >> fileName;

  ifstream inputFile;
  inputFile.open(fileName);
  if (!inputFile.is_open()) {
    cout << "File " "\"" << fileName << "\" could not be opened" << endl;
    exit(2);
  }

  ofstream outputFile;
  outputFile.open("saleschart.txt");
  if (!outputFile.is_open()) {
    cerr << "Output file didn't open!" << endl;
    exit(1);
  }

  unsigned int storeNumber;
  long long int salesValue;

  outputFile << "SALES BAR CHART" << endl;
  outputFile << "(Each * equals 5,000 dollars)" << endl;

  while (inputFile >> storeNumber >> salesValue) {
    if (salesValue < 0) {
      cout << "The sales value for store " << storeNumber << " is negative" << endl;
      continue;
    }
    if (storeNumber < 1 || storeNumber > 99) {
      cout << "The store number " << storeNumber << " is not valid" << endl;
      continue;
    } 
    int stars = salesValue / 5000;
    outputFile << "Store " << setw(2) << storeNumber << ": " << starOutput(stars) << endl;
  }  

  if (outputFile.fail()) {
    outputFile << "Writing to output file failed!" << endl;
    exit(1);
  }

  inputFile.close();
  outputFile.close();

  return 0;
}
