#include <iostream>
using namespace std;

int main() {

int decision;

cout << "Choose choice 1" << endl;
cout << "Enter with the number keys" << endl;
cout << "1." << endl;
cout << "2." << endl;
cin >> decision;

while (decision != 1) {
  cout << "Choose again" << endl;
  cin >> decision;
}

cout << "nice" << endl;

  return 0;
}
