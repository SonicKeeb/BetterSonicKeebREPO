//
//  main.cpp
//  CS1336_Pizza_Party
//
//  Created by Hamilton Ngo on 9/16/21.
//

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    int people;
    int numPizzas;
    double cost;

    /* Type your code here. */
   
   cin >> people;
   
   numPizzas = ceil((people * 2.0) / 12.0);
   cost = numPizzas * 14.95;
   cout << "Pizzas: " << numPizzas << endl;
   
   cout << "Cost: $" << fixed << setprecision(2) << cost << endl;

}
