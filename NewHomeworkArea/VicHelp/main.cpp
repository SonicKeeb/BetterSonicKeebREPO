//AverageOfInputtedIntegerValues.cpp: This Program Calculates the Average/Mean of a Defined/Inputted Maximum of X Values and Asks for Their Y Points to be Inputted
//Name: Victor Sim
//Class Section: Online COSC 1436 (Programming Fundamentals 1)
//Date: 10/9/21

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {

int numOfValues;
double values;
double totalOfValues = 0;
const int topBoundary = 10;
const int bottomBoundary = 2;
const int precision = 3;
int count = 0;
double average;

cout << "Enter a number of values from 2 to 10: ";
cin >> numOfValues;

while (numOfValues < bottomBoundary || numOfValues > topBoundary) {
  cout << "Invalid input!" << endl;
  cout << "Enter a number of values from 2 to 10: ";
  cin >> numOfValues;
}

for (int i = 0; i < numOfValues; i++) {
  cout << "Enter value " << i+1 << ": ";
  cin >> values;
  totalOfValues += values;
  count++;
}

average = totalOfValues / count;
cout << "The average is " << fixed << setprecision(precision) << average << endl;


return 0;
}
