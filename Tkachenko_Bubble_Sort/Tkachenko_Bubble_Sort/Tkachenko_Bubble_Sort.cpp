#include <iostream>
#include <ctime> 
using namespace std;

void BubbleSort(int list[], int listLength)
{
	while (listLength--)
	{
		bool swapped = false;
		for (int i = 0; i < listLength; i++)
		{
			if (list[i] > list[i + 1])
			{
				swap(list[i], list[i + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

int main()
{
	srand(time(0));
	int list[10] = { 50,22,65,62,39,69,17,13,23,26 };
	cout << "Input array: " << endl;
	for (int i = 0; i < 10; i++)
		cout << list[i] << '\t';
	cout << endl;

	BubbleSort(list, 10);

	cout << "Sorted array: " << endl;
	for (int i = 0; i < 10; i++)
		cout << list[i] << '\t';
	cout << endl;
	cout << "runtime = " << clock() / 1000.0 << endl; // время работы программы                  
}
