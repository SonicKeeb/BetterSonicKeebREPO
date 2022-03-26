#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct info {
  int id;
  int accountNumber;
  double dollar;
  string dateTime;
};
typedef struct info transaction;


void displayMenu();
int testInputFile(string fullpath);
bool readTransactionInformation(transaction *&arr, int SIZE, string fullpath);

int main() {

  string fileName = "fullPath.txt";
  
  transaction *ptr;
  transaction array[100];
  ptr = array;

  bool option_arrays[5] = {false}; // sets all 5 elements to false

  char user_option; // stores user_option
  do {
    displayMenu();
    cout << "enter your option from menu" << endl;
    cin >> user_option;
    switch (user_option) {
      case 'a':
        option_arrays[0] = true;
        cout << "Enter full path file" << endl;
        testInputFile("fullPath.txt");
        break;
      case 'b':
        if (option_arrays[0] == true) {
          readTransactionInformation(ptr, 100, "fullPath.txt");
        }
      case 'c':
      case 'd':
      case 'e':
      case 'f':
      default:
        cout << "invalid input" << endl;
        break;
    }
  } while(user_option != 'f');

  return 0;
}

void displayMenu() {
  cout << "A. Get file location" << endl <<
    "B. Read file information" << endl <<
    "C. Display statistics" << endl <<
    "D. Search for a transaction (ID)" << endl <<
    "E. Add a transaction" << endl <<
    "F. Exit\n" << endl;

  cout << "input(in order) again: " << endl;
}

int testInputFile(string fullpath) {

  ifstream inputFile;
  inputFile.open("fullPath.txt");
  if (!inputFile.is_open()) {
    cout << "Error opening the file!" << endl;
    return -1;
  }

  int count = 0;
  string lines;
  while (!inputFile.eof()) {
    getline(inputFile, lines);
    count++;
  }

  if (count == 0) {
    cout << "Empty File" << endl;
    return 0;
  }

  inputFile.close();

  cout << "Number of transactions is: " << count-1 << endl;
  return count;
}

bool readTransactionInformation(transaction *&arr, int SIZE, string fullpath) {
  ifstream inputFile;
  inputFile.open("fullPath.txt");
  if (!inputFile.is_open()) {
    cout << "Error opening the file!" << endl;
    return -1;
  }

  int count = 0;
  if (arr != nullptr) {
    delete[]arr;
  }
  arr = new transaction[SIZE];
  while (!inputFile.eof()) {
    inputFile >> arr[count].id >> arr[count].accountNumber >> arr[count].dollar 
              >> arr[count].dateTime;
}
return true;
}
