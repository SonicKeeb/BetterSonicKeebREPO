#include <iostream>
using namespace std;

/* Define your function here */ 

void SwapValues(int& userVal1, int& userVal2, int& userVal3, int& userVal4) {

  int empty1, empty2;
  
  empty1 = userVal1;
  userVal1 = userVal2;
  userVal2 = empty1;

  empty2 = userVal3;
  userVal3 = userVal4;
  userVal4 = empty2;

}

int main() {
     /* Type your code here. Your code must call the function.  */

  int userVal1, userVal2, userVal3, userVal4;

  cin >> userVal1 >> userVal2 >> userVal3 >> userVal4;

  SwapValues(userVal1, userVal2, userVal3, userVal4);

  cout << userVal1 << " " << userVal2 << " " << userVal3 << " " << userVal4 << endl;

        return 0;
}
