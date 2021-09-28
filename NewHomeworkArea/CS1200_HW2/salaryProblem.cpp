#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {

//Declaring variables

int employees, hoursWorked;
double payRate, grossPay;

//Outputting Total Employees prompt and inputting total employees

cout << "Total Employees" << endl;
cin >> employees;

//Loop that iterates depening on total # of employees
//Takes input of payRate and hoursWorked for each emplyee
//And calculates it each time for each employee
//It then outputs the Employee number and their grosspay

for (int i = 0; i <  employees; i++) {

cout << "PayRate ";
cin >> payRate;
cout << endl;
cout << "Hours Worked ";
cin >> hoursWorked;
cout << endl << endl;

if (hoursWorked > 40) {
	grossPay = (1.5 * payRate) * hoursWorked;
} else {
	grossPay = payRate * hoursWorked;
}  
cout << "Employee " << i << " GrossPay " << grossPay << endl << endl; 
}

}
