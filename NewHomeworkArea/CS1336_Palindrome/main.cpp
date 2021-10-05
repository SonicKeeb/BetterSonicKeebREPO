#include <iostream>
#include <string>
#include <cctype>
using namespace std;

   /* Type your code here. */

int main() {

    string input;
    getline(cin, input);

    string output, reverseOutput = "";

    int length = input.length();

    for (int i = 0; i < length; i++){
        if (input[i] == ' '){
            continue;
        }
        output += input[i];
    }

    for (int i = output.length() - 1; i >= 0; i--){
        reverseOutput += output[i];
    }

    if (!(output == reverseOutput)){
        std::cout << "not a ";
    }

    std::cout << "palindrome: " << input << std::endl;

    return 0;
} 
