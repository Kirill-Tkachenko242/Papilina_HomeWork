#pragma once
#include <vector>

template <typename T>
using Participant = std::vector<T>(*)(std::vector<T>);


std::vector<int> bubblesort_by_tkachenko(std::vector<int> to_sort);
std::vector<double> bubblesort_by_tkachenko(std::vector<double> to_sort);
std::vector<int> insertionSort_by_sheiko(std::vector<int> to_sort);
std::vector<double> insertionSort_by_sheiko(std::vector<double> to_sort);
std::vector<int> merge_sort_by_medvedev(std::vector<int> to_sort);
std::vector<double> merge_sort_by_medvedev(std::vector<double> to_sort);
std::vector<int> quick_sort_by_Loganov(std::vector<int> to_sort);
std::vector<double> quick_sort_by_Loganov(std::vector<double> to_sort);
std::vector<int> shellsort_by_doronin(std::vector<int> to_sort);
std::vector<double> shellsort_by_doronin(std::vector<double> to_sort);



