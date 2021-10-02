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
cout << secondString;
}

cout << endl;

for (int i = 0; i < inputString.size(); i++) {
originalString = (char) (inputString.at(i));
cout << originalString;
}

cout << endl;

if (originalString == secondString) {
cout << "yes " << endl;
} else {
cout << "no " << endl;
}

/* if (originalString != secondString) {
cout << "not a palindrome:  " << inputString << endl;
} else { 
cout << "palindrome: " << inputString << endl;
} */
return 0;
}


