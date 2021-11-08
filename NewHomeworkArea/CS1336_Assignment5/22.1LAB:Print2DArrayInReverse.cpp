#include <iostream>
using namespace std;

int main() {

  /* Type your code here. */

  int array[12];
  int input;
  int count = 0;

  for (int i = 0; i < 12; i++) {
    cin >> input;
    array[i] = input;
  }

  int size = sizeof(array)/sizeof(array[0]);

  for (int j = size-1; j >= 0; j--) {
    count++;
    cout << array[j] << " ";
    if (count % 3 == 0) {
      cout << endl;
    }
  }

  return 0;
}
