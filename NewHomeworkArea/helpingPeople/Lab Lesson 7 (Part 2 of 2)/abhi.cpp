#include <fstream>
#include<iomanip>
#include<iostream>
using namespace std;

int main() { //beginning of the main function

  cout << "Enter input file name" << endl;
  string filename;
  cin >> filename;

  double total = 0;
  double validCount = 0;
  double validSum = 0;
  double validAvg = 0;
  double outrange = 0;
  //===FIRST OPEN===
  ifstream inputFile;
  inputFile.open(filename);
  if (!inputFile.is_open()) {
    cout << "File " "\"" << filename << "\" could not be opened" << endl;
    exit(2);
  }

  ofstream outputFile;
  outputFile.open("invalid-values.txt");
  if (!outputFile.is_open()) {
    cerr << "Output file didn't open!" << endl;
    exit(1);
  }

  double num;

  // the file opened successfully
  while (inputFile >> num) {
    total++;
    // process the num value
    if (!(num < 0 || num > 105)){
      validSum += num;
      validCount++;
    } else {
      outrange++;
      continue;
    }
  }
  
  cout << total << endl;
  cout << validCount << endl;
  cout << outrange << endl;
  cout << validSum / validCount << endl;


/*
   validAvg = validSum/validCount;
   cout << "The count of valid data is " << validCount << endl;
   cout << "The sum of valid data is " << validSum << endl;
   cout << "The average of valid data is " << validAvg << endl;

   cout << "The count of out of range data is " << outrange << endl;
 */

return 0;
}
