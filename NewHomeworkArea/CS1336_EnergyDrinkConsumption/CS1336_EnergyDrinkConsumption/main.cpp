//
//  main.cpp
//  CS1336_EnergyDrinkConsumption
//
//  Created by Hamilton Ngo on 9/17/21.
//

#include <iostream>

int main() {
    
    int customers;
    int oneOrMore;
    int citrus;
    
    std::cin >> customers;
    
    oneOrMore = customers * 0.15;
    citrus = oneOrMore * 0.58;
    
    std::cout << oneOrMore << std::endl;
    std::cout << citrus << std::endl;
    
    return 0;
}
