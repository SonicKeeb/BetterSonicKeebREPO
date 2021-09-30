//
//  main.cpp
//  CS1336_MadLib-Loops
//
//  Created by Hamilton Ngo on 9/30/21.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
   
    //Declaration of variables
    
    string inputString;
    int num;
    
    //Inputs
    
    cin >> inputString;
    cin >> num;
    
    //For whenever inputString is NOT "quit" it runs
    
    while (inputString != "quit") {
        cout << "Eating " << num << " " << inputString << " a day keeps you happy and healthy." << endl;
        cin >> inputString;
        cin >> num;
    }
    
    return 0;
}
