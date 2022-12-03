#pragma once
#include <vector>
//#include"BitonicSort_Sharnin.h"
//#include"MergeSort_Shuranskiy.h"
//#include"HeapSort_Gabrielian.h"
//#include"QuickSort_Pashayan.h"

template <typename T>
using Participant = std::vector<T>(*)(std::vector<T>);



//--------------------Team Tkachenko---------------------------
std::vector<int> bubblesort_by_tkachenko(std::vector<int> to_sort);
std::vector<double> bubblesort_by_tkachenko(std::vector<double> to_sort);

//std::vector<int> shellsort_by_kamenshchikov(std::vector<int> to_sort);
//std::vector<double> shellsort_by_kamenshchikov(std::vector<double> to_sort);
//
//std::vector<int> merge_sort_by_iliushik(std::vector<int> data);
//std::vector<double> merge_sort_by_iliushik(std::vector<double> data);
//
//std::vector<double> quick_sort_by_Shabalinov(std::vector<double> data);
//std::vector<int> quick_sort_by_Shabalinov(std::vector<int> data);
//---------------------------------------------------------------


