#include <iostream>
#include <iomanip>

double inchesToCentimeters(double inches) {
  double centimeters;
  centimeters = inches * 2.54;
  std::cout << centimeters << std::endl;
  return centimeters;
}

double centimetersToInches(double centimeters) {
  double inches;
  inches = centimeters / 2.54;
  std::cout << inches << std::endl;
  return inches;
}

double inchesToFeet(double inches) {
  double feet;
  feet = inches / 12.0;
  std::cout << feet << std::endl;
  return feet;
}

double feetToInches(double feet) {
  double inches;
  inches = feet * 12.0;
  std::cout << inches << std::endl;
  return inches;
}

int main() { 
  char operation;
  double input;
  std::cin >> operation;
  std::cin >> input;
  std::cout << std::fixed << std::setprecision(2);

  switch(operation) {
      case 'c':
          // TODO: inches to centimeters
          inchesToCentimeters(input);
          break;
      case 'C':
          // TODO: feet to centimeters
          inchesToCentimeters(feetToInches(input));
          break;
      case 'f':
          // TODO: inches to feet
          inchesToFeet(input);
          break;
      case 'F':
          // TODO: centimeters to feet
          inchesToFeet(centimetersToInches(input));
          break;
      case 'i':
          // TODO: feet to inches
          feetToInches(input);
          break;
      case 'I':
          // TODO: centimeters to inches
          centimetersToInches(input);
          break;
      default:
          std::cout << "Unknown operation " << operation << std::endl;
  }
  return 0;
}

