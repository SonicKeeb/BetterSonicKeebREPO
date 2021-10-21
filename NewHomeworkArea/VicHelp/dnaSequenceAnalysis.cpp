#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

  int countTotal, countAdenine, countThymine, countCytosine, countGuanine = 0;
  double adeninePercent, thyminePercent, cytosinePercent, guaninePercent;

  ifstream fileInput;
  fileInput.open("dnaSequence.txt");
  if ( !fileInput.is_open()) {
    cerr << "File didn't open!" << std::endl;
    exit(2);
  }

  ofstream fileOutput;
  fileOutput.open("FileToWrite.txt");
  if ( !fileOutput.is_open()) {
    cerr << "Output file didn't open!" << endl;
    exit(1);
  }

  string dnaSequence;
//  getline(fileInput, dnaSequence);

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

    if (fileInput.fail()) {
      if (fileInput.eof()) {
        fileOutput << "End of the file!" << endl;
      } else {
        fileOutput << "Unkown Error!" << endl;
      }
      exit(1);
    }
  }
  fileOutput << endl;

  fileOutput << "DNA sequence analysis:" << endl;
  fileOutput << countTotal << " nucleotides in the sequence" << endl;
  fileOutput << endl << endl;
  fileOutput << "Sequence breakdown:" << endl;
  fileOutput << "Adenine:   " << countAdenine << setw(12) << fixed << setprecision(2) << double(double(countAdenine) / double(countTotal)) * 100.00 << "%" << endl;
  fileOutput << "Thymine:   " << countThymine << setw(12) << fixed << setprecision(2) << double(double(countThymine) / double(countTotal)) * 100.00 << "%" << endl;
  fileOutput << "Cytosine:  " << countCytosine << setw(12) << fixed << setprecision(2) << double(double(countCytosine) / double(countTotal)) * 100.00 << "%" << endl;
  fileOutput << "Guanine:   " << countGuanine << setw(12) << fixed << setprecision(2) << double(double(countCytosine) / double(countTotal)) * 100.00 << "%" << endl;



  fileOutput << dnaSequence;

  if ( fileOutput.fail()) {
    fileOutput << "Writing to output file failed!" << endl;
    exit(1);
  }

  fileInput.close();
  fileOutput.close();

  return 0;
}
