#include <iostream> // cin/cout
#include <fstream> // file-stream
#include <iomanip> // in/output manipulators
#include <string> // string-class
#include <cmath> // math-class

using namespace std;

struct input {
  int id;
  double x_coord;
  double y_coord;
  string city_name;
};
typedef struct input CITY;

int optionOutput(char, int & , int & , CITY * , int);
int numRecords(string);
void display_menu();

int main() {

  string fileName;
  cout << "Enter the file name: " << endl;
  cin >> fileName;

  int array_size = numRecords(fileName);
  CITY * input_array = new CITY[array_size];

  ifstream input_file;
  input_file.open(fileName);

  if (!input_file.is_open()) {
    cout << "Error opening file\n";
    return -1;
  }

  for (int i = 0; i < array_size; i++) {
    input_file >> input_array[i].id >> input_array[i].x_coord >> input_array[i].y_coord;
    getline(input_file, input_array[i].city_name);
  }
  input_file.close();

  int iCity1 = -1, iCity2 = -1;
  char option;

  do {
    display_menu();
    cin >> option;
    while (getchar() != '\n');
    optionOutput(option, iCity1, iCity2, input_array, array_size);
  } while (!(option == 'd' || option == 'D'));

  return 0;
}

int numRecords(string fileName) {
  ifstream input_file;
  input_file.open(fileName.c_str());

  if (!input_file.is_open()) {
    cout << "Error opening file\n";
    return -1;
  }

  int counter = 0;
  string helper;
  while (!input_file.eof()) {
    getline(input_file, helper);
    counter++;
  }

  input_file.close();

  return counter;
}

void display_menu() {
  cout << "a) Enter cities\nb) Compute the distance between the two cities\n";
  cout << "c) Find the closest city to city1\nd) exit\n";
}

int optionOutput(char option, int & iCity1, int & iCity2, CITY * input_array, int array_size) {
  if (option == 'a' || option == 'A') {
    char option2;
    do {
      cout << "1) by ID\n2) by name\n";
      cin >> option2;
      while (getchar() != '\n');
    } while (option2 != '1' && option2 != '2');

    switch (option2) {
    case '1':
      int id;
      cout << "Enter ID: " << endl;
      cin >> id;
      for (int i = 0; i < array_size; i++) {
        if (id == input_array[i].id) {
          cout << input_array[i].id << "\t" << input_array[i].x_coord <<
            "\t" << input_array[i].y_coord << "\t" << input_array[i].city_name << endl;
        }
      }
      break;
    case '2':
      string city_value;
      cout << "Enter City Name: " << endl;
      getline(cin, city_value);

      string new_value;

      for (int j = 0; j < array_size; j++) {
        new_value = "";
        bool has_alpha = false;
        for (int i = 0; i < input_array[j].city_name.length(); i++) {

          int city_val_i;

          if (has_alpha || isalpha(input_array[j].city_name.at(i))) {
            has_alpha = true;
            new_value += input_array[j].city_name.at(i);
          }
        }
        input_array[j].city_name = new_value;
      }

      for (int i = 0; i < array_size; i++) {
        if (city_value == input_array[i].city_name) {
          cout << input_array[i].id << "\t" << input_array[i].x_coord <<
            "\t" << input_array[i].y_coord << "\t" << input_array[i].city_name << endl;
        }
      }
      break; // end switch statement
    }
  } else if (option == 'b' || option == 'B') {
    do {
      cout << "calculating distance between 2 cities: \nEnter City 1 ID: " << endl;
      cin >> iCity1;
      cout << "Enter City 2 ID: " << endl;
      cin >> iCity2;

    } while (iCity1 == -1 && iCity2 == -1);
    bool city1_found = false, city2_found = false;
    int indexC1, indexC2;
    for (int i = 0; i < array_size; i++) {
      if (iCity1 == input_array[i].id) {
        indexC1 = i;
        city1_found = true;
      }
      if (iCity2 == input_array[i].id) {
        indexC2 = i;
        city2_found = true;
      }
    }

    if (city1_found && city2_found) {
      cout << "Distance between \'City ID: " << iCity1 << "\' and \'City ID: " << iCity2 <<
        "\' is: " <<
        pow((pow(input_array[indexC2].x_coord - input_array[indexC1].x_coord, 2) +
          pow(input_array[indexC2].y_coord - input_array[indexC1].y_coord, 2)), 0.5) << endl;
    } else {
      cout << "Please enter a valid city ID" << endl;
    }
  } else if (option == 'c' || option == 'C') {
    int city_id, city_i;
    cout << "Enter CITY ID: " << endl;
    cin >> city_id;

    double city_id_isfound = false;

    for (int i = 0; i < array_size; i++) {
      if (city_id == input_array[i].id) {
        city_i = i;
        city_id_isfound = true;
      }
    }

    if (!city_id_isfound) {
      cout << "invalid input! Please try again...\n" << endl;
      return -2;
    }

    double * distance_array = new double[array_size];

    for (int i = 0; i < array_size; i++) {
      distance_array[i] = pow((pow(input_array[i].x_coord - input_array[city_i].x_coord, 2) +
        pow(input_array[i].y_coord - input_array[city_i].y_coord, 2)), 0.5);
    }

    double min_val = distance_array[0];
    int min_i = 0;

    while (min_val == 0) {
      min_i++;
      min_val = distance_array[min_i];
    }

    for (int i = 0; i < array_size; i++) {
      if (distance_array[i] != 0 && distance_array[i] < min_val) {
        min_val = distance_array[i];
        min_i = i;
      }
    }
    cout << "Minimum Distance is between:\nCity ID: " << city_id << " and City ID: " <<
      input_array[min_i].id << endl;
    cout << "The distance between these two cities is: " << min_val << "\n" << endl;

  } else if (option == 'd' || option == 'D') {
    return -1;
  } else {
    cout << "Invalid option, please try again...\n";
    return -2;
  }
  return 0; // exit success

}
