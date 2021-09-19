//
//  main.cpp
//  BonusCS1336_InterstateHighwayNumbers
//
//  Created by Hamilton Ngo on 9/17/21.
//

#include <iostream>
using namespace std;

int main() {
    
   int highwayNumber;
   cin >> highwayNumber;

   /* Type your code here. */
    
    if (highwayNumber == 1000 || highwayNumber == 0) {
        cout << highwayNumber << " is not a valid interstate highway number." << endl;
    }

    if (highwayNumber > 0 && highwayNumber < 100) {
        if (highwayNumber % 2 == 0) {
            cout << "I-" << highwayNumber << " is primary, going east/west." << endl;
        } else {
            cout << "I-" << highwayNumber << " is primary, going north/south." << endl;
        }
    }
    
    if (highwayNumber > 99 && highwayNumber < 1000) {
        if (highwayNumber == 200) {
            cout << highwayNumber << " is not a valid interstate highway number." << endl;
            return -1;
        }
        cout << "I-" << highwayNumber << " is auxiliary, serving I-" << highwayNumber % 100 << (((highwayNumber % 100) % 2 == 0) ? ", going east/west." : ", going north/south.") << endl;
    }
    
   return 0;
}
