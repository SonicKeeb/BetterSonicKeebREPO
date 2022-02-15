#include <iostream>
#include <fstream>
using namespace std;

int getNumberOfSamples();
int generateSamplesAndStoreInFile(int);
int readValuesFromFile(int [], int);
void bubblesort(int [], int);
bool linearSearchForAValue(int [], int, int);
bool recursiveSearchForAValue(int [], int, int);

int main() {
  int N = getNumberOfSamples();

  if (generateSamplesAndStoreInFile(N) == -1){
    return -1;
  }

  int data[100];
  if (readValuesFromFile(data, 100) == -2){
    return -2;
  }

  bubblesort(data, N);

  int key;
  cout << "Enter a value to search for: " << endl;
  cin >> key;

  cout << "Linear Search: ";
  if (!linearSearchForAValue(data, N, key)) {
    cout << "The value " << key << " was not found!\n";
  } else { 
    cout << "The value " << key << " was found!\n"; }

  cout << "Recursive Search: ";
  if (!recursiveSearchForAValue(data, N, key)) {
    cout << "The value " << key << " was not found!\n";
  } else { 
    cout << "The value " << key << " was found!\n";
  }

  return 0;
}

int getNumberOfSamples() {
  int M;
  do {
    cout << "Please enter the number of samples [1,100]: ";
    cin >> M;
  } while(M < 0 || M > 100);
  return M;
}

int generateSamplesAndStoreInFile(int M) {
  ofstream outputFile;
  outputFile.open("test.txt");

  if (!outputFile.is_open()) {
    cout << "Error opening the file for writing...\n";
    return -1;
  }
  srand(1); // for computing
  for (int i = 0; i < M; i++) {
    outputFile << rand() << endl;
  }
  outputFile.close();
  return 0;
}

int readValuesFromFile(int values[], int SIZE){
  ifstream inputFile;
  inputFile.open("test.txt");

  if (!inputFile.is_open()){
    cout << "Error opening the file for reading...\n";
    return -2;
  }
  int index = 0;
  while(!inputFile.eof() && index < SIZE) {
    inputFile >> values[index];
    index++;
  }
  inputFile.close();
}

void bubblesort(int values[], int N) {
  int temp; // helper for swapping
  bool SWAP;
  do {
    SWAP = false;

    for (int i = 0; i < N-1; i++) {
      if (values[i] > values[i+1]) {
        temp = values[i];
        values[i] = values[i+1];
        values[i+1] = temp;
        SWAP = true;
      }
    }

  } while (SWAP);
}

bool linearSearchForAValue(int values[], int SIZE, int key) {
  for (int i = 0; i < SIZE; i++) {
    if (values[i] == key) {
      return true;
    }
  }
  return false;
}

bool recursiveSearchForAValue(int values[], int SIZE, int key) {
  // base case
  if (SIZE == 0)
    return false;
  if (values[--SIZE] == key) {
    return true;
  }
  recursiveSearchForAValue(values, SIZE, key);
}
