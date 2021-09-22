#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/* Write a program that reads in five test scores. The program should them calculate the average for the five tests and display the average using fixed formatting with one digit of precision.

The prompt to read in the 5 values must be:

Enter 5 test grades */

// Program takes the input of 5 test scores which are double in type and finds their total average

int main() {

// Declaration of variables in type double

double testGrade;
double testGrade1;
double testGrade2;
double testGrade3;
double testGrade4;
double average;

// Outputting prompt to read in the 5 values

cout << "Enter 5 test grades" << endl;

// Next line takes the character inputs for all 5 test grades

cin >> testGrade >> testGrade1 >> testGrade2 >> testGrade3 >> testGrade4;

// Next line defines and initiliazes what average is

average = (testGrade + testGrade1 + testGrade2 + testGrade3 + testGrade4) / 5.0;

// Last line of code outputs the string "Average :" and outputs what the value of the average actually is with 1 decimal place

cout << "Average: " << fixed << setprecision(1) << average << endl;


}
