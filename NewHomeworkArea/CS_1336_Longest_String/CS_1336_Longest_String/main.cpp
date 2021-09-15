//
//  main.cpp
//  CS_1336_Longest_String
//
//  Created by Hamilton Ngo on 9/15/21.
//

// Write a program that takes two strings and outputs the longest string. If they are the same length then output the second string.

// Ex. If the input is:
// almond pistachio
// output is
// pistachio

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1;
    string str2;
    string longest;

   /* Type your code here */
    
    std::cin >> str1;
    std::cin >> str2;
    
    /* simple if else statement however if they strings are the same length then it outputs the second string */
    
    if ( str1 > str2 ) {
        longest = str1;
        std::cout << longest << std::endl;
    } else if ( str2 > str1 ) {
        longest = str2;
        std::cout << longest << std::endl;
    } else {
        longest = str2;
        std::cout << longest << std::endl;
    }

   return 0;
}
