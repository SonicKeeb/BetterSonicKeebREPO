#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

double maximumValue(double[], int);
double minimumValue(double[], int);

const int NUMBER_OF_JUDGES = 10;
const int MIN_SCORE = 0;
const int MAX_SCORE = 10;
const string FILE_NAME = "scorecard1.txt";
const int END_PROGRAM = 0;
const int TENTHS_PLACE = 1;
const int HUNDREDTHS_PLACE = 2;
const int SUBSCRIPT_ADJUSTMENT = 1;

int main() {
  string athleteFirstName;
  string athleteLastName;
  int amountOfScores = 0;
  double judgeScores[NUMBER_OF_JUDGES];

  ifstream inputFile;
  inputFile.open(FILE_NAME); 

  while(!inputFile){ 
    cout << "ERROR: the scorecard could not be opened" << endl;
    return 2;
  }

  if(inputFile >> athleteFirstName >> athleteLastName) {

  while (!inputFile.eof() && amountOfScores < NUMBER_OF_JUDGES)
  {
    inputFile >> judgeScores[amountOfScores];
    if(judgeScores[amountOfScores] > MAX_SCORE || judgeScores[amountOfScores] < MIN_SCORE){
      cout << "Invalid scores" << endl << athleteFirstName << " " << athleteLastName << " is disqualified" << endl;
      return 2;
    }
    amountOfScores++;
  }

  if(amountOfScores != NUMBER_OF_JUDGES){
    cout << "Insufficient scores" << endl << athleteFirstName << " " << athleteLastName  << " is disqualified" << endl;
    return 2;
  }
  }

  double lowestScore = minimumValue(judgeScores, amountOfScores);
  double highestScore = maximumValue(judgeScores, amountOfScores);

  cout << athleteFirstName << " " << athleteLastName << "'s results:" << endl;

  int specificScore = 0;
  double sumOfScores = 0;
  int countOfScore = 0;
  
  cout << fixed << setprecision(TENTHS_PLACE);
  
  for(; specificScore < amountOfScores; specificScore++){
    if(judgeScores[specificScore] != lowestScore && judgeScores[specificScore] != highestScore){
      sumOfScores += judgeScores[specificScore];
      countOfScore++;
    }
    if(specificScore != amountOfScores - SUBSCRIPT_ADJUSTMENT)
      cout << judgeScores[specificScore] << ", ";
    else
      cout << judgeScores[specificScore];
  }
  cout << endl << "The highest score of " << highestScore << " and the lowest score of "<< lowestScore << " were \n" << "dropped" << endl;
  cout << fixed << setprecision(HUNDREDTHS_PLACE) <<"The average score is " << sumOfScores / countOfScore << endl;
  inputFile.close();
  return END_PROGRAM;
}

double maximumValue(double judgeScores[], int scoreSize){
  int maximum = 0;
  int specificScore = 0;
  for(;specificScore < scoreSize; specificScore++){
    if(judgeScores[specificScore] > judgeScores[maximum]){
      maximum = specificScore;
    }
  }
  return judgeScores[maximum];
}

double minimumValue(double judgeScores[], int scoreSize){
  int minimum = 0;
  int specificScore = 0;
  for(;specificScore < scoreSize; specificScore++){
    if(judgeScores[specificScore] < judgeScores[minimum]){
      minimum = specificScore;
    }
  }
  return judgeScores[minimum];
}
