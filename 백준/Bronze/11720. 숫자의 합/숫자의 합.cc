#include <iostream>

using namespace std;

int main()
{
	int N, total{};
	char ch;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> ch;
		total += ch - 48;
	}

	cout << total;
}