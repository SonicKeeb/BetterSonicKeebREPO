/*ICA 2-28-2022
        Example 2: 
        Assume an input file with the following data structure is given(users.txt):
        <int> <string> <double>

        Where
        int is the id (>0)
        string is the username
        double is the GPA

        Assume that there are no more than 100 enteries in the input file

        a) Define an structure user to store the info of one student
        b) Define an array to store up to 100 elements of the user data type
        c) Read the input file into the array of b)
        d) Display the data as a table and use precision 2 for GPA
        e) Find the average GPA
        f) Display all the students with the GPA >= average_gpa

        e.g.

        1234 axs210087 4.0
        5453 fsnfnvd32 3.7
        2345 oqfowre244 2.6
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;


int main() {
  
  struct user {
  int id;
  string username;
  double gpa;
  } stuff[100];
  
  ifstream inputFile;
  inputFile.open("users.txt");
  if (!inputFile.is_open()) {
    cout << "File could not be opened" << endl;
    return -1;
    } 
  int count = 0;
  while (!inputFile.eof()) {
    inputFile >> stuff[count].id >> stuff[count].username >> stuff[count].gpa;
    count++;
  }
  inputFile.close();
  
  int endline = 0;

  for (int i = 0; i < count; i++) {
  cout << stuff[i].id << "\t" << stuff[i].username << "\t" << fixed 
       << setprecision(2) << stuff[i].gpa;
  if (count % 3 == 0) {
    cout << endl;
  }
}
  double sum = 0;
  for (int i = 0; i < count; i++) {
    sum += stuff[i].gpa;
  }
  cout << endl;
  cout << "Average: " << sum / 3.0 << endl << endl;

  for (int i = 0; i < count-1; i++) {
    cout << stuff[i].id << "\t" << stuff[i].username << "\t" << fixed 
         << setprecision(2) << stuff[i].gpa;
  if (count % 3 == 0) {
    cout << endl;
  }
  }
  
  return 0;
}
