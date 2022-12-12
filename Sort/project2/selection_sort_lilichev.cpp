#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

template <typename T>
void selectSort(vector<T>& to_sort)//, int n)
{
	int n = to_sort.size();
	//pos_min is short for position of min
	int pos_min, temp;

	for (int i = 0; i < n - 1; i++)
	{
		pos_min = i;//set pos_min to the current index of array

		for (int j = i + 1; j < n; j++)
		{

			if (to_sort[j] < to_sort[pos_min])
				pos_min = j;
			//pos_min will keep track of the index that min is in, this is needed when a swap happens
		}

		//if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
		if (pos_min != i)
		{
			temp = to_sort[i];
			to_sort[i] = to_sort[pos_min];
			to_sort[pos_min] = temp;
		}
	}
}

vector<int> select_sort_by_lilichev(vector<int> to_sort) {
	selectSort(to_sort);
	return to_sort;
}
vector<double> select_sort_by_lilichev(vector<double> to_sort) {
	selectSort(to_sort);
	return to_sort;
}

