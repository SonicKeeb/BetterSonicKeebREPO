#include <iostream>
using namespace std;

  int main() {

  string inputString;
  int length = inputString.length();
  string output;

  cin >> inputString;

  for (int i = 0; i < inputString.length(); i++) {
    if (i < 9) {
      output = "Valid";
    } else {
      output = "Invalid";
    }
  }
  cout << output << endl;
  return 0;
}
