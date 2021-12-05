#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int main() {

  /* TODO: Declare any necessary variables here. */

  char letter;
  string firstName, lastName;
  double num1, num2, num3;
  double midterm1, midterm2, finalAverage, average = 0;

  /* TODO: Read a file name from the user and read the tsv file here. */

  ifstream fileInput;
  fileInput.open("StudentInfo.tsv");
  if ( !fileInput.is_open()) {
    cerr << "File didn't open!" << endl;
    exit(1);
  }

  ofstream fileOutput;
  fileOutput.open("report.txt");
  if ( !fileOutput.is_open()) {
    cerr << "Output file didn't open!" << endl;
    exit(1);
  }

  /* TODO: Compute student grades and exam averages, then output results to a text file here. */

  while (fileInput >> firstName >> lastName >> num1 >> num2 >> num3) {
    average = (num1 + num2 + num3) / 3;
    if (average >= 90) {
      letter = 'A';
    } else if (average >= 80 && average < 90) {
      letter = 'B';
    } else if (average >= 70 && average < 80) {
      letter = 'C';
    } else if (average >= 60 && average < 70) {
      letter = 'D';
    } else {
      letter = 'F';
    }

    fileOutput << fixed << setprecision(2);

    fileOutput << firstName << '\t' << lastName << '\t' << num1 << '\t' << num2 << '\t' << num3 << '\t' << letter << endl;
   

    if ( fileInput.fail()) {
      if ( fileInput.eof()) {
        cout << "End of the file!" << std::endl;
      } else {
        cout << "Unknown error!" << std::endl;
      }
      exit(1);
    }
  }

  cout << endl;

  fileInput.close();
  fileOutput.close();
  return 0;
}

