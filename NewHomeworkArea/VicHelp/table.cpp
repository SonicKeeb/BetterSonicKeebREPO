#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main() {

string evenCase, lessCase, greaterCase, charOutput; 
string errorMessageCombiner = "";
int inputSize, rowColumn;
int count = 0;
const int lowerBound = 3, upperBound = 15;

cout << "enter an odd size from 3 to 15: ";
cin >> inputSize;

while (inputSize != 0) {
  if (inputSize < lowerBound || inputSize > upperBound) {
    if (inputSize % 2 == 0) {
      evenCase = "that's even! ";
      errorMessageCombiner += evenCase;
    }
    if (inputSize < lowerBound) {
      lessCase = "that's less than the min!";
      errorMessageCombiner += lessCase;
    }
      if (inputSize > upperBound) {
        greaterCase = "that's greater than the max!";
        errorMessageCombiner += greaterCase;
      }
    }
    if (inputSize >= lowerBound && inputSize <= upperBound) {
      if (inputSize % 2 == 0) {
        evenCase = "that's even!";
        errorMessageCombiner += evenCase;
       } else {
         break;
       }
      }
      cout << "error: " << errorMessageCombiner << endl;
      errorMessageCombiner = "";
      cout << "enter an odd size from 3 to 15: ";
      cin >> inputSize;
}
  if (inputSize >= lowerBound && inputSize <= upperBound) {
    if (inputSize % 2 != 0) {
      rowColumn = inputSize;
      }
  }
  cout << endl;
// if Index is ever odd it is a * if not then it is a 0
for (int i = 1; i <= (rowColumn * rowColumn); i++) {
  if (i % 2 == 0) {
    charOutput = "0 ";
  } else {
    charOutput = "* ";
  }
    count++;
    cout << charOutput;
    if (count % rowColumn == 0) {
      cout << endl;
    }
}
return 0;
}
