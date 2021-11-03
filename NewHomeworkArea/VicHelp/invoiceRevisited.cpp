//Invoice.cpp: This program calculates the Grocery Invoice from given inputs
//Name: Victor Sim
//Class Section: Online COSC 1436 (Programming Fundamentals 1)
//Date: 9/25/21
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

// Bread, Milk, Soap, Eggs, Deodorant, Juice, Chips, Forks, Spoons, and Cups, 

  int itemDecision (int& decision) {
    cin >> decision;
    string decisionString = "";
    switch (decision) {
      case 1:
        decisionString = "Bread";
        cout << decisionString << endl;
       break;
      case 2:
        decisionString = "Milk";
        break;
      case 3:
        decisionString = "Soap";
        break;
      case 4:
        decisionString = "Eggs";
        break;
      case 5:
        decisionString = "Deoderant";
        break;
      case 6:
        decisionString = "Juice";
        break;
      case 7:
        decisionString = "Chips";
        break;
      case 8:
        decisionString = "Forks";
        break;
      case 9:
        decisionString = "Spoons";
        break;
      case 10:
        decisionString = "Cups";
        break;
      default:
        decisionString = "Error not valid number";
    }

    return decision;
    cout << endl;

  }

  double priceInput (double& price) {
    cin >> price;
    return price;
  }

  // It is true if it is taxable and false if not taxable
  // Oct 31: The check does work indeed but the return values don't say true or false but they do work

  int taxableCheck (int decision) {
    double allTax = 1;
    switch (decision) {
      case 1:
        return 0;
        break;
      case 2:
        return 0;
        break;
      case 3:
        allTax = 0.08;
        return 1;
        break;
      case 4:
        return 0;
        break;
      case 5:
        return 1;
        allTax = 0.08;
        break;
      case 6:
        return 0;
        break;
      case 7:
        return 0;
        break;
      case 8:
        allTax = 0.08;
        return 1;
        break;
      case 9:
        allTax = 0.08;
        return 1;
        break;
      case 10:
        allTax = 0.08;
        return 1;
        break;
      default:
        cout << "failure" << endl;
        }
        return allTax;
  }

  int age (int& ageInput) {
    double discount;
    cin >> ageInput;
    if (ageInput >= 60) {
      discount = 0.05;
    } else {
      discount = 0;
    }
    return discount;
  }

  double invoice () {
    return priceInput(price) + (priceInput(price) * taxableCheck(decision)) - (priceInput(price) * age(ageInput));
  }

  int main() {

  int decision;
  int ageInput;
  double price;

  while (decision < 1) {
  if (decision < 1 || decision > 10) {
    cout << "What would you like to buy?" << endl;
    cout << "1. Bread\n2. Milk\n3. Soap\n4. Eggs:\n5. Deodorant:\n6. Juice:\n7. Chips:\n8. Forks:\n9. Spoons:\n10. Cups:" << endl;
    cout << "Please enter your choice: ";
    taxableCheck(itemDecision(decision));
  } else {
    break;
  }
  }
  

  cout << "Please enter the price: $: ";
  priceInput(price);
  
  while (price <= 0) {
    cout << "Please enter the price: $: ";
    priceInput(price);
    cout << endl;
  }

  cout << "Please enter age: ";
  age(ageInput);

  while (ageInput) {
    if (ageInput == 0 || ageInput < 1 || ageInput > 119) {
    cout << "Please enter the age: ";
    age(ageInput);
    cout << endl;
    } else {
      break;
    }
  }

  invoice(decision, price, ageInput);

/*  //Declaring Variables

  int decision = 0;
  int age = 0;
  double price = 0.00; 
  double tax = 0.00;
  double discount = 0.00;
  double finalTotal = 0.00;
  const double taxRate = 0.08;
  const double discountRate = 0.05;

  //User input for choice + prompt

  cout << "What would you like to buy?" << endl;
  cout << "1. Bread\n2. Milk\n3. Soap" << endl;
  cout << "Please enter your choice: ";
  cin >> decision;

  //error checking
  if (decision < 1 || decision > 3) {
    cout << "Sorry, " << decision << " wasn't a valid choice";
    return -1;
  }

  //User input for price + prompt

  cout << "Please enter the price: $";
  cin >> price;

  //User input for age + prompt

  cout << "Please enter your age: ";
  cin >> age;

  //Generation of Invoice Title

  cout << endl  << setw(15) << "Invoice" << endl;


  if (decision == 3) {
    tax = taxRate * price;
  }

  //Condition Calculation for Uniquely Taxed Good

  finalTotal = price + tax;

  //Condition Calculation for Unique Circumstance - Old Age.

  if (age >= 60) {
    discount = discountRate * finalTotal;
  }

  //Generation of Rest of nclude <iostream>
  Invoice
  finalTotal -= discount;

  cout << setprecision(2) << fixed << "Price:" << setw(10) << "$" << price << endl;
  cout << setprecision(2) << fixed <<"Tax:" << setw(12) << "$" << tax << endl;

  if(age >= 60) {
    cout << setprecision(2) << fixed << "Discount:" << setw(8) << "$-" << discount << endl;
  }

  cout << setprecision(2) << fixed << "Total:" << setw(10) << "$" << finalTotal << endl;
  */

  return 0;
}


