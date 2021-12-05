#include <iostream>
#include <fstream> 
#include <iomanip> 
#include <vector>

using namespace std;

const int MAX_SIZE = 21;

int readSquare(int square[MAX_SIZE][MAX_SIZE], string inputFileName);
bool validateSquare(const int square[MAX_SIZE][MAX_SIZE], int size);
void displayFunction(const int square[MAX_SIZE][MAX_SIZE], int arraySize);

int main()
{
  int arraySize;
  int square[MAX_SIZE][MAX_SIZE];
  string fileName;
  bool validate;
  cout << "Enter input file name" << endl;
  cin >> fileName;

  //Call readSquare function
  arraySize = readSquare(square, fileName);

  if (arraySize != 0)
  {
    displayFunction(square, arraySize);
  }
  else
  {
    cout << "File " << '"' << fileName << '"' << " could not be opened" << endl;
    return 0;
  }

  //Call validateSquare
  validate = validateSquare(square, arraySize);

  if (validate)
  {
    cout << "Valid magic square" << endl;
  }
  else
  {
    cout << "Invalid magic square" << endl;
  }

  return 0;
}

int readSquare(int square[MAX_SIZE][MAX_SIZE], string inputFileName)
{
  int size;
  ifstream inputFile;
  inputFile.open(inputFileName);

  if (inputFile)
  {
    inputFile >> size;

    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        if (inputFile.eof())
        {
          inputFile.close();
          return size;
        }
        inputFile >> square[i][j];
      }
    }
  }
  else
  {
    return 0;
  }
  return size;
}
bool validateSquare(const int square[MAX_SIZE][MAX_SIZE], int size)
{
  int sum = size * (size * size + 1) / 2;
  int horizontal = 0;
  int vertical = 0;
  int diagonal1 = 0;
  int diagonal2 = 0;
  int counter = 1; 
  int toSize = 0;
  int check;


  //horizontal check
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      horizontal = horizontal + square[i][j];
    }
    if (horizontal != sum)
    {
      return false;
    }
    horizontal = 0;
  }

  //vertical check
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      vertical = vertical + square[j][i];
    }
    if (vertical != sum)
    {
      return false;
    }
    vertical = 0;
  }

  //double diagonal check
  for (int i = 0; i < size; i++)
  {
    diagonal1 = diagonal1 + square[i][i];
  }

  for (int i = 0; i < size; i++)
  {
    diagonal2 = diagonal2 + square[size - 1 - i][i];
  }

  if (diagonal2 != diagonal1)
  {
    return false;
  }


  while (toSize < size * size)
  {
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        check = square[i][j];

        if (check == counter)
        {
          break;
        }

      }
      if (check == counter)
      {
        counter++;
        break;
      }
    }
    toSize++;
  }
  if (counter - 1 != size * size)
  {
    return false;
  }

  return true;

}
void displayFunction(const int square[MAX_SIZE][MAX_SIZE], int arraySize)
{
  cout << "Magic square" << endl;

  for (int i = 0; i < arraySize; i++)
  {
    for (int j = 0; j < arraySize; j++)
    {
      cout << square[i][j] << " ";
    }
    cout << '\n';
  }
  cout << '\n';
}
