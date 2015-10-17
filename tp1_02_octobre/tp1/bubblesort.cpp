#include <iostream>
#include <vector>
#include <algorithm>
#include "bubblesort.h"

using namespace std;

void BubbleSort(vector<int> &values, int start, int size) {

  bool swapped;
  int temp;
  do {
    swapped = false;
    for (int i = start; i < size - 1; i++) {
      // Si la paire n'est pas ordonnee
      if (values[i] > values[i + 1]) {
        // On interchange les valeurs
        swap(values[i], values[i + 1]);
        swapped = true;
      }
    }
  } while (swapped);
}
