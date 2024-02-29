#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	int sum = 0;
	
	for (int i = 0; i < 5; ++i)
	{
		cin >> n;

		sum += n;
	}

	cout << sum;

	return 0;
}