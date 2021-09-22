#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/* Write a program that reads in five test scores. The program should them calculate the average for the five tests and display the average using fixed formatting with one digit of precision.

The prompt to read in the 5 values must be:

Enter 5 test grades */

int main() {

double testGrade;
double testGrade1;
double testGrade2;
double testGrade3;
double testGrade4;
double average;


cout << "Enter 5 test grades" << endl;

cin >> testGrade >> testGrade1 >> testGrade2 >> testGrade3 >> testGrade4;

average = (testGrade + testGrade1 + testGrade2 + testGrade3 + testGrade4) / 5.0;

cout << "Average: " << fixed << setprecision(1) << average << endl;


}
