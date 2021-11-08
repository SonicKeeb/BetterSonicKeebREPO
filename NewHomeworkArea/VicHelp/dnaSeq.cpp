/*CovidDNASequence.cpp: This Program Calculates The Amount, Percentage, 
  and Type of Nucleotides from a Given Input File of a DNA Sequence 
  (Covid Strain) and Outputs it into an Output File*/
//Name: Victor Sim
//Class Section: Online COSC 1436 (Programming Fundamentals 1)
//Date: 10/23/21

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
  /*Variables and Constants Initialized and Declared*/
  int sumNucleotides = 0;
  int countAdenine = 0;
  int countThymine = 0;
  int countCytosine = 0;
  int countGuanine = 0;
  char charPlaceholder = 'z';
  const int PERCENTAGE_MAKER = 100;
  const int WIDTH_FORMAT = 11;

  /*Input Stream Object Declared*/
  ifstream fileInputted;

  /*Input File Opened in Input Stream*/
  fileInputted.open("dnaSequence.txt");

  /*Error Checking If Input File is Opened or Not*/
  if(fileInputted.fail()) {
    /*Console Outputs Error Message and Terminates Program If File is Not Opened*/
    cout << "Error: in opening input file\n";
    return -1;
  }

  /*While Loop to Read Each Character Until There is No More*/
  while(fileInputted >> charPlaceholder) {

    /*If The Char is an A, Increment count for Adenine and count for Total*/ 
    if(charPlaceholder == 'A') {
      countAdenine++;
      sumNucleotides++;
    }

    /*If The Char is an T, Increment count for Thymine and count for Total*/
    else if(charPlaceholder == 'T') {
      countThymine++;
      sumNucleotides++;
    }

    /*If The Char is an C, Increment count for Cytosine and count for Total*/
    else if(charPlaceholder == 'C') {
      countCytosine++;
      sumNucleotides++;
    }

    /*If The Char is an G, Increment count for Guanine and count for Total*/
    else if(charPlaceholder == 'G') { 
      countGuanine++;
      sumNucleotides++;
    } else { /*If Other Chars are found, it will print an error message*/ 
      cout << "Error: " << charPlaceholder << " is not a valid character\n";
    }
  }

  /*Input file Closed to Save Resources After It's Read Usage*/
  fileInputted.close();

  /*Console Output*/
  cout << "DNA sequence analysis:\n";
  cout << sumNucleotides << " nucleotides in the sequence\n";
  cout << "\nSequence breakdown:\n";
  cout << left << "Adenine:  " << setw(WIDTH_FORMAT) << fixed << setprecision(2) << left << countAdenine << ((double)countAdenine / sumNucleotides) * PERCENTAGE_MAKER << "%\n";
  cout << left << "Thymine:  " << setw(WIDTH_FORMAT) << fixed << setprecision(2) << left << countThymine << ((double)countThymine / sumNucleotides) * PERCENTAGE_MAKER << "%\n";
  cout << left << "Cytosine: " << setw(WIDTH_FORMAT) << fixed << setprecision(2) << left << countCytosine << ((double)countCytosine / sumNucleotides) * PERCENTAGE_MAKER<< "%\n";
  cout << left << "Guanine:  " << setw(WIDTH_FORMAT) << fixed << setprecision(2) << left << countGuanine << ((double)countGuanine / sumNucleotides) * PERCENTAGE_MAKER << "%\n";

  /*Object of Output Stream Declared*/
  ofstream fileOutputted;

  /*Output Object File Opened in Output Stream*/
  fileOutputted.open("covid_output.txt");

  /*Error Checking If Output File is Opened or Not*/
  if(fileOutputted.fail()) {
    /*print error message and quit program*/
    cout << "Error in opening output file\n";
    return -1;
  }

  /*Result written into the Output File*/
  fileOutputted << "DNA sequence analysis:\n";
  fileOutputted << sumNucleotides << " nucleotides in the sequence\n";
  fileOutputted << "\nSequence breakdown:\n";
  fileOutputted << left << "Adenine:  " << setw(WIDTH_FORMAT) << fixed << setprecision(2) << left << countAdenine << ((double)countAdenine / sumNucleotides) * PERCENTAGE_MAKER << "%\n";
  fileOutputted << left << "Thymine:  " << setw(WIDTH_FORMAT) << fixed << setprecision(2) << left << countThymine << ((double)countThymine / sumNucleotides) * PERCENTAGE_MAKER << "%\n";
  fileOutputted << left << "Cytosine: " << setw(WIDTH_FORMAT) << fixed << setprecision(2) << left << countCytosine << ((double)countCytosine / sumNucleotides) * PERCENTAGE_MAKER << "%\n";
  fileOutputted << left << "Guanine:  " << setw(WIDTH_FORMAT) << fixed << setprecision(2) << left << countGuanine << ((double)countGuanine / sumNucleotides) * PERCENTAGE_MAKER << "%\n";

  /*closing file*/ 
  fileOutputted.close(); 

  return 0;
}
