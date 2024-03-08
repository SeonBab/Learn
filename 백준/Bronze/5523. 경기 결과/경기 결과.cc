#include <iostream>

using namespace std;

int main()
{
	int n, a, b, c = 0, d = 0;

	cin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;

		if (a > b)
		{
			++c;
		}
		else if (a < b)
		{
			++d;
		}
	}

	cout << c << " " << d;

	return 0;
}