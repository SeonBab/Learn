#include <iostream>

using namespace std;

int main()
{
	int N, X, a[10000];

	cin >> N >> X;

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];

		if (X > a[i])
		{
			cout << a[i] << " ";
		}
	}
}