#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

//This program will read inthe number of seconds and convert it to days, hours, minutes, and remaining seconds.

int main() {

long long int seconds, hours, minutes, days;

cout << "Enter seconds" << endl;
cin >> seconds;
cout << "Total seconds: " << seconds << endl << endl;

days = seconds / 86400;
hours = (seconds % 86400) / 3600;
seconds = (seconds % 86400) % 3600;
minutes = seconds / 60;
seconds = seconds % 60;


if (seconds <= 0) {
	cout << "Total seconds must be greater than zero" << endl;
	return -1;
} else if (seconds > 0) {
	if (days == 0) {
		;
	} else { 
	cout << days << " day(s)" << endl;
	}
	if (hours == 0) {
		;
	} else {
	cout << hours << " hour(s)" << endl;
	}
	if (minutes == 0) {
		;
	} else {
	cout << minutes << " minute(s)" << endl;
	}
	if (seconds == 0) {
		;
	} else {
	cout << seconds << " second(s)" << endl;
 }
} else {
	;
}
return 0;
}
