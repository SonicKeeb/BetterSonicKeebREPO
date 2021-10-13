//
//  main.cpp
//  CS1136_9.1
//
//  Created by Hamilton Ngo on 10/10/21.
//
/* This program takes in the user's input of a medium and the following total distance traveled and calculates and outputs what the total time it takes to cover that distance through that medium.*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;
int main() {
    // insert code here...
    
    // Declaration of variables
    const int air = 1100;
    const int water = 4900;
    const int steel = 16400;
    unsigned int medium;
    double distance;
    double seconds;
    
    
    // Prompt Statements and input of medium which is answering the prompt
    cout << "Select the medium that sound is traveling through:" << endl;
    cout << "1 Air" << endl << "2 Water" << endl << "3 Steel" << endl;
    cin >> medium;
    
    // Switch statement for cases 1-3 if it is anything else activate default statement
    switch(medium) {
        case 1:
            cout << "Enter distance (in feet)" << endl; // Prompt Statement
            cin >> distance; // Input
            if (distance <= 0) { // Conditional to check if input is greater than 0
                cout << "The distance must be greater than zero" << endl;
            } else {
                cout << "Air: " << fixed << setprecision(4) << distance << " ft" << endl;
                seconds = distance / air; // calculation and output
                cout << "Traveled for " << fixed << setprecision(4) << seconds << " seconds" << endl;
            }
            break; // Stop here for this case
            
            // All following cases do the same thing for each respective medium
            
        case 2:
            cout << "Enter distance (in feet)" << endl;
            cin >> distance;
            if (distance <= 0) {
                cout << "The distance must be greater than zero" << endl;
            } else {
                cout << "Water: " << fixed << setprecision(4) << distance << " ft" << endl;
                seconds = distance / water;
                cout << "Traveled for " << fixed << setprecision(4) << seconds << " seconds" << endl;
            }
            break;
        case 3:
            cout << "Enter distance (in feet)" << endl;
            cin >> distance;
            if (distance <= 0) {
                cout << "The distance must be greater than zero" << endl;
            } else {
                cout << "Steel: " << fixed << setprecision(4) << distance << " ft" << endl;
                seconds = distance / steel;
                cout << "Traveled for " << fixed << setprecision(4) << seconds << " seconds" << endl;
            }
            break;
        default: // Default statement for if input medium is not 1, 2, 3
            cout << "The menu value is invalid. Please run the program again." << endl;
    }
 
    return 0;
}
