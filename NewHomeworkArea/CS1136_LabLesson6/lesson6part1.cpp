#include <iostream>
#include <iomanip>
using namespace std;

int main() {

  unsigned int lowerValue, upperValue;
  int count = 0;

  cout << "Enter lower and upper values" << endl;
  
  while (true) {
    cin >> lowerValue >> upperValue;
    if (lowerValue < 32 || lowerValue >= 127 || upperValue < 32 || upperValue >= 127 || lowerValue > upperValue) {
      cout << "Values must be in range 32 to 126 inclusive" << endl;
      cout << "Enter lower and upper values" << endl;
    } else {
      break;
    }
  }
  
  cout << "Characters for ASCII values between " << lowerValue << " and " << upperValue << endl;
  
  cout << "----+----+----+----+" << endl;

  for (char i = lowerValue; i <= upperValue; i++) {
   cout << i;
   count++;
    if (count % 20 == 0 || count == (upperValue+1 - lowerValue)) {
      cout << endl;
    }
  }


  cout << "----+----+----+----+" << endl;

  return 0;
}
