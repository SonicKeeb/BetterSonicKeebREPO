#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
  double nextIn;
  int vecSize;
  double max = 0;
  double normal;
  vector <double> myVec;

  cout << fixed << setprecision(2);
  cin >> vecSize; 
  for (int i=0; i < vecSize; i++)
  {
    cin >> nextIn;
    myVec.push_back(nextIn);
    if (nextIn > max)
    {
      max = nextIn;
    }
  }

  for (int i=0; i < vecSize; i++)
  {
    normal = myVec.at(i) / max;
    cout << normal << ' ';
  }

  cout << '\n';


  return 0;
}
