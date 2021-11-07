#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

int sumNucleotides = 0;
int countAdenine = 0;
int countThymine = 0;
int countCytosine = 0;
int countGuanine = 0;
char charPlaceholder = 'z';
const double PERCENTAGE_MAKER = 100;
const int WIDTH_FORMAT = 11;

bool counting() {

  ifstream fileInputted;
  fileInputted.open("dnaSequence.txt");
  if (fileInputted.fail()) {
    cout << "Error: in opening input file\n";
    return -1;
  }

  while (fileInputted >> charPlaceholder) {
    if (charPlaceholder == 'A') { /*If The Char is an A, Increment count for Adenine and count for Total*/
      countAdenine++;
      sumNucleotides++;
    } else if (charPlaceholder == 'T') { /*If the Char is an T, Increament count for Thymine and count for Total*/
      countThymine++;
      sumNucleotides++;
    } else if (charPlaceholder == 'C') { /*If The Char is an C, Increment count for Cytosine and count for Total*/
      countCytosine++;
      sumNucleotides++;
    } else if (charPlaceholder == 'G') { /*If The Char is an G, Increment count for Guanine and count for Total*/
      countGuanine++;
      sumNucleotides++;
    } else { /*If Other Chars are found, it will print an error message*/ 
      cout << "Error: " << charPlaceholder << " is not a valid character\n";
      return false;
    }
  }


fileInputted.close(); 
return true;

}

void format (ostream& output) {

  output << fixed << setprecision(2);

  output << setw(15) << left << setw(10) << left;
  output << setw(15) << left << setw(10) << left;
  output << setw(15) << left << setw(10) << left;
  output << setw(15) << left << setw(10) << left;

}

void report (ostream& output) {

  output <<"DNA sequence analysis:\n";
  output << sumNucleotides << setw(6) << left << " nucleotides in the sequence\n";
  output <<"\nSequence breakdown:\n"; 
  output << "Adenine: " << countAdenine << " " << setw(7) << left << (double(countAdenine) / double(sumNucleotides)) * PERCENTAGE_MAKER << endl;   
  output << "Thymine: " << countThymine << " " << setw(7) << left << (double(countThymine) / double(sumNucleotides)) * PERCENTAGE_MAKER << endl;
  output << "Cytosine: " << countCytosine << " " << setw(7) << left << (double(countCytosine) / double(sumNucleotides)) * PERCENTAGE_MAKER << endl;
  output << "Guanine: " << countGuanine << " " << setw(7) << left << (double(countGuanine) / double(sumNucleotides)) * PERCENTAGE_MAKER << endl;

}

int main() {


  ofstream output;
  output.open("FileToWrite.txt");
  if (!output) {
    cout << "Error in opening output file\n";
    exit(0);
  }

  counting();
  format(output);
  report(output);

  return 0;
}

