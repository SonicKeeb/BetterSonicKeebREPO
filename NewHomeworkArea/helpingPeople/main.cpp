#include <iostream>
using namespace std;

int main() {
  bool goodPassword;
  string checkStr;

  cin >> checkStr;

  /* Your code goes here */
  for (int i = 0; i < checkStr.length(); i++) {
    if (i < 8) {
      goodPassword = true;
    } else {
      goodPassword = false;
    }
  }

  if (goodPassword) {
    cout << "Valid" << endl;
  }
  else {
    cout << "Invalid" << endl;
  }

  return 0;
}
