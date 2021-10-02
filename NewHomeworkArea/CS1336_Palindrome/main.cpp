#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {

   /* Type your code here. */

string inputString;
string secondString;
string originalString;

getline(cin, inputString);

for (int i = inputString.size()-1; i >= 0; i--) {
secondString = (char) (inputString.at(i));
}

for (int i = 0; i < inputString.size(); i++) {
originalString = (char) (inputString.at(i));
}

if (originalString == secondString) {
cout << "palindrome: " << inputString << endl;
} else {
cout << "not a palindrome: " << inputString << endl;
}

return 0;
}


