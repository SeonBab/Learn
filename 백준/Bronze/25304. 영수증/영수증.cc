#include <iostream>

using namespace std;

int main(void)
{
	int X, N;
	int a, b, c = 0;

	cin >> X >> N;

	for (int i = 0; i <= N - 1; i++)
	{
		cin >> a >> b;

		c += a * b;
	}

	if (X == c) cout << "Yes";
	else cout << "No";

}