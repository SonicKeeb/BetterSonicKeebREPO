#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

  /* Type your code here. */

  cout << fixed << setprecision(2);
  
  int amount;
  double number;
  cin >> amount;
  vector<double> data(amount);

  for (int i = 1; i <= amount; i++) {
    cin >> number;
    data[i] = number;
  }
  
  double max = data[0];
  
  for (int j = 1; j <= amount; j++) {
    if (data[j] > max) {
      max = data[j];
    }
  }

  for (int j = 1; j <= amount; j++) {
    cout << data[j] / max << " ";
  }
  

  
  cout << endl;

  
  
  return 0;
}

