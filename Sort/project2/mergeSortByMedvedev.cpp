#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

template<typename T>
void mergesort(T* a, T* b, int start, int end)
{
    if (end - start < 2)
        return;
    if (end - start == 2)
    {
        if (a[start] > a[start + 1])
            swap(a[start], a[start + 1]);
        return;
    }
    mergesort(a, b, start, start + (end - start) / 2);
    mergesort(a, b, start + (end - start) / 2, end);
    int s1 = start;
    int mid = start + (end - start) / 2;
    int s2 = mid;
    int i = 0;
    while (i < (end - start))
    {

        if (s1 >= mid || (s2 < end && a[s2] <= a[s1]))
        {
            b[i] = a[s2];
            ++s2;
        }
        else
        {
            b[i] = a[s1];
            ++s1;
        }
        i++;
    }
    for (size_t i = start; i < end; ++i)
        a[i] = b[i - start];

}

vector<int>mergeSort_by_Medvedev(vector<int>to_sort)
{
    vector<int>b(to_sort.size(), 0);
    mergesort(&to_sort[0], &b[0], 0, to_sort.size());
    return to_sort;

}

vector<double>mergeSort_by_Medvedev(vector<double>to_sort)
{
    vector<double>b(to_sort.size(), 0);
    mergesort(&to_sort[0], &b[0], 0, to_sort.size());
    return to_sort;

}