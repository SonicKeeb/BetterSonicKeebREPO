#include <iostream>
#include <string>
using namespace std;

bool check(string input) {
  bool tf;
  for (int i = 0; i < input.length(); i++) {
    if (input[i] != ',') {
      tf = false;
  } else {
    tf = true;
  }
  }
  return tf;
}

int main() {

  string input;
  string output, output2 = "";
  cout << "Enter input String:" << endl;

  while (getline(cin, input)) {
    if (input == "q") {
      break;
    }
    bool something = check(input);
    if (something == false) {
      cout << "no comma" << endl;
      getline(cin, input);
      } else {
        cout << "first and second" << endl;
        getline(cin, input);
      }
  } 

  return 0;
}
