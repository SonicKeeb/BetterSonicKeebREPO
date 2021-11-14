#include <iostream>
#include <vector>
using namespace std;

void reverseArrayCopy(int original[], int originalSize, int newVersion[], int newVersionSize)
{

  for (int i=0; i < newVersionSize; i++)
  {
    cout << newVersion[i] << " ";

  }
}

/* Your function here */

int main() {
  const int ARRAY_SIZE = 5;
  int original[ARRAY_SIZE];
  const int NEW_SIZE = 5;
  int copy[NEW_SIZE];

  for ( int i=0; i<ARRAY_SIZE; i++) {
    std::cin >> original[i];
  }

  for (int i=0; i < ARRAY_SIZE; i++)
  {
    copy[i] = original[i];
    cout << copy[i];
  }


  reverseArrayCopy(original, ARRAY_SIZE, copy, NEW_SIZE);

  /* Your code here */

  return 0;
}
