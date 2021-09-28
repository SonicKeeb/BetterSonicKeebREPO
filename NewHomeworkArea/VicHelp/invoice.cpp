//Invoice.cpp: This program calculates Grocery Invoice from given inputs
//Name: Victor Sim
//Class Section: Online COSC 1436 (Programming Fundamentals 1)
//Date: 9/25/21
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
//Declaring Variables
int choice , age;
double price, tax = 0.00, discount = 0.00, finalPrice;

//User input for choice + prompt
cout<<"What would you like to buy?"<<endl;
cout<<"1. Bread\n2. Milk\n3. Soap"<<endl;
cout<<"Please enter your choice: ";
cin>>choice;

//error checking
if(choice < 1 || choice > 3){
   cout<<"Sorry, "<< choice <<" wasn't a valid choice";
   return 0;
   }

//User input for price + prompt
cout << "Please enter the price: $";
cin >> price;

//User input for age + prompt
cout << "Please enter your age: ";
cin >> age;

//Generation of Invoice/Result
cout << endl  << setw(15) << "Invoice" << endl;


if(choice == 3)
{
    tax = 0.08 * price;
}
    finalPrice = price + tax;


if(age >= 60)
{
    discount = 0.05 * finalPrice;
}
finalPrice -= discount;
cout << "Price: $%0.2f\n" <<  price;
cout << "Tax: $%0.2f\n" << tax;


if(age >= 60)
{
    cout << "Discount: $-%0.2f\n" <<tax;
}
cout << "Total: $%0.2f\n" << finalPrice;

}
