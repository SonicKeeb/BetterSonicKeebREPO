/*
Hamilton Ngo
CS1337.002 
3/26/2022
This program presents the user with a menu and requires them to go through the menu
in the selected order from top to bottom implementing the contents of the text file chosen
by the user and it does some calculations and appending with it.
Assumptions: My part e never fails assuming that the person read my directions right and did what
I told them to do correctly

NOTE: I will add in my text file because there are some parts that I used the direct name of
my text file
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct info { //struct created and defined right here
  int id;
  unsigned long long int accountNumber;
  double dollar;
  string dateTime;
};
typedef struct info transaction;

//Next 6 lines are function prototypes, full functoins under main
void displayMenu();
int testInputFile(string fullpath);
bool readTransactionInformation(transaction *&arr, int SIZE, string fullpath);
void transactionStatistics(transaction *arr, int SIZE, int &min, int &max, double &average);
transaction *searchElement(transaction *arr, int SIZE, int key);
bool addTransaction(string filename);

int main() {

  string fileName;
  
  transaction *ptr = nullptr;
  int num_rows = 0;
  bool option_arrays[5] = {false}; // sets all 5 elements to false
  int min;
  int max;
  double average;
  int key;
  char user_option; // stores user_option
  do {
    displayMenu();
    cout << "enter your option from menu in lowercase" << endl;
    cin >> user_option;
    switch (user_option) {
      case 'a':
        option_arrays[0] = true; //setting each part of the step to true allows the input validation2wrk
        cout << "Enter full path file" << endl;
        cin >> fileName;
        num_rows = testInputFile(fileName);
        break;
      case 'b':
        if (option_arrays[0] == true) {
          readTransactionInformation(ptr, num_rows, fileName);
        }
        option_arrays[1] = true;
        break;
      case 'c':
        if (option_arrays[1] == true) {
          transactionStatistics(ptr, num_rows, min, max, average);
        }
        option_arrays[2] = true;
        break;
      case 'd':
        if (option_arrays[2] == true) {
          transaction *point;
          point = searchElement(ptr, num_rows, key);
        }
        option_arrays[3] = true;
        break;
      case 'e':
        if (option_arrays[3] == true) {
          addTransaction("fullPath.txt");
        }
        option_arrays[4] = true;
      case 'f':
        exit(0);
      default:
        cout << "Invalid input" << endl;
        break;
    }
  } while(user_option != 'f');

  return 0;
}

void displayMenu() { // Display menu function to save lines
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
    if (lines != "") {
      count++;
    }
  }

  if (count == 0) {
    cout << "Empty File" << endl;
    return 0;
  }

  inputFile.close();

  cout << "Number of transactions is: " << count << endl << endl;
  return count;
}

bool readTransactionInformation(transaction *&arr, int SIZE, string fullpath) {

  if (arr != nullptr) {
    delete[] arr;
  }
  arr = new transaction[SIZE];

  ifstream inputFile;
  inputFile.open("fullPath.txt");
  if (!inputFile.is_open()) {
    cout << "Error opening the file!" << endl;
    return -1;
  }

  int count = 0;
  while (!inputFile.eof()) {
    inputFile >> arr[count].id >> arr[count].accountNumber >> arr[count].dollar 
      >> arr[count].dateTime;
    count++;
  }
  return true;
}

void transactionStatistics(transaction *arr, int SIZE, int &min, int &max, double &average) {
  if (arr != nullptr) {
    delete[] arr;
  }
  arr = new transaction[SIZE];

  ifstream inputFile;
  inputFile.open("fullPath.txt");
  if (!inputFile.is_open()) {
    cout << "Error opening the file!" << endl;
    exit(0);
  }
  double sum = 0;
  int count = 0;
  while (!inputFile.eof()) {
    inputFile >> arr[count].id >> arr[count].accountNumber >> arr[count].dollar 
      >> arr[count].dateTime;
      sum += arr[count].dollar;
    count++;
    }

  int temp; // Sorting the dollar array so that the max and min are always first and last index;
  bool SWAP;
  do {
    SWAP = false;

    for (int i = 0; i < SIZE; i++) {
      if (arr[i].dollar > arr[i+1].dollar) {
        temp = arr[i].dollar;
        arr[i].dollar = arr[i+1].dollar;
        arr[i+1].dollar = temp;
        SWAP = true;
      }
    }
  } while (SWAP);

  min = 0;
  max = SIZE-1;
  average = sum / SIZE;;
  
  cout << endl;
  cout << "Min: " << min << endl;
  cout << "Max: " << max << endl;
  cout << "Average: " << fixed << setprecision(2) << average << endl << endl;
}

transaction *searchElement(transaction *arr, int SIZE, int key) {
  cout << "Enter an integer value - key: " << endl;
  cin >> key;
  cout << endl;
  for (int i = 0; i < SIZE; i++) {
    if (arr[i].id == key) {
      cout << "value has been found" << endl;
      return &arr[i];
    } 
  }
  cout << "Value was not found" << endl;
  return nullptr;
}

bool addTransaction(string filename) {

  filename = "fullPath.txt";
  ofstream file_out;

  file_out.open(filename, ios_base::app);
  cout << "Enter in id, account number, dollar, and dateTime(all at once have a space inbetween: " 
       << endl;
  
  int id;
  unsigned long long int accountNumber;
  double dollar;
  string dateTime;

  cin >> id >> accountNumber >> dollar >> dateTime;

  file_out << id << " " << accountNumber << " " << dollar << " " << dateTime << endl;

return true;
}
