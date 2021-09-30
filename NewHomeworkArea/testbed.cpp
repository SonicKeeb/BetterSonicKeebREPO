#include <iostream>
#include <string>
#include <cmath>

int main() {

std::string inputString;
std::getline(std::cin, inputString);
for ( int i=0; i<inputString.size();
i++) {
std::cout << (char)
std::toupper(inputString.at(i));
}
std::cout << std::endl;

}
