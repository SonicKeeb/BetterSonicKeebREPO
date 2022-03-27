#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct info {
  int id;
  unsigned long long int accountNumber;
  double dollar;
  string dateTime;
};
typedef struct info transaction;


void displayMenu();
int testInputFile(string fullpath);
bool readTransactionInformation(transaction *&arr, int SIZE, string fullpath);
void transactionStatistics(transaction *arr, int SIZE, int &min, int &max, double &average);
transaction *searchElement(transaction *arr, int SIZE, int key);

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
        option_arrays[0] = true;
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
          transaction *searchElement(ptr, num_rows, key);
        }
        option_arrays[3] = true;
        break;
      case 'e':
      case 'f':
      default:
        cout << "Invalid input  or you exited" << endl;
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

  int temp; // Sorting the dollar array;
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
      return &arr[i];
    } 
  }
  return nullptr;
}
