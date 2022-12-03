#include <vector>
#include <algorithm>
using namespace std;



template <typename T>
void bubble_sort(vector<T>& to_sort) {
    int length = to_sort.size();
    int temp;
    for (int i = 0; i < length; ++i)
        for (int q = length - 1; q > i; --q)
            if (to_sort[q] < to_sort[q - 1])
            {
                temp = to_sort[q]; to_sort[q] = to_sort[q - 1]; to_sort[q - 1] = temp;
            }
}

vector<int> bubblesort_by_tkachenko(vector<int> to_sort) {
    bubble_sort(to_sort);
    return to_sort;
}
vector<double> bubblesort_by_tkachenko(vector<double> to_sort) {
    bubble_sort(to_sort);
    return to_sort;
}