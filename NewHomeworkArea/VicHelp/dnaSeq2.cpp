//C++ SOURCE CODE:

/*CovidDNASequence2.cpp: This Program Calculates The Amount, Percentage, 
	and Type of Nucleotides from a Given Input File of a DNA Sequence 
	(Covid Strain) and Outputs it into an Output File*/
//Name: Victor Sim
//Class Section: Online COSC 1436 (Programming Fundamentals 1)
//Date: 11/6/21

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

int counting(string filename, int& sumNucleotides, int& countAdenine, int& countThymine, int& countCytosine, int& countGuanine) {

	char charPlaceholder = 'z';
	ifstream fileInputted;
	fileInputted.open(filename);
	if (fileInputted.fail()) {
		cout << "Error: in opening input file\n";
		return false;
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

void formatLine(ostream& output, double countNucleotides, int amountOfSpecificNucleotide, char abbrevNucleotide) {

	const double PERCENTAGE_MAKER = 100.00;
	string nucleotide;
	int countOfSpecificNucleotide = 0;
	const int TWO_DECIMAL_FORMATTER(2);
	const int WIDTH_FORMAT_ONE = 7;
	const int WIDTH_FORMAT_TWO = 6;
	const int WIDTH_FORMAT_THREE = 5;
	const int WIDTH_FORMAT_FOUR = 4;

	if(abbrevNucleotide == 'A')
	{
		nucleotide = "Adenine";
		countOfSpecificNucleotide = amountOfSpecificNucleotide;
	}
	else if(abbrevNucleotide =='T')
	{
		nucleotide = "Thymine";
		countOfSpecificNucleotide = amountOfSpecificNucleotide;
	}
	else if(abbrevNucleotide == 'C')
	{
		nucleotide = "Cytosine";
		countOfSpecificNucleotide = amountOfSpecificNucleotide;
	}
	else if(abbrevNucleotide =='G')
	{
		nucleotide = "Guanine";
		countOfSpecificNucleotide = amountOfSpecificNucleotide;
	}

	if(nucleotide == "Adenine" || nucleotide == "Thymine" || nucleotide == "Guanine" ) { 
		output << nucleotide << ":  " << setw(WIDTH_FORMAT_ONE) << left << countOfSpecificNucleotide << "\t";

		output << fixed << setprecision(TWO_DECIMAL_FORMATTER) << countOfSpecificNucleotide / countNucleotides * PERCENTAGE_MAKER  <<"%\n";

		cout << nucleotide << ":  " << setw(12) << left << countOfSpecificNucleotide;

		cout << fixed << setprecision(TWO_DECIMAL_FORMATTER) << countOfSpecificNucleotide / countNucleotides * PERCENTAGE_MAKER  <<"%\n";
	}
	else if(nucleotide == "Cytosine") {
		output << nucleotide << ": " << setw(WIDTH_FORMAT_TWO) << left << countOfSpecificNucleotide << "\t" << fixed << setprecision(TWO_DECIMAL_FORMATTER) << countOfSpecificNucleotide / countNucleotides * PERCENTAGE_MAKER  <<"%\n";

		cout << nucleotide << ": " << setw(11) << left << countOfSpecificNucleotide << "\t" << fixed << setprecision(TWO_DECIMAL_FORMATTER) << countOfSpecificNucleotide / countNucleotides * PERCENTAGE_MAKER  <<"%\n";
	}
}

void outputReport (ostream& outputFile, int sumNucleotides, int countAdenine, int countThymine, int countCytosine, int countGuanine) {

	char abbrevNucleotide;
	outputFile << "DNA sequence analysis:\n" << sumNucleotides <<" nucleotides in the sentence.\n";
	outputFile << "\nSequence breakdown:\n";
	cout << "DNA sequence analysis:\n" << sumNucleotides <<" nucleotides in the sentence.\n";
	cout << "\nSequence breakdown:\n";
	formatLine(outputFile, sumNucleotides, countAdenine, abbrevNucleotide = 'A');
	formatLine(outputFile, sumNucleotides, countThymine, abbrevNucleotide = 'T');
	formatLine(outputFile, sumNucleotides, countCytosine, abbrevNucleotide = 'C');
	formatLine(outputFile, sumNucleotides, countGuanine, abbrevNucleotide = 'G');

}

int main() {
	int sumNucleotides = 0;
	int countAdenine = 0;
	int countThymine = 0;
	int countCytosine = 0;
	int countGuanine = 0;

	ofstream outputFile;
	outputFile.open("covid_output.txt");

	counting("dnaSequence.txt", sumNucleotides, countAdenine, countThymine, countCytosine, countGuanine);

	outputReport(outputFile, sumNucleotides, countAdenine, countThymine, countCytosine, countGuanine);

	outputFile.close();



	return 0;
}
