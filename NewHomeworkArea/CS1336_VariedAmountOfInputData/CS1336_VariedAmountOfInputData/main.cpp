//
//  main.cpp
//  CS1336_VariedAmountOfInputData
//
//  Created by Hamilton Ngo on 9/30/21.
//

#include <iostream>
#include <iomanip>
using namespace std;

// Takes max and average of inputted data so long as its not negative

int main() {
    
    // Declaration of variables
    
    int num;
    int count = 0;
    double average;
    double sum = 0;
    
    cin >> num;
    
    // Max will become whatever the biggest num is
    
    int max = num;
    
    // For whenever num is not negative, it will add itself to the total sum which
    // starts at 0, it then increases the count by 1 because we have already input
    // one number, then it inputs the next number and checks to see if that number
    // is the greatest number and sets max to become that number
    // Loop iterates again until negative number is inputted which is how it stops
    
    while (num >= 0) {
        sum = sum + num;
        count = count + 1;
        cin >> num;
        if (num >= max) {
            max = num;
        }
    }
    
    average = sum / count;
    cout << max << " " << fixed << setprecision(2) << average << endl;
    
    return 0;
}
