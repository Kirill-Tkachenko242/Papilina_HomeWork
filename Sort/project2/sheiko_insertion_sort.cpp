#include <vector>
#include <algorithm>
using namespace std;



template <typename T>

void insertionSort(vector<T>& to_sort)
{
    int listLength= to_sort.size();
    for (int i = 1; i < listLength; i++)
    {
        int j = i - 1;
        while (j >= 0 && to_sort[j] > to_sort[j + 1])
        {
            swap(to_sort[j], to_sort[j + 1]);
            j--;
        }
    }
}

vector<int> insertionSort_by_sheiko(vector<int> to_sort) {
    insertionSort(to_sort);
    return to_sort;
}
vector<double> insertionSort_by_sheiko(vector<double> to_sort) {
    insertionSort(to_sort);
    return to_sort;
}