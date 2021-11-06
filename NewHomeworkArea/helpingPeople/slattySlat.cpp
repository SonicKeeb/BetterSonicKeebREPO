#include <iostream>
#include <iomanip>
using namespace std;

// Display safest region
int getChoice() {
  int choice;
  cout << "Menu" << endl;
  cout << "----" << endl;
  cout << "1->Diplay safest region, 2->Display least safe region, 3->Display all" << endl;
  cin >> choice;
  if (choice < 1 || choice > 3) {
    cout << "You entered " << choice << endl;
    cout << "Invalid Choice" << endl;
    return -1;
  }
    cout << "You entered " << choice << endl;
  return choice;
}

void getAccidentStats(double& north, double& south, double& east, double& west) {

  cout << "Enter the accident stats for the North region: ";
  cin >> north;
  if (north < 0 || north > 1) {
    exit(EXIT_FAILURE);
  } else {
    cout << "Accident stats entered for North region is " << north << endl;
  }

  cout << "Enter the accident stats for the South region: ";
  cin >> south;
  if (south < 0 || south > 1) {
    exit(EXIT_FAILURE);
  } else {
    cout << "Accident stats entered for sout region is " << south << endl;
  }

  cout << "Enter the accident stats for the East region: ";
  cin >> east;
  if (east < 0 || east > 1) {
    exit(EXIT_FAILURE);
  } else {
    cout << "Accident stats entered for east region is " << east << endl;
  }

  cout << "Enter the accident stats for the West region: ";
  cin >> west;
  if (west < 0 || west > 1) {
    exit(EXIT_FAILURE);
  } else {
    cout << "Accident stats entered for West region is " << west << endl;
  }
}

void findSafest(double& north, double& south, double& east, double& west) {

  double safest;

  if (north < south && north < east && north < west) {
    safest = north;
    cout << "Region north is the safest, with " << north << " accidents per capita" << endl;
  } else if (south < north && south < east && south < west) {
    safest = south;
    cout << "Region south is the safest, with " << south << " accidents per capita" << endl;
  } else if (east < north && east < south && east < west) {
    safest = east;
    cout << "Region east is the safest, with " << east << " accidents per capita" << endl;
  } else {
    safest = west;
    cout << "Region west is the safest, with " << west << " accidents per capita" << endl;
  }
}

void findLeastSafe(double& north, double& south, double& east, double& west) {

  double leastSafe;

   if (north > south && north > east && north > west) {
    leastSafe = north;
    cout << "Region north is the least safe, with " << north << " accidents per capita" << endl;
  } else if (south > north && south > east && south > west) {
    leastSafe = south;
    cout << "Region south is the least safe, with " << south << " accidents per capita" << endl;
  } else if (east > north && east > south && east > west) {
    leastSafe = east;
    cout << "Region east is the least safe, with " << east << " accidents per capita" << endl;
  } else {
    leastSafe = west;
    cout << "Region west is the least safe, with " << west << " accidents per capita" << endl;
  }
}

void displayAll(double& north, double& south, double& east, double& west) {
  cout << "North region has " << north << " accidents per capita" << endl;
  cout << "South region has " << south << " accidents per capita" << endl;
  cout << "East region has " << east << " accidents per capita" << endl;
  cout << "West region has " << west << " accidents per capita" << endl;
}

int main() {

  double north, south, east, west;
  int choice;

  getAccidentStats(north, south, east, west);
  cout << endl << endl;

  choice = getChoice();

  if (choice == 1) {
    findSafest(north, south, east, west);
  } else if (choice == 2) {
    findLeastSafe(north, south, east, west);
  } else {
    displayAll(north, south, east, west);
  }

  cout << "Exiting" << endl;

  return 0;
}
