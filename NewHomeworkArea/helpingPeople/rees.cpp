#include <iostream>
#include <iomanip>
using namespace std;

void read(unsigned int& value1, unsigned int& value2);

void display(unsigned int& value1, unsigned int& value2, unsigned char char1, unsigned char char2, int count);

int main()
{
  int count;
  unsigned int firstVal, secondVal;
  unsigned char firstChar, secondChar;

  read(firstVal, secondVal);

  display(firstVal, secondVal, firstChar, secondChar, count);

  return 0;
}

void read(unsigned int& value1, unsigned int& value2)
{
  cout << "Enter lower and upper values" << endl;
  cin >> value1;
  cin >> value2;

  while (value1 < 32 || value1 > 126 || value2 < 32 || value2 > 126 || value1 > value2)
  {
    cout << "Values must be in range 32 to 126 inclusive" << endl;

    cout << "Enter lower and upper values" << endl;
    cin >> value1;
    cin >> value2;

  }

}

void display(unsigned int& value1, unsigned int& value2, unsigned char char1, unsigned char char2, int count)
{

  char1 = value1;
  char2 = value2;

  count = 1;

  cout << "Characters for ASCII values between " << value1 << " and " << value2 << endl;
  cout << "----+----+----+----+" << endl;
  cout << char1;

  while(char1 < char2)
  {
    char1++;
    cout << char1;

    count = count + 1;

    if (count % 20 == 0 || count == (value2 + 1 - value1))
    {
      cout << endl;
    }

    if(char1 >= char2)
    {
      cout << endl;

      break;
    }
  }

  cout << "----+----+----+----+" << endl;

}
