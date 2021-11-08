#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

  /* Type your code here. */

  cout << fixed << setprecision(2);

  int amount;
  int number;
  int min;
  int max;
  cin >> amount;
  vector<int> data(amount);

  for (int i = 1; i <= amount; i++) {
    cin >> number;
    data[i] = number;
  }

  cin >> min >> max;

  for (int j = 1; j <= amount; j++) {
    if (data[j] > max || data[j] < min) {
      continue;
    } else {
      cout << data[j] << ",";
    }
  }



  cout << endl;



  return 0;
}
