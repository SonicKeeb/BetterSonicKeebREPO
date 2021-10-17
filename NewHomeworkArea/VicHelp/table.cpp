#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main() {

//Declaration of variables below
string evenCase, lessCase, greaterCase, charOutput; 
string errorMessageCombiner = "";
int inputSize, rowColumn;
int count = 0;
const int lowerBound = 3, upperBound = 15;

//Initial Prompt Statement and input
cout << "enter an odd size from 3 to 15: ";
cin >> inputSize;

/* 
  This loop works by whenever your inputted number is not 0, and if it is not inside the bounds of the problem (inclusively between 3 and 15) it will calculate
whether or not the value is even if when you divide by 2 it has a remainder of 0 or not, and if the value is less than the constant lower boundary or higher 
than the constant higher boundary.
*/
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
    if (inputSize >= lowerBound && inputSize <= upperBound) { // At this point in time it now checks if the value is WITHIN bounds
      if (inputSize % 2 == 0) { // And if it is even
        evenCase = "that's even!";
        errorMessageCombiner += evenCase; // errorMessageCombiner is an empty string that takes all the possible cases and combines them
       } else { // if the number is odd and within bounds it breaks out of the loop
         break;
       }
      }
      cout << "error: " << errorMessageCombiner << endl; // output prompt statment and error message as well as next input
      errorMessageCombiner = "";
      cout << "enter an odd size from 3 to 15: ";
      cin >> inputSize;
}
  if (inputSize >= lowerBound && inputSize <= upperBound) { // A check again once your input breaks out of the loop
    if (inputSize % 2 != 0) {
      rowColumn = inputSize; // rowColumn then saves the valid inputted value
      }
  }
  cout << endl;
// if Index is ever odd it is a * if not then it is a 0
for (int i = 1; i <= (rowColumn * rowColumn); i++) { // This for loop creates the table and its maximum length is determined by the size of the input SQUARED
  if (i % 2 == 0) {
    charOutput = "0 ";
  } else {
    charOutput = "* ";
  }
    count++; // Count keeps track of the iteration
    cout << charOutput;
    if (count % rowColumn == 0) { // if the count divided by the rowColumn is ever == 0 then it starts a new line that way the square is always equal on each side
      cout << endl;
    }
}
return 0;
}
