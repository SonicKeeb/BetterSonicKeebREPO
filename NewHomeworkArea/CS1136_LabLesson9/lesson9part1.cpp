#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

void read(int& ordered, int& stock, double& shipHand);
void display(int ordered, int stock, double shipHand);

int main() {
  int ordered, stock;
  double shipHand;
  read(ordered, stock, shipHand);
  display(ordered, stock, shipHand);
  return 0;
}

void read(int& ordered, int& stock, double& shipHand) {
  cout << "Spools to be ordered" << endl;
  while (cin >> ordered) {
    if (ordered < 1) {
      cout << "Spools order must be 1 or more" << endl;
      cout << "Spools to be ordered" << endl;
    } else {
      break;
    }
  }
  cout << "Spools in stock" << endl;
  while (cin >> stock) {
    if (stock < 0) {
      cout << "Spools in stock must be 0 or more" << endl;
      cout << "Spools in stock" << endl;
    } else {
      break;
    }
  }
  char choice;
  cout << "Special shipping and handling (y or n)" << endl;
  cin >> choice;
  if (choice == 'n') {
  shipHand = 12.99;
  } else if (choice == 'y') {
    cout << "Shipping and handling amount" << endl;
    while (cin >> shipHand) {
      if (shipHand < 0) {
        cout << "The spool shipping and handling charge must be 0.0 or more" << endl;
        cout <<"Shipping and handling amount" << endl;
      } else {
        break;
      }
    }
  }
}

void display(int ordered, int stock, double shipHand) {
  double spoolCost = 104;
  int ready;
  int backOrder;

  if (ordered > stock) {
    ready = stock;
    backOrder = ordered - stock;
  } else {
    ready = ordered;
    backOrder = ordered - stock;
  }

  if (backOrder < 0) {
    backOrder = 0;
  }

  cout << "Spools ready to ship: " << ready << endl;
  cout << "Spools on back-order: " << backOrder << endl;
  cout << fixed << setprecision(2);
  cout << "Subtotal ready to ship: $" << setw(10) << right << spoolCost * ready << endl;
  cout << "Shipping and handling:  $" << setw(10) << right << shipHand * ready << endl;
  cout << "Total shipping charges: $" << setw(10) << right << (spoolCost * ready) + (shipHand * ready) << endl;
}
