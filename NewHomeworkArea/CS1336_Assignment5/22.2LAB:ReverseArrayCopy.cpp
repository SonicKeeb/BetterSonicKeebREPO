#include <iostream>
using namespace std;

/* Your function here */

void reverseArrayCopy(int original[], int originalSize, int newVersion[], int newVersionSize) {
  //In slides at the end, loop through array and input each element into new array
  // so long as the new array is as large as the original you have room to input more

  if (newVersionSize < originalSize) {
    return;
  }
  for (int i = 0; i < originalSize; i++){
    newVersion[i] = original[originalSize-1-i];
  }
}

int main() {
  const int ARRAY_SIZE = 5;
  int original[ARRAY_SIZE];

  for (int i = 0; i < ARRAY_SIZE; i++) {
    cin >> original[i];
  }

  /* Your code here */

  int size = sizeof(original)/sizeof(original[0]);

  int newVersion[ARRAY_SIZE];

  for (int i = size-1; i >= 0; i--) {
    newVersion[i] = original[i];
    cout << newVersion[i] << " ";
  }

  cout << endl;

  reverseArrayCopy(original, ARRAY_SIZE, newVersion, ARRAY_SIZE);


  return 0;
}

