#include <iostream>

using namespace std;

int arr[3];

void bubbleSort()
{
	int tmp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 3; i++)
	{
		cin >> arr[i];
	}

	bubbleSort();


	for (int i = 0; i < 3; i++)
	{
		cout << arr[i] << ' ';
	}
	
	return 0;
}