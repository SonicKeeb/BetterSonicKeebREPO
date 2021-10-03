#include <iostream>
using namespace std;

int main() {

   /* Type your code here. */
int inputNumber;

cin >> inputNumber;

while (inputNumber!= 1) {
if (inputNumber % 2 != 0) {
inputNumber = (inputNumber * 3) + 1;
} else {
inputNumber = inputNumber / 2;
}
cout << inputNumber << "\t";
}
   return 0;
}
