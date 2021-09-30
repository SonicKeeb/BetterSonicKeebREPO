//
//  main.cpp
//  CS1336_CountCharacters
//
//  Created by Hamilton Ngo on 9/30/21.
//

#include <iostream>
#include <string>

int main() {
    char inputChar;
    std::string inputStr;

    std::cin >> inputChar;
    std::getline(std::cin, inputStr);

    int len = inputStr.length();
    int counter = 0;

    for (int i = 0; i < len; i++){
        if (inputStr[i] == inputChar){
            counter++;
        }
    }

    if (counter != 1){
        std::cout << counter << " " << inputChar << "'s" << std::endl;
        return 0;
    }
    std::cout << counter << " " << inputChar << std::endl;

    return 0;
}
