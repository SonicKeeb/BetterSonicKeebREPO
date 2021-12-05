#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

  int index = 0;
  string fileName;
  string category;
  string name;
  string food;
  string description;
  string availability;
  int tab;
  int tab1;
  int tab2;
  ifstream inputFile;
  cin >> fileName;

  inputFile.open(fileName);

  while(inputFile)
  {
    if (inputFile.eof())
    {
      break;  
    }

    getline(inputFile, food);

    tab = food.find('\t');

    category = food.substr(index, tab);

    tab1 = food.find('\t', tab + 1);      
    name = food.substr(tab + 1, tab1 - tab - 1);

    tab2 = food.find('\t', tab1 + 1);        
    description = food.substr(tab1 + 1, tab2 - tab1 - 1);

    availability = food.substr(tab2 + 1);

    if (availability != "Available")
    {
      continue;
    }

    cout << name << " " << '(' << category << ')' << " " << "--" << " " << description << endl;      


  }

  return 0;
}
