#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int readFunction(char readArray[], int arraySize, ifstream& file)
{
  int counter = 0;

  for (int i = 0; i < arraySize; i++)
  {
    file >> readArray[i];

    if (file.eof())
    {
      break;
    }
    counter++;
  }
  return counter;
}

void displayFunction(char answers[], char studentAns[], double correctCount)
{
  double grade;
  double incorrectCount = 0;
  for (int i = 0; i < correctCount; i++)
  {
    if (answers[i] != studentAns[i])
    {
      cout << "Question " << i + 1 << " has incorrect answer " << "'" << studentAns[i] << "'," << " the correct answer is " << "'" << answers[i] << "'" << endl;
      incorrectCount++;
    }
  }

  grade = ((incorrectCount * 100) / correctCount);
  grade = 100 - grade;
  cout << incorrectCount << " questions were missed out of " << correctCount << endl;
  cout << fixed << setprecision(1) << "The student grade is " << grade << "%" << endl;

  if (grade < 70)
  {
    cout << "The student failed" << endl;
  }
  else
  {
    cout << "The student passed" << endl;
  }
}


int main()
{
  const int ARRAY_SIZE = 30;
  int studentCount;
  int answerCount;
  char answers[ARRAY_SIZE];
  char studentAns[ARRAY_SIZE];
  string sFile;
  string aFile;

  ifstream studentFile;
  ifstream answerFile;

  cout << "Enter student answers file name" << endl;
  cin >> sFile;

  studentFile.open(sFile);

  if (studentFile)
  {
    studentCount = readFunction(studentAns, 30, studentFile);
    cout << "Enter correct answer file name" << endl;
    cin >> aFile;
    answerFile.open(aFile);
    if (answerFile)
    {
      answerCount = readFunction(answers, 30, answerFile);

      if (studentCount != answerCount)
      {
        cout << "The student answers file has " << studentCount << " entries and the correct answers file has " << answerCount << " entries" << endl;
        cout << "Grading cannot be done if they are not the same" << endl;

        studentFile.close();
        answerFile.close();
        return 0;
      }

      if (studentCount == 0 && answerCount == 0)
      {
        cout << "The number of student answers and correct answers are both 0" << endl;
        cout << "No grade can be calculated" << endl;
        return 0;
      }

      displayFunction(answers, studentAns, answerCount);
    }
    else
    {
      cout << "File " << '"' << aFile << '"' << " could not be opened" << endl;
      return 0;
    }
  }
  else
  {
    cout << "File " << '"' << sFile << '"' << " could not be opened" << endl;
    return 0;
  }

  studentFile.close();
  answerFile.close();


  return 0;
}
