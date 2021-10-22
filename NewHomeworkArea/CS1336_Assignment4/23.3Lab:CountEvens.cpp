#include <iostream>
using namespace std;

/* Type your code here. */

int CountEvens(int num1, int num2, int num3, int num4) {
  int result = 0;
  if (num1 % 2 == 0) {
    result++;
  } if (num2 % 2 == 0) {
    result++;
  } if (num3 % 2 == 0) {
    result++;
  } if (num4 % 2 == 0) {
    result++;
  } else {
    ;
  }
  return result;
}

int main() {
  int result, num1, num2, num3, num4;

  cin >> num1 >> num2 >> num3 >> num4;

  result = CountEvens(num1, num2, num3, num4);
  cout << "Total evens: " << result << endl; // Expected "Total evens: 2".

  return 0;
}
