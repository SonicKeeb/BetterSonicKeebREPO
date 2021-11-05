#include <iostream>
#include <vector>
using namespace std;

int main() {

  /* Type your code here. */

  int input;
  cin >> input;
  int myArray[input];

  for (int i = 0; i < input; i++) {
    cin >> myArray[i];
  }

  int lastValue;
  cin >> lastValue;

  for (int i = 0; i < input; i++) {
    if (myArray[i] > lastValue) {
      continue;
    }
    cout << myArray[i] << ",";
  }

  cout << endl;

  return 0;
}

