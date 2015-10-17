#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
#include "bubblesort.h"
#include "quicksort.h"

/* Lecture des fichiers (source github) */

void ReadArray(std::string filename, std::vector<int> &array, int size) {
  std::fstream file(filename);
  array.clear();
  if (file.is_open()) {
    int number, i = 0;
    while (!file.eof() && i < size) {
      file >> number;
      array.push_back(number);
      ++i;
    }
  } else {
    std::cout << "Error open file :" << filename << std::endl;
  }
}

/* Ecriture dans sortie.csv */

void WriteCSV(int size, double time, std::string algorithm, std::string serie, std::string path_name) {
  std::ofstream myfile;
  std::string file_path_out = path_name + "data_" + algorithm + "_" + serie + ".csv";
  myfile.open(file_path_out, std::fstream::app);
  //myfile << "Taille" << "," << "Time" << "\n";
  myfile << size << "," << time << "\n";
  myfile.close();
}

/* Application principale */

int main(int argc, char *argv[]) {

  std::string path_name = argv[1];
  std::string algorithm = argv[2];
  int size = atoi(argv[3]);
  std::string serie = argv[4]; // serie de donnees 0_9, 10_19, 20_29
  std::string file_name = "";

  double time;
  double moyenne = 0; // moyenne pour les difference series
  double somme = 0;
  std::vector<int> array_to_sort;
  array_to_sort.reserve(size);

  /* Pour chaque fichier de la serie */
  for (int i = 0; i < 10; ++i) {

    if (serie == "0_9") {
      file_name = path_name + "tp1-H10-donnees/testset_" + std::to_string(size) + "_" + std::to_string(i) + ".txt";
      ReadArray(file_name, array_to_sort, size);
    } else if (serie == "10_19") {
      file_name = path_name + "tp1-H10-donnees/testset_" + std::to_string(size) + "_" + std::to_string(i + 10) + ".txt";
      ReadArray(file_name, array_to_sort, size);
    } else if (serie == "20_29") {
      file_name = path_name + "tp1-H10-donnees/testset_" + std::to_string(size) + "_" + std::to_string(i + 20) + ".txt";
      ReadArray(file_name, array_to_sort, size);
    }

    file_name = argv[1];
    std::clock_t start;
    start = std::clock(); // le temps de debut

    if (algorithm == "bubblesort") {
      BubbleSort(array_to_sort, 0, array_to_sort.size());
    } else if (algorithm == "quicksort_pivot_first") {
      QuichSortPivotFirst(array_to_sort, 0, array_to_sort.size() - 1);
//      QuichSortPivotFirst(array_to_sort, 0, array_to_sort.size()-1);
    } else if (algorithm == "quicksort_seuil") {
      QuichSortSeuil(array_to_sort, 0, array_to_sort.size());
    } else if (algorithm == "quicksort_random") {
      QuickSortRandom(array_to_sort, 0, array_to_sort.size());
    } else if (algorithm == "quicksort_random_seuil") {
      QuickSortRandomSeuil(array_to_sort, 0, array_to_sort.size());
    }


//    // le temps de fin
    time = (std::clock() - start) / (double) (CLOCKS_PER_SEC / 1000);
    somme += time;
  }
  moyenne = somme / 10;
  std::cout << time << std::endl;

  /* Ecrire le resultat dans fichier CSV */

  WriteCSV(size, moyenne, algorithm, serie, path_name);

  return 0;
}
