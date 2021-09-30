//
//  main.cpp
//  CS1336_CheckerForIntegerString
//
//  Created by Hamilton Ngo on 9/30/21.
//

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main() {
   std::string userString;
   
   cin >> userString;
   
   int userStringLength = userString.length();
   
   for (int i = 0; i < userStringLength; i++){
      if (!(userString[i] >= '0' && userString[i] <= '9')){
         std::cout << "No" << std::endl;
         return -1;
      }
   }
   
   std::cout << "Yes" << std::endl;
   
   return 0;
}
