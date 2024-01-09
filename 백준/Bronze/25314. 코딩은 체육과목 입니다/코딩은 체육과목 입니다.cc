#include <iostream>

using namespace std;

int main()
{
	int n;

	cin >> n;

	for (int i = 4; i <= n; n -= i)
	{
		cout << "long ";
	}

	cout << "int";
}