#include <iostream>
#include <iomanip> // Using iomanip for things such as formatting with setw
#include <cmath> // Using cmath for advanced math functions
using namespace std; // namespace to type less

int main() {
  // Next 9 lines are all for declaring and initalizing variables that I will need in the program
  double min, max; 
  double total = 0.0, sDTotal;
  double mean, sDcount = 0, v;
  double d;
  double sDdivide;
  double randNumd;
  double variance;
  int n;
  int count = 0;

  cout << "Enter the min and max(min first): "; // Prompt Statement for input
  cin >> min >> max; // Input
  while ((min > max)) { //This next body of code is the input validation, if the inputted value is wrong
    //Then the program will prompt and take another input again
    cout << "Enter the min and max(min first) ";
    cin >> min >> max;
  }
  // Lines 26 to 38 do the same thing as lines 18 to 24 except for sample number and delta
  cout << "Enter the number of samples(n): ";
  cin >> n;
  while (!(n <= 80) || !(n >= 1)) {
    cout << "Enter the number of samples(n): ";
    cin >> n;
  }

  cout << "Enter the smallest difference between two samples(d): ";
  cin >> d;
  while (!(d <= (max - min))) {
    cout << "Enter the smallest difference between two samples(d): ";
    cin >> d;
  }
  // These next two lines are for outputting the title of the table
  cout << endl << setw(10) << right << "Col/1" << setw(10) << right << "Col/2" << setw(10) << right 
    << "Col/3" << setw(10) << right << "Col/4" << endl;

  srand(1); // Using srand to have the same random numbers everytime
  for (int i = 0; i < n; i++) { // This loop starts at 0 and increments until index hits the sample size
    int randNum = (rand() % (int)(max - min + 1) + min); // declaring/initializing random number
    randNumd = randNum * d; // setting random number with delta to variable randNumd
    cout << fixed << setprecision(3) << setw(10) << right << showpos << randNumd; //Outputting table value
    count++;                                                                      // with positive sign   
    if (count % 4 == 0) { // formatting conditional, every 4 numbers in the columns, endl
      cout << endl;
    }
    total += randNumd; // sumnation formula to get the mean
    mean = total / n; // calculating the mean from sumnation
  }  

  cout << endl; // endl for foromatting

  srand(1); // Using srand to have the same random numbers everytime
  for (int i = 0; i < n; i++) { //This loop is used to create the same numbers that the first loop created
    int randNum = (rand() % (int)(max - min + 1) + min); // same random number generator in line 45
    randNumd = randNum * d; // same declaration as in line 46
    sDTotal =  pow((randNumd - mean), 2); //setting the variable sDTotal as the sumnation of rng - mean 
    //squared (this is one part of standard deviation calculation)
    sDcount += sDTotal; // to save sDTotal in a different variable
  }

  cout << endl; // endl for formatting
  sDdivide = sqrt(sDcount / n); // final part of the standard deviation calculation
  variance = sDdivide * sDdivide; // square standard deviation to find variance
  cout << noshowpos << "Mean: " << mean << endl << "Standard Deviation: " << sDdivide << endl 
    << "Variance: " << variance << endl; // final line of output to display calculations

  return 0;
}



