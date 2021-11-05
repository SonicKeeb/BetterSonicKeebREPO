#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//double average (int& test1, int& test2, int& test3);
//char getLetterGrade (double avg, int test3);
//bool getScore (int& testScore, int& testScore, int& testScore3);

double average (int test1, int test2, int test3) {

  cout << fixed << setprecision(1);

  double average;
  average = (test1 + test2 + test3) / 3.0;
  cout << average << endl;
  return average;
}

char getLetterGrade (double avg, int test3) {
  char grade;

  if (avg >= 90) {
    grade = 'A';
  }

  if (avg >= 80 && avg < 90) {
    if (test3 >= 95) {
      grade = 'A';
    } else {
      grade = 'B';
    }
  }

  if (avg >= 70 && avg < 80) {
    if (test3 >= 85) {
      grade = 'B';
    } else {
      grade = 'C';
    }
  }

  if (avg >= 60 && avg < 70) {
    if (test3 >= 75) {
      grade = 'C';
    } else {
      grade = 'D';
    }
  }
  return grade;
}

bool getScore (int& testScore) {
  bool valid;

  cout << endl;
  cin >> testScore;

  if (testScore < 0 || testScore > 100) {
    cout << "The score entered is invalid, the valid range is 0 - 100" << endl;
    valid = false;
  } else {
    valid = true;
  }
  return valid;
}

int main() {
  int firstTest, secondTest, thirdTest;
  bool validCheck1 = getScore(firstTest);

  if (validCheck1) {
    bool validCheck2 = getScore(secondTest);
    if (validCheck2) {
      bool validCheck3 = getScore(thirdTest);
      if (validCheck3) {
        cout << getLetterGrade(average(firstTest, secondTest, thirdTest), thirdTest) << endl;
      }
    }
  }
  return 0;
}
