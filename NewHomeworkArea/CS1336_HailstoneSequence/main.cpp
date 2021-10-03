#include <iostream>
using namespace std;

int main() {

   /* Type your code here. */

int inputNumber;
int count = 0;

cin >> inputNumber;

while (inputNumber!= 1) {
count++;
cout << inputNumber << "\t";
if (inputNumber / inputNumber == 1) {
inputNumber = inputNumber;
if (inputNumber % 2 != 0) {
inputNumber = (inputNumber * 3) + 1;
} else {
inputNumber = inputNumber / 2;
}
}
if (count % 10 == 0) {
cout << endl;
}
}
cout << inputNumber;
cout << endl;
   return 0;
}
