#include <iostream>
#include <fstream>
#include <string>
#define MAX_N 100
using namespace std;

int main(){

  int data[MAX_N]; // to store the sample values from file
  int counter; // to be used as index
  int N; // the number of samples
  fstream myfile; // for i/o

//Do while loop that asks for an input of sample size so long as the input is invalid in range

  do {
    cout << "Enter the number of samples ";
    cin >> N;
  }
  while(N < 1 || N > 100);

  myfile.open("test.txt", ios::out); // opens file as ofstream


//Error message incase the file does not open
  if (!myfile.is_open()) {
    cout << "Error in file opening\n";
    return -1;
  }


//loop for inputting random numbers into text file from 0 to sample size inputted
  for (counter = 0; counter < N; counter++) {
    myfile << rand() << endl;
  }

  myfile.close(); //Closing the file to make sure it is not modified or tampered after the inputs

  // opening file for reading
  myfile.open("test.txt", ios::in);


//Error message incase the file does not open
  if(!myfile.is_open()) { 
    cout << "Error in file reading\n";
    return -2;
  }


//Set counter to 0 that way we can loop the saved random numbers from the text file and loop input them
//into an array
  counter = 0;

  while (!myfile.eof()) {
    myfile >> data[counter];
    counter++;
  }

  // display the values
  cout << "COL1\tCOL2\tCOL3\tCOL4";
  for (counter = 0; counter < N; counter++) {
    if (counter % 4 == 0) {
      cout << endl;
    }
    cout << data[counter] << "\t";
  }
  cout << endl;

  // finding max/min
  int maxInArray = data[0], minInArray = data[0];

  for (int i = 0; i < N; i++) {
    if (maxInArray < data[i]) { 
      maxInArray = data[i];
    }
    if (minInArray > data[i]) { 
      minInArray = data[i];
    }
  }

  // display min and max of array
  cout << "The maximum value in this list is: " << maxInArray << endl;
  cout << "The minimum value in this list is: " << minInArray << endl;

  return 0;
}
