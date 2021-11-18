#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

  unsigned int lowerBound, upperBound;
  char c;

  cout << "Enter lower and upper values" << endl;
  cin >> lowerBound;
  cin >> upperBound;

  while (lowerBound < 32 || lowerBound >= 127 || upperBound > 126 || upperBound < 32 || upperBound < lowerBound) {
    cout << "Values must be in range 32 to 126 inclusive" << endl;
    cout << "Enter lower and upper values" << endl;
    cin >> lowerBound;
    cin >> upperBound;
  }

  cout << "Characters for ASCII values between " << lowerBound << " and " << upperBound << endl;
  cout << "----+----+----+----+" << endl;

  for (int i = lowerBound; i <= upperBound; ++i) {

    cout << c;
    c += 1;

  }

  cout << endl << "----+----+----+----+" << endl;

  return 0;
}
