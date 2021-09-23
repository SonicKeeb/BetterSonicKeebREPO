//
//  main.cpp
//  CS1336_ConvertFromSeconds
//
//  Created by Hamilton Ngo on 9/22/21.
//

#include <iostream>
using namespace std;

int main() {
   int seconds;
   int minutes;
   int hours;

   /* Type your code here. */
   
cin >> seconds;

hours = seconds / 3600 ;
seconds = seconds % 3600;
minutes = seconds / 60;
seconds = seconds % 60;

cout << "Hours: " << hours << endl;
cout << "Minutes: " << minutes<< endl;
cout << "Seconds: " << seconds << endl;

   return 0;
}
