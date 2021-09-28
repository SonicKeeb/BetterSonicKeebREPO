#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {

int employees, hoursWorked;
double payRate, grossPay;

cout << "Total Employees" << endl;
cin >> employees;

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
