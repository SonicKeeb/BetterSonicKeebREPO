#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {

  const int SIZE = 50;
  double grade[SIZE];
  string first[SIZE];
  string last[SIZE];
  string temp;
  int course[SIZE];

  ifstream inputFile;
  inputFile.open("roster.txt");
  if (!inputFile.is_open()) {
    cout << "File could not be opened" << endl;
    return -1;
    }
  inputFile.close();

  int loop = 0;
  inputFile.open("roster.txt");
  if (inputFile.is_open()) {
    while(!(inputFile.eof())) {
      inputFile >> temp >> first[loop] >> temp >> last[loop] >> temp >> course[loop] 
                >> temp >> grade[loop];
      loop++;
      }
    }
  inputFile.close();

  bool swap;
  do {
    swap = false;
    for (int i = 0; i < loop; i++) {
      if (course[i] > course[i+1]){
        swap = true;
        int temp = course[i];
        course[i] = course[i+1];
        course[i+1] = temp;
        string temporary = first[i];
        first[i] = first[i+1];
        first[i+1] = temporary;
        double tempor = grade[i];
        grade[i] = grade[i+1];
        grade[i+1] = tempor;
        }
      }
    } while(swap);

  cout << "FIRST_NAME\t" << "LAST_NAME\t" << "COURSE_NUMBER\t" << " GRADE" 
       << endl;

  for (int i = 0; i < loop; i++) { // The spacing in the strings with tabs is to help with formatting
    cout << fixed << setprecision(2) << first[i] << "\t    " // 5 spaces
         << last[i] << "\t    " //4 spaces
         << course[i] << "        \t" // 8 spaces
         << showpos << grade[i] << noshowpos
         << endl;
    }
  }


