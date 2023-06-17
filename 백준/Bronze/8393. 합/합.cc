#include <iostream>

using namespace std;

int main()
{
	int n, total{};
	
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		total += i;
	}

	cout << total;
}