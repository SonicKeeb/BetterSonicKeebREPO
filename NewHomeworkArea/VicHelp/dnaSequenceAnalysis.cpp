#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

  // Declaration of variables
  int countTotal, countAdenine, countThymine, countCytosine, countGuanine = 0;
  // Declaration of opening input Textfile and opening empty output file

  ifstream fileInput;
  fileInput.open("dnaSequence.txt");
  if ( !fileInput.is_open()) {
    cerr << "File didn't open!" << endl;
    exit(2);
  }

  ofstream fileOutput;
  fileOutput.open("FileToWrite.txt");
  if ( !fileOutput.is_open()) {
    cerr << "Output file didn't open!" << endl;
    exit(1);
  }

  // Delcaring dnaSequence as a string to become all the inputted characters in the textfile

  string dnaSequence;

  // While loop iterates whenever there are still characters in the text file and 
  // for every character (for loop goes through each index) the total count goes up each iteration
  // and the same happens for the specific counters of the bases if at that index is a valid
  // character.

  while(getline(fileInput, dnaSequence)) {
    for(int i = 0; i < dnaSequence.length(); i++) {
      countTotal++;
      if (dnaSequence[i] == 'A') {
        countAdenine++;
      } else if (dnaSequence[i] == 'T') {
        countThymine++;
      } else if (dnaSequence[i] == 'C') {
        countCytosine++;
      } else if (dnaSequence[i] == 'G') {
        countGuanine++;
      } else {
        fileOutput << i << " error" << endl;
      }
    }  

    if (fileInput.fail()) { // If the file fails and it is the end of the file exit
      if (fileInput.eof()) {
        fileOutput << "End of the file!" << endl;
      } else {
        fileOutput << "Unkown Error!" << endl;
      }
      exit(1);
    }
  }

  // Output all the calculation and prompt statements into fileOutput (the file is already open and 
  // fileOutput is the name of "FileToWrite.txt" which is currently an empty file until the program 
  // is run. 

  // Once the program has been run the output goes into the file as text

  fileOutput << endl;

  fileOutput << "DNA sequence analysis:" << endl;
  fileOutput << countTotal << " nucleotides in the sequence" << endl;
  fileOutput << endl << endl;
  fileOutput << "Sequence breakdown:" << endl;
  fileOutput << "Adenine:   " << countAdenine << setw(12) << fixed << setprecision(2) << double(double(countAdenine) / double(countTotal)) * 100.00 << "%" << endl;
  fileOutput << "Thymine:   " << countThymine << setw(12) << fixed << setprecision(2) << double(double(countThymine) / double(countTotal)) * 100.00 << "%" << endl;
  fileOutput << "Cytosine:  " << countCytosine << setw(12) << fixed << setprecision(2) << double(double(countCytosine) / double(countTotal)) * 100.00 << "%" << endl;
  fileOutput << "Guanine:   " << countGuanine << setw(12) << fixed << setprecision(2) << double(double(countGuanine) / double(countTotal)) * 100.00 << "%" << endl;

  // If the file fails to output then prompt this statement and exit

  if ( fileOutput.fail()) {
    fileOutput << "Writing to output file failed!" << endl;
    exit(1);
  }

  // Close the files both INPUT and OUTPUT

  fileInput.close();
  fileOutput.close();

  return 0; // End Program
}
