#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {

  /* Type your code here. */

  int inputAmount;
  cin >> inputAmount;
  int myArray[inputAmount];

  cout << fixed << setprecision(2);

  for (int i = 0; i < inputAmount; i++) {
    cin >> myArray[i];
  }

  for (int i = 0; i < inputAmount; i++) {
    cout << myArray[i] << ' ';
  }
  return 0;
}

