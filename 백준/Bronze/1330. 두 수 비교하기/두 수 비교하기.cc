#include <iostream>

int main(void)
{
	int a, b;

	std::cin >> a >> b;

	if (a > b)
	{
		std::cout << ">";
	}
	else if (a < b)
	{
		std::cout << "<";
	}
	else if (a == b)
	{
		std::cout << "==";
	}
}