#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d, time;
	
	cin >> a >> b >> c >> d;

	time = a + b + c + d;

	cout << time / 60 << endl << time % 60;

	return 0;
}