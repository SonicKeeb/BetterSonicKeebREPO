//
//  main.cpp
//  CS1336_RemoveGrayFromRGB
//
//  Created by Hamilton Ngo on 9/17/21.
//
// Find the smallest value of the three and Subtract that value from all 3 color values

#include <iostream>

int main() {
    
    int red;
    int green;
    int blue;
    int grayPart;
    
    std::cin >> red >> green >> blue;
    
    if (red < green && red < blue) {
        grayPart = red;
    } else if (green < red && green < blue) {
        grayPart = green;
    } else {
        grayPart = blue;
    }
    
    std::cout << red - grayPart << " " << green - grayPart << " " << blue - grayPart << std::endl;
    
}
