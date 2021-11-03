#include <iostream>
#include <iomanip> 
#include <cmath>
using namespace std;

int main() {

  double starting, ending, increment;
  double celsius, kelvin;
  
  cin >> starting >> ending >> increment;
  
  cout << fixed << setprecision(4);

  while (true) {
    if (!(starting <= ending && increment > 0.0)) {
      cout << "Starting temperature must be <= ending temperature and increment must be > 0.0" << endl;
      cin >> starting >> ending >> increment;
    } else {
      break;
    }
  }

  cout << setw(18) << "Fahrenheit" << setw(18) << "Celsius" << setw(18) << "Kelvin" << endl;

  for (double i = starting; i <= ending; i = (i + increment)) {
    if (starting == ending && starting == increment) {
    cout << setw(18) << i << setw(18) << (i - 32) / 1.8 << setw(18) << ((i - 32) / 1.8) + 273.15 << endl;
    break;
    }
   celsius = (i - 32) / 1.8;
   kelvin = celsius + 273.15;
   cout << setw(18) << i << setw(18) << celsius << setw(18) << kelvin << endl;
  }

  return 0;
}
