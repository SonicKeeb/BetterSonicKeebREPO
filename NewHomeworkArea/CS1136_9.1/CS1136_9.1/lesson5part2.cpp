//
//  lesson5part2.cpp
//  CS1136_9.1
//
//  Created by Hamilton Ngo on 10/10/21.
//

/* This program gives a choice of 4 mediums and calculated the distance traveled through the respective medium in meters based on the time ( in seconds ) entered. */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
// declaratoin of all variables that will be used
    unsigned int menuNum;
    string menuItem;
    double seconds;
    double airSpeed = 331.5;
    double cdSpeed = 258.0;
    double helium = 972.0;
    double hydrogen = 1270.0;
    double distanceTraveled;
    // Prompt statement on medium choice
    cout << "Select the medium that sound is traveling through:" << endl
         << "1 Carbon Dioxide" << endl
         << "2 Air" << endl
         << "3 Helium" << endl
         << "4 Hydrogen" << endl;
    // Input of the choice buy a number
    cin >> menuNum;
    // Precondition so that  if the choice entered was invalid it would output fail statement
    // and stop, if not invalid then it prompts the time to be inputted
    if ( menuNum < 1 || menuNum > 4) {
        cout << "The menu value is invalid. Please run the program again." << endl;
        return -1;
    } else {
        cout << "Enter time (in seconds)" << endl;
    }
    // Precondition assigning the names of mediums with the choice from the selection
    if ( menuNum == 1 ) {
        menuItem = "Carbon Dioxide";
    } else if ( menuNum == 2 ) {
        menuItem = "Air";
    } else if ( menuNum == 3 ) {
        menuItem = "Helium";
    } else {
        menuItem = "Hydrogen";
    }
    // Input of seconds
    cin >> seconds;
    // Conditional that initially checks if input time was valid, if not it stops, otherwise
    // it calculated the distanceTraveled for each selected medium and time inputted
    if ( seconds < 0.000 || seconds > 30.000 ) {
        cout << "The time must be between 0.000 and 30.000 (inclusive)" << endl;
        return -1;
    } else {
        if ( menuNum == 1 ) {
            distanceTraveled = seconds * cdSpeed;
        } else if ( menuNum == 2 ) {
            distanceTraveled = seconds * airSpeed;
        } else if ( menuNum == 3 ) {
            distanceTraveled = seconds * helium;
        } else {
            distanceTraveled = seconds * hydrogen;
        }
    }
    // Outputting the final prompt and calculatoins
    cout << menuItem << ": " << fixed << setprecision(3) << seconds << " seconds" << endl;
    cout << "Traveled " << fixed << setprecision(4) << distanceTraveled << " meters" << endl;
    
    return 0;
}
