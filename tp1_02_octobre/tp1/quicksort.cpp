/**
 * @author Benjamin James Wright <bwright@cse.unsw.edu.au>
 * @description Efficient implementation of quicksort using the
 *  c++11 standard.
 */

#include <iostream>
#include <random>
#include <iterator>
#include "quicksort.h"


std::size_t partition(std::vector<int>& array, std::size_t pivot, std::size_t left, std::size_t right) {
  int value = array[pivot];
  std::swap(array[pivot], array[right]);
  std::size_t store = left;
  for (size_t i = left; i < right; ++i) {
    if (array[i] <= value) {
      std::swap(array[i], array[store]);
      store++;
    }
  }
  std::swap(array[store], array[right]);
  return store;
}


void quicksort(std::vector<int>& array, std::size_t left, std::size_t right) {
  if (left < right) {
    // Randomly choose the pivot.
    std::minstd_rand generator;
    std::uniform_int_distribution<> dist(left, right);
    // Find the new pivot from partitioning on a random pivot.
    std::size_t new_pivot = partition(array, dist(generator), left, right);
    // Recurse as per usual.
    quicksort(array, left, new_pivot - 1);
    quicksort(array, new_pivot + 1, right);
  }
}