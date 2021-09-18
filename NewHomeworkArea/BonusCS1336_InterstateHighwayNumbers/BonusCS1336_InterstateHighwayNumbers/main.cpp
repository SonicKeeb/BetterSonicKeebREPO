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

    
    if (highwayNumber > 0 && highwayNumber < 100 && highwayNumber % 2 == 0) {
        cout << "I-" << highwayNumber << " is primary, going east/west." << endl;
    } else if (highwayNumber > 100 && highwayNumber % 2 == 0){
        cout << "I-" << highwayNumber << " is auxillary, servi, going north/south." << endl;
    }
    
    if (highwayNumber == 200 || highwayNumber == 1000) {
        cout << highwayNumber << " is not a valid interstate highway number." << endl;
    } else {
        return -1;
    }
    
   return 0;
}
