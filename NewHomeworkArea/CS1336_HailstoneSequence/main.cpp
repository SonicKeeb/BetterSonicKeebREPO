#include <iostream>
#define RED "\033[31m"
#define GREEN "\033[32m"
using namespace std;

int main() {

   /* Type your code here. */

long long int inputNumber;
long long int count = 0;

cin >> inputNumber;

while (inputNumber!= 1) {
count++;
if (inputNumber % 2 != 0) {
cout << RED << inputNumber << "\t";
} else {
cout << GREEN << inputNumber << "\t";
}
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
cout << RED << inputNumber;
cout << endl;
   return 0;
}
