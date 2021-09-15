//
//  main.cpp
//  CS_1336_Golf
//
//  Created by Hamilton Ngo on 9/15/21.
//

/*  Golf scores record the number of strokes used to get the ball in the hole. The expected number of strokes varies from hole to hole and is called par (i.e. 3, 4, or 5). Each score's name is based on the actual strokes taken compared to par:
 
    "Eagle": number of strokes is two less than par
    "Birdie": number of strokes is one less than par
    "Par": number of strokes equals par
    "Bogey": number of strokes is one more than par
 
    Given two integers that represent par and the number of strokes used,
    write a program that prints the appropriate score name.

    Print "Error" if par is not 3, 4, or 5.

    Ex: If the input is:
    4 3
 
    The output is:
    Birdie */


#include <iostream>
#include <string>
using namespace std;

int main() {
    int par;
    int strokes;
    string name;

    /* Type your code here */
    
    std::cin >> par;
    std::cin >> strokes;
    
    if ( (par != 3) && (par != 4) && (par != 5)) {
        name = "Error";
        std::cout << name << std::endl;
    } else if ( strokes == par + 1 ) {
        name = "Bogey";
        std::cout << name << std::endl;
    } else if ( strokes == par ) {
        name = "Par";
        std::cout << name << std::endl;
    } else if ( strokes == par - 1 ) {
        name = "Birdie";
        std::cout << name << std::endl;
    } else if ( strokes == par - 2 ) {
        name = "Eagle";
        std::cout << name << std::endl;
    }

    return 0;
}
