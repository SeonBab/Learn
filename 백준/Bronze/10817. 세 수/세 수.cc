#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int arr[3], temp;


	for (int i = 0; i < 3; i++)
	{
		std::cin >> arr[i];
	}

	sort(arr, arr + 3);

	cout << arr[1];


}