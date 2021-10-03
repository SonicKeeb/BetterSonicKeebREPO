#include <iostream>
using namespace std;

int main() {

   /* Type your code here. */
int inputNumber;
int num = 0;

cin >> inputNumber;

while (num != 1) {
if (num % 2 != 0) {
num = (inputNumber* 3) + 1;
} else {
num = inputNumber / 2;
}
}
cout << num << "\t";
   return 0;
}
