//
//  main.cpp
//  CS_1136_4.1_Lab_Part3
//
//  Created by Hamilton Ngo on 9/15/21.
//

// This program outputs a 12 x 12 Rectangle in an
// upright position and a 13 Unit base Equilateral Triangle

#include <iostream>

int main()
{
    
    // The next three lines here declare the variables I created which contain
    // the string characters in the shapes
    
    std::string rectangleRowOneAndTwelve;
    std::string rectangleRowMiddles;
    std::string triangleBase;

    // These next three lines are what I made my variables become which are the
    // base and middle portions of the rectangle as well as the base of the Triangle
    
    rectangleRowOneAndTwelve = "@@@@@@@@@@@@";
    rectangleRowMiddles = "@          @";
    triangleBase = "%%%%%%%%%%%%%";
    
    // This next line outputs the top and bottom row of the rectangle
    
    std::cout << rectangleRowOneAndTwelve << std::endl;
    
    // The next 3 lines are the for loop that I wrote which works to output the middle
    // rows of the rectangle that way I don't have to manually output them all
    // it iterates 10 times
    
    for (int i = 0; i <= 9; i++) {
      std::cout << rectangleRowMiddles << std::endl;
    }
    
    // This line outputs the bottom row of the Rectangle
    
    std::cout << rectangleRowOneAndTwelve << std::endl;
    
    // This line ends the next line after the Rectangle
    
    std::cout << std::endl;
    
    // These last lines manually output the 13 base Triangle
    
    std::cout << "      %" << std::endl;
    std::cout << "     % %" << std::endl;
    std::cout << "    %   %" << std::endl;
    std::cout << "   %     %" << std::endl;
    std::cout << "  %       %" << std::endl;
    std::cout << " %         %" << std::endl;
    std::cout << triangleBase << std::endl;
    
}
