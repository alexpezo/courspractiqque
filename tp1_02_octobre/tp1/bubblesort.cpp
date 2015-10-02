#include "bubblesort.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<int> bubbleSort(std::vector<int> vec) {
  int sorted ;

  while (sorted != 0) {
    sorted = 0;
    for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); i++) {
      if (i + 1 != vec.end()) {
        if (*i > *(i + 1)) {
          iter_swap(i, i + 1);
          sorted += 1;
        }
      }
    }
  }
  return vec;
}
