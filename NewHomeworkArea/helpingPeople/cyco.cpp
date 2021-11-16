#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
  string fileName;
  cout << "Enter input file name" << endl;
  cin >> fileName;

  ifstream inputFile;
  ofstream outputFile;

  inputFile.open(fileName);
  unsigned int storeNum;
  long long int salesNum;
  if (inputFile >> storeNum >> salesNum)
  {
    outputFile.open("saleschart.txt");
    // the file opened successfully
    while (inputFile >> storeNum >> salesNum)
    {
      if (storeNum < 1 || storeNum > 99)
      {
        cout << "The store number " << storeNum << " is not valid" << endl;
        break;
      }
      else if (salesNum < 0)
      {
        cout << "The sales value for store " << storeNum << " is negative" << endl;
        break;
      }
      else
      {
        cout << "Store" << setw(2) << storeNum << ":";
        if (salesNum % 5000 != 0)
        {
          cout << '*';
          salesNum = salesNum - 5000;
        }
        cout << '\n';
      }

    }
    inputFile.close();
    outputFile.close();
  }
  else
  {
    cout << "File " << '"' << fileName << '"' << " could not be opened" << endl;
  }

  return 0;
}
