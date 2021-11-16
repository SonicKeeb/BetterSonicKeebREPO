#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> myVect{-1, 2, 4, 24, 36, -10};
  for ( int i=0; i<myVect.size(); i++) {
    if ( myVect.at(i) < 0) {
      myVect.push_back(myVect.at(i));
    }
  }
  return 0;
}
