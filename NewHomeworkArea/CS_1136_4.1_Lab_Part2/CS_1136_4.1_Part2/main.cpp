//
//  main.cpp
//  CS_1136_4.1_Part2
//
//  Created by Hamilton Ngo on 9/15/21.
//

#include <iostream>
using namespace std;

int main()
{
    double risingLevel;
   
   // read in the estimated rising ocean level
   cout << "Enter the estimated ocean level" << endl;
   cin >> risingLevel;
   
   // YOUR CODE GOES HERE
   
    /* The next 4 lines output the string letting us know what the level, years, and total rise are. Concurrently it also calculates the total risingLevels by multipllying the inputed rising level with the corresponding amount of years. It then outputs the total risingLevel as well as ends the line. */
    
    cout << "Level: " << risingLevel << endl;
    cout << "Years: 5, Rise: " << risingLevel * 5 << endl;
    cout << "Years: 10, Rise: " << risingLevel * 10 << endl;
    cout << "Years: 50, Rise: " << risingLevel * 50 << endl;
    
   return 0;
}
