nclude <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int main() {
  /* TODO: Declare any necessary variables here. */

  double midterm1;
  double midterm2;
  double final;
  double counter = 0;
  int studentAvg;
  double midterm1Avg = 0;
  double midterm2Avg = 0;
  double finalAvg = 0;
  char letterGrade;
  string fileName;
  string firstName;
  string lastName;
  ifstream inputFile;
  ofstream outputFile;


  /* TODO: Read a file name from the user and read the tsv file here. */

  cin >> fileName;

  inputFile.open(fileName);
  outputFile.open("report.txt");

  while (inputFile)
  {

    inputFile >> firstName;
    inputFile >> lastName;
    inputFile >> midterm1;
    inputFile >> midterm2;
    inputFile >> final;

    if (inputFile.eof())
    {
      break;
    }

    midterm1Avg = midterm1Avg + midterm1;
    midterm2Avg = midterm2Avg + midterm2;
    finalAvg = finalAvg + final;

    studentAvg = (midterm1 + midterm2 + final) / 3;

    if (studentAvg >= 90)
    {
      letterGrade  = 'A';
    }
    else if (studentAvg >= 80 && studentAvg < 90)
    {
      letterGrade  = 'B';
    }
    else if (studentAvg >= 70 && studentAvg < 80)
    {
      letterGrade  = 'C';
    }
    else if (studentAvg >= 60 && studentAvg < 70)
    {
      letterGrade  = 'D';
    }
    else if (studentAvg < 60)
    {
      letterGrade  = 'F';
    }
    counter++;
    outputFile << firstName  << '\t' << lastName << '\t' << midterm1 << '\t' << midterm2 << '\t' << final << '\t' << letterGrade << endl;

  }

  midterm1Avg = midterm1Avg / counter;
  midterm2Avg = midterm2Avg / counter;
  finalAvg = finalAvg / counter;

  outputFile << '\n';
  outputFile << fixed << setprecision(2);
  outputFile << "Averages: midterm1 " << midterm1Avg << ", midterm2 " << midterm2Avg << ", final " << finalAvg << endl;

  return 0;
}
