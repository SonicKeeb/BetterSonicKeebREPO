//
//  main.cpp
//  CS_1336_Program_Options
//
//  Created by Hamilton Ngo on 9/15/21.
//

#include <iostream>

int main() {
    char optionFlag;
    std::cin >> optionFlag;

    // Put the switch statement here
    
    switch (optionFlag) {
        case 'a':
            std::cout << "Everything" << std::endl;
            break;
        case 'c':
            std::cout << "Character mode" << std::endl;
            break;;
        case 'e':
            std::cout << "Everything" << std::endl;
            break;;
        case 'i':
            std::cout << "Interactive" << std::endl;
            break;
        case 'o':
            std::cout << "Printing to a file" << std::endl;
            break;
        default:
            std::cout << "Not supported" << std::endl;
            break;
    }
    return 0;
}
