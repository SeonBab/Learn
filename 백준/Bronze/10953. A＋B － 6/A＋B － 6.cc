#include <iostream>

using namespace std;

int main()
{
	int n, a, b;
	char comma;

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a >> comma >> b;

		cout << a + b << endl;
	}

	return 0;
}