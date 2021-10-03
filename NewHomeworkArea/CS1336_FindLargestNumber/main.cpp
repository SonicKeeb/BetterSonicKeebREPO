#include <iostream>
using namespace std;

int main() {

   /* Type your code here. */

int inputNum;
int num = 0;

cin >> inputNum;

while (inputNum >= 0) { 
if (inputNum > num) {
num = inputNum;
}
cin >> inputNum;
if (num < inputNum) {
num = inputNum;
}
}
cout << num << endl;
return 0;
 }
