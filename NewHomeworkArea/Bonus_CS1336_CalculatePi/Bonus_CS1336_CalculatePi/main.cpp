//
//  main.cpp
//  Bonus_CS1336_CalculatePi
//
//  Created by Hamilton Ngo on 9/17/21.
//

#include <iostream>
using  namespace std;
int main() {
    
//Calculate pi mathmatically 

double pi;
double circumference;
double diameter;

cout << "Enter the circumference" << endl;
  cin >> circumference;
cout << "Enter the diameter" << endl;
  cin >> diameter;

pi = circumference / diameter;

cout << "Pi is " << pi << endl;

return 0;
    
}
