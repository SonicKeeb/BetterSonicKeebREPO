#include <iostream>
using namespace std;

/* Type your code here. */

int CountEvens(int num1, int num2, int num3, int num4) {
  int result = 0;
  for (int i = 0; i < 4; i++) {
    if (i % 2 == 0) {
      result++;
    }
  }
  return result;
}

int main() {
  int result;
        
  result = CountEvens(3, 1, 4, 12);
  cout << "Total evens: " << result << endl; // Expected "Total evens: 2".

  return 0;
}
