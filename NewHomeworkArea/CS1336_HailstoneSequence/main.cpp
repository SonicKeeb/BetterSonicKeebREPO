#include <iostream>
#define RED "\033[31m"
#define GREEN "\033[32m"
using namespace std;

int main() {

   /* Type your code here. */

int inputNumber;
int count = 0;

cin >> inputNumber;

if (!(inputNumber >= '0' && inputNumber <= '9')){
         std::cout << "Not a number please input a number, hit ./a.out and ENTER and type another input" << std::endl;
	return -1;
      }

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
