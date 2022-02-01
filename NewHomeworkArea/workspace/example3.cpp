//PsuedoCode Here
/*
  Start program
  Include iomanip for setw
  use namespace std
  
  intialize string firstName, lastName
  initialize integer course
  initilize double e1, e2, e3
  intialize double avg
    
    output "Enter first and Last name"
    input firstName, lastName

    output "Enter Course"
    input course
      
    output "Exam Score 1"
    input e1

    output "Exam Score 2"
    input e2

    output "Exam Score 3"
    input e3
    
    avg = (e1 + e2 + e3) / 3
    
    output "Last", "First", "Course", "E1", "E2", "E3", "AVG"
    output lastName, firstName, course, e1, e2, e3, avg

    return 0
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

string firstName, lastName;
int course;
double e1, e2, e3;
double avg;

cout << "Enter your first and last name" << endl;
cin >> firstName >> lastName;

cout << "Enter your course number" << endl;
cin >> course;

cout << "Enter your exam score 1" << endl;
cin >> e1;

cout << "Enter your exam score 2" << endl;
cin >> e2;

cout << "Enter your exam score 3" << endl;
cin >> e3;

avg = (e1 + e2 + e3) / 3;

cout << left << setw(15) << "Last" << left << setw(15) << "First" << left << setw(5) << "Course  " << left << setw(4) << "E1" << left << setw(4) << "E2" << left << setw(4) << "E3" << left << setw(6) << "AVG" << endl;
cout << left << setw(15) << lastName << left << setw(17) << firstName << left << setw(6) << course << left << setw(4) << e1 << left << setw(4) << e2 << left << setw(4) << e3 << fixed << setprecision(2) << left << setw(6) << avg << endl;
  return 0;
}
