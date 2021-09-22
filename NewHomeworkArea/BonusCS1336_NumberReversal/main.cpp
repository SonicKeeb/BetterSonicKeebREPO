#include <iostream>
using namespace std;

int main() {
   int number;
   int reversedNumber = 0; 
   int remainder;
   
   // Get the number here
   std::cin >> number;
   
   while ( number > 0) {
       remainder = number % 10;
       reversedNumber = reversedNumber * 10 + remainder;
       number /= 10;
      
      // Output a digit and divide to get rid of that number
      std::cout << remainder;
   }
   std::cout << std::endl;
   
   return 0;
}
