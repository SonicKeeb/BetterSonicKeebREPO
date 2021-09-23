//
//  main.cpp
//  BonusCS1336_Seasons
//
//  Created by Hamilton Ngo on 9/18/21.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
string inputMonth;
int inputDay;

cin >> inputMonth;
cin >> inputDay;

	/* Type your code here. */

// The Dates for each season in the northern hemisphere are:
// Spring: march 20 - June 20
// Summer: June 21 - September 21
// Autumn: September 22 - December 20
// Winter: December 21 - March 19

if (inputMonth == "March" || inputMonth == "April" || inputMonth == "May" || inputMonth == "June") {
	if (inputDay >= 1 && inputDay <= 20) {
		cout << "Spring" << endl;
  }
} else if (inputMonth == "June" || inputMonth == "July" || inputMonth == "August" || inputMonth == "September") {
	if (inputDay >= 1 && inputDay <= 21) {
		cout << "Summer" << endl;
  }
} else if (inputMonth == "September" || inputMonth == "October" || inputMonth == "November" || inputMonth == "December") {
	if (inputDay >= 1 && inputDay <= 22) {
		cout << "Autumn" << endl;
  }
} else if (inputMonth == "December" || inputMonth == "January" || inputMonth == "Febuary" || inputMonth == "March") {
	if (inputDay >= 1 && inputDay <= 21) { 
		cout << "Winter" << endl;
  }
} else {
	cout << "Invalid" << endl;
}

    return 0;
}
