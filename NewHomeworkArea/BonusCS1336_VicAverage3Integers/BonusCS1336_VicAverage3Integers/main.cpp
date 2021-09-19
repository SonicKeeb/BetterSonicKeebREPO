//
//  main.cpp
//  BonusCS1336_VicAverage3Integers
//
//  Created by Hamilton Ngo on 9/18/21.
//

#include <iostream>

int main() {
    
    double num1;
    double num2;
    
    std::cout << "Enter the first value ";
    std::cin >> num1;
    std::cout << num1 << std::endl;
    
    std::cout << "Enter the second value ";
    std::cin >> num2;
    std::cout << num2 << std::endl;
    
    num1 = num1 + num2;
    
    std::cout << "Enter the third value ";
    std::cin >> num2;
    std::cout << num2 << std::endl;
    
    std::cout << "The average is " << (num1 + num2) / 3.0 << std::endl;
    
    return 0;
}
