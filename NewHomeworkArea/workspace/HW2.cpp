#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

#define SIZE 1000

struct city {
  int id;
  char group;
  double x;
  double y;
  string name;
};

double distance(city cd[], int c1, int c2, int max) {
  for (int i = 0; i < max; i++) {
    if (cd[i].id == c1) {
      for (int j = 0; j < max; j++) {
        if (cd[j].id == c2) {
          cout << "The distance is: " << sqrt(((cd[j].x - cd[i].x) * (cd[j].x - cd[i].x)) + ((cd[j].y - cd[i].y) * (cd[j].y - cd[i].y))) << endl;
          return 0;
        }
      }
    }
  }
}

int main() {

  city cities[SIZE];

  ifstream inputFile;
  inputFile.open("cityinfo.txt");
  if (!inputFile.is_open()) {
    cout << "Error opening the file!" << endl;
    return -1;
  }
  int count = 0;
  string state[SIZE];
  while (!inputFile.eof()) {
    inputFile >> cities[count].id >> cities[count].group >> cities[count].x >> cities[count].y;
    getline(inputFile, cities[count].name);
    count++;
  }
  inputFile.close();

  cout << "Choose an option (Must be in LOWER CASE)" << endl;
  cout << "a. Display cities by ID range" << endl << "b. Display cities by group" <<
    endl << "c. Enter City 1" << endl << "d. Enter City 2" << endl << "e. Compute Distance" << endl <<
    "f. Exit" << endl;

  char choice;
  while (!(choice == 'a' || choice == 'b' || choice == 'c' || choice == 'd' || choice == 'e' || choice == 'f')) {
    cin >> choice;
    if (choice == 'a' || choice == 'b' || choice == 'c' || choice == 'd' || choice == 'e' || choice == 'f') {
      break;
    }
    if (choice == 'f') {
      exit(1);
    }
    cout << "invalid choice choose again" << endl;
  }

  //option a
  if (choice == 'a') {
    int max_id, min_id;
    do {
      cout << "input minimum and maximum ids: ";
      cin >> min_id >> max_id;
    } while (min_id > max_id || min_id <= 0 || 0 >= max_id);
    for (int i = 0; i < 500; i++) {
      if (cities[i].id >= min_id && cities[i].id <= max_id) {
        cout << left << setw(6) << cities[i].id << left << setw(8) << cities[i].group << left << setw(10) << fixed <<
          setprecision(2) << cities[i].x << left << setw(10) << fixed <<
          setprecision(2) << cities[i].y << left << setw(30) << cities[i].name << endl;
      }
    }
    cout << "Choose an option (Must be in LOWER CASE)" << endl;
    cout << "a. Display cities by ID range" << endl << "b. Display cities by group" <<
      endl << "c. Enter City 1" << endl << "d. Enter City 2" << endl << "e. Compute Distance" << endl <<
      "f. Exit" << endl;
  }

  //option b 
  if (choice == 'b') {
    char choiceChar;
    do {
      cout << "input group character, has to be from A-Z: " << endl;
      cin >> choiceChar;
    } while (!(choiceChar == 'A' || choiceChar == 'B' || choiceChar == 'C' || choiceChar == 'D' ||
        choiceChar == 'E' || choiceChar == 'F' || choiceChar == 'G' ||
        choiceChar == 'H' || choiceChar == 'I' || choiceChar == 'J' ||
        choiceChar == 'K' || choiceChar == 'L' || choiceChar == 'M' ||
        choiceChar == 'N' || choiceChar == 'O' || choiceChar == 'P' ||
        choiceChar == 'Q' || choiceChar == 'R' || choiceChar == 'S' ||
        choiceChar == 'T' || choiceChar == 'U' || choiceChar == 'V' ||
        choiceChar == 'W' || choiceChar == 'X' || choiceChar == 'Y' ||
        choiceChar == 'Z'));
    for (int i = 0; i < 1000; i++) {
      if (cities[i].group == choiceChar) {
        cout << left << setw(6) << cities[i].id << left << setw(8) << cities[i].group << left <<
          setw(10) << fixed << setprecision(2) << cities[i].x << left << setw(10) << fixed <<
          setprecision(2) << cities[i].y << left << setw(30) << cities[i].name << endl;
      }
    }
    cout << "Choose an option (Must be in LOWER CASE)" << endl;
    cout << "a. Display cities by ID range" << endl << "b. Display cities by group" <<
      endl << "c. Enter City 1" << endl << "d. Enter City 2" << endl << "e. Compute Distance" << endl <<
      "f. Exit" << endl;
  }

  int city1, city2;

  //option c
  if (choice == 'c') {
    cout << "Enter the value for city 1" << endl;
    cin >> city1;
    while (city1 == city2) {
      cout << "Values are the same enter a different value" << endl;
      cin >> city1;
    }
    cout << "Choose an option (Must be in LOWER CASE)" << endl;
    cout << "a. Display cities by ID range" << endl << "b. Display cities by group" <<
      endl << "c. Enter City 1" << endl << "d. Enter City 2" << endl << "e. Compute Distance" << endl <<
      "f. Exit" << endl;
  }

  //option d
  if (choice == 'd') {
    cout << "Enter the value for city 1" << endl;
    cin >> city2;
    while (city1 == city2) {
      cout << "Values are the same enter a different value" << endl;
      cin >> city2;
    }
    cout << "Choose an option (Must be in LOWER CASE)" << endl;
    cout << "a. Display cities by ID range" << endl << "b. Display cities by group" <<
      endl << "c. Enter City 1" << endl << "d. Enter City 2" << endl << "e. Compute Distance" << endl <<
      "f. Exit" << endl;
  }

  //option e
  if (choice == 'e') {
    while (city1 <= 0 || city1 == city2) {
      cout << "City1 value doesn't exist enter a value (positive)" << endl;
      cin >> city1;
    }
    while (city2 <= 0 || city1 == city2) {
      cout << "City2 value doesn't exist enter a value (positive)" << endl;
      cin >> city2;
    }
    distance(cities, city1, city2, 1000);
    cout << "Choose an option (Must be in LOWER CASE)" << endl;
    cout << "a. Display cities by ID range" << endl << "b. Display cities by group" <<
      endl << "c. Enter City 1" << endl << "d. Enter City 2" << endl << "e. Compute Distance" << endl <<
      "f. Exit" << endl;
  }

  return 0;
}
