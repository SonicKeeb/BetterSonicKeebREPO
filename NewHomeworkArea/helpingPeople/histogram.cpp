#include <iostream>
#include <string>
#include <vector>
using namespace std;

int rollDie() {
  return rand() % 6 + 1;
}

void initArray(int data[], int size) {

  for(int i = 0; i < size; i++) {
    data[i] = rollDie() + rollDie();
  }
}

void sortArray(int data[], int size) {
  for(int i = 1; i < size; i++) {
    data[i] = rollDie() + rollDie();
  }
   for (int i = 1; i < size; i++) {
    for(int a = 0; a < size; a++) {
      if(data[i] > data[a]) {
        int temp = data[i];
        data[i] = data[a];
        data[a] = temp;
      }
    }
    cout << data[i];
  }
}

void bucketize(const int data[], int size, int buckets[]) {
  for(int a = 0; a < 11; a++) {
    buckets[a] = 0;
  }
  for(int i = 0; i < size; i++) {
    int randVar = rollDie() + rollDie();
    for(int j = 0; j < size; j++) {
      if(data[i] == randVar) {
        buckets[randVar - 2]++; 
      }
    }
  }
}

void normalizeBuckets(int buckets[], int norm) {

  int max = buckets[0];
  for(int a = 0; a < 11; a++) {
    if(max < buckets[a]) {
      max = buckets[a];
    }
  }

  for(int i = 0; i < 11; i++) {
    if(buckets[i] >= 0 && buckets[i] <= norm) {
      buckets[i] = (buckets[i] * norm)/(max);
    }
    cout << buckets[i];
  }
}

void displayHistogram(int buckets[]) {

  for(int i = 0; i < 11; i++) {
    cout << i + 2 << ":  ";
    for(int j = 0; j < buckets[i]; j++) {
      cout << "*";
    }
    cout << endl;
  }
}

int main() {
  int rolls;
  srand(4);
  cout << "Enter the number of rolls:" << endl;
  cin >> rolls;
  int diceArray[11];
  int size = sizeof(diceArray)/sizeof(diceArray[0]);
  initArray(diceArray, size);
  sortArray(diceArray, size);
  for(int i = 0; i < rolls; i++) {
    if(diceArray[i] == 7) {
      cout << "The first instance of a '7' in the sorted array is:" << i << endl;
      break;
    }
  }

  int bucketArray[11];
 // normalizeBuckets(bucketArray, 10);
 // displayHistogram(bucketArray); 

  return 0;
}
