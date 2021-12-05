#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_COLUMNS = 5;

int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName);

double average(double values[][MAX_COLUMNS], int numRows);

double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows);

double smallestVal(double values[][MAX_COLUMNS], int row);


int main()
{
  const int MAX_ROWS = 30;
  double grades[MAX_ROWS][MAX_COLUMNS];
  int row = 0;
  int column = 0;
  string fileName;

  ifstream inputFile;

  cout << "Enter input file name" << endl;
  cin >> fileName;

  inputFile.open(fileName);

  if (inputFile)
  {
    int actualRows = readFile(grades, MAX_ROWS, fileName);
    if (actualRows == 0)
    {
      cout << "The input file " << '"' << fileName << '"' << " did not contain any data" << endl;
      return 0;
    }
    else
    {
      cout << "Processing " << actualRows << " rows, and 5 columns" << endl;
      cout << fixed << setprecision(2) << "Average for all values is " << average(grades, actualRows) << endl;

      while (column < MAX_COLUMNS)
      {
        cout << fixed << setprecision(2) << "Average for column " << column << " is " << columnAverage(grades, column, actualRows) << endl;
        column++;
      }
      while (row < actualRows)
      {
        cout << fixed << setprecision(2) << "Smallest value for row " << row << " is " << smallestVal(grades, row) << endl;
        row++;
      }
    }

  }
  else
  {
    cout << "File " << '"' << fileName << '"' << " could not be opened" << endl;
  }

  inputFile.close();


  return 0;
}

int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName)
{
  int counter = 0;
  ifstream inputFile;
  inputFile.open(inputFileName);

  for (int i = 0; i < maxRows; i++)
  {
    for (int j = 0; j < MAX_COLUMNS; j++)
    {
      if (inputFile.eof()) {
        return counter;
      }
      inputFile >> values[i][j];
    }
    counter++;
    if (inputFile.eof())
    {
      return counter;
    }
    if (counter > 30)
    {
      return 30;
    }

  }
  return counter;
}

double average(double values[][MAX_COLUMNS], int numberRows)
{
  double runAvg = 0;
  int counter = 0
    ;
  for (int i = 0; i < numberRows; i++)
  {
    for (int j = 0; j < MAX_COLUMNS; j++)
    {
      runAvg = runAvg + values[i][j];
      counter++;
    }

  }
  return runAvg / counter;
}

double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows)
{
  double avg = 0;
  for (int i = 0; i < numberRows; i++)
  {
    avg = avg + values[i][column];
  }
  return avg / numberRows;
}

double smallestVal(double values[][MAX_COLUMNS], int row)
{
  double val;
  double smallestVal = 1000;
  for (int i = 0; i < MAX_COLUMNS; i++)
  {
    val = values[row][i];

    if (val < smallestVal)
    {
      smallestVal = values[row][i];
    }
  }
  return smallestVal;
}
