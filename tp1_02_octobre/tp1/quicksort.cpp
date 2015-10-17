#include <iostream>
#include <vector>
#include <algorithm>
#include "bubblesort.h"

#define SEUIL 100 // pour changer la valeur de seuil

using namespace std;



/*Definitions des fonctions*/

/**
 * @bref QuickSort avec pivot = left sans seuil
 *
 * @param array tableau a trier
 * @param left indice du premier element de tableau
 * @param right indice du dernier element de tableau
 */

void QuichSortPivotFirst(vector<int> &array, int left, int right) {
  int pivot, i, j, temp;
  if (left < right) {
    pivot = left;
    i = left;
    j = right;
    while (i < j) {
      while (array[i] <= array[pivot] && i <= right) {
        i++;
      }
      while (array[j] > array[pivot] && j >= left) {
        j--;
      }
      if (i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
    temp = array[j];
    array[j] = array[pivot];
    array[pivot] = temp;
    QuichSortPivotFirst(array, left, j - 1);
    QuichSortPivotFirst(array, j + 1, right);
  }
}

/**
 * @bref QuickSort avec pivot = left avec un seuil
 *
 * @param array tableau a trier
 * @param left indice du premier element de tableau
 * @param right indice du dernier element de tableau
 */

void QuichSortSeuil(vector<int> &array, int left, int right) {
  int pivot, i, j, temp;
  if (left < right) {
    pivot = left;
    i = left;
    j = right;
    while (i < j) {
      while (array[i] <= array[pivot] && i <= right) {
        i++;
      }
      while (array[j] > array[pivot] && j >= left) {
        j--;
      }
      if (i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
    temp = array[j];
    array[j] = array[pivot];
    array[pivot] = temp;

    if (left + SEUIL < right) {
      QuichSortPivotFirst(array, left, j - 1);
      QuichSortPivotFirst(array, j + 1, right);
    } else {
      BubbleSort(array, left, right);
    }

  }
}


/**
 * @bref QuickSort avec pivot = random  sans seuil
 *
 * @param array tableau a trier
 * @param left indice du premier element de tableau
 * @param right indice du dernier element de tableau
 */

void QuickSortRandom(std::vector<int> &array, int left, int right) {
  int l = left;
  int r = right - 1;
  int size = right - left;

  if (size > 1) {
    int pivot = array[rand() % size + l];


    while (l < r) {
      while (array[r] > pivot && r > l) {
        r--;
      }

      while (array[l] < pivot && l <= r) {
        l++;
      }

      if (l < r) {
        std::swap(array[l], array[r]);
        l++;
      }
    }

    QuickSortRandom(array, left, l);
    QuickSortRandom(array, r, right);
  }
}


/**
 * @bref QuickSort avec pivot = random  avec seuil
 *
 * @param array tableau a trier
 * @param left indice du premier element de tableau
 * @param right indice du dernier element de tableau
 */
void QuickSortRandomSeuil(std::vector<int> &array, int left, int right) {
  int l = left;
  int r = right - 1;
  int size = right - left;

  if (size > 1) {
    int pivot = array[rand() % size + l];


    while (l < r) {
      while (array[r] > pivot && r > l) {
        r--;
      }

      while (array[l] < pivot && l <= r) {
        l++;
      }

      if (l < r) {
        std::swap(array[l], array[r]);
        l++;
      }
    }
    if (left + SEUIL < r) {
      QuickSortRandom(array, left, l);
      QuickSortRandom(array, r, right);
    }
    else {
      BubbleSort(array, left, l);
      BubbleSort(array, r, right);
    }
  }
}

