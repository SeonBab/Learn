#include <iostream>

int main()
{
    int n;

    std::cin >> n;

    int NumCounts[10] = { 0 };

    while (n != 0)
    {
        int TargetIndex = n % 10;

        ++NumCounts[TargetIndex];

        n /= 10;
    }

    int FlipCount = NumCounts[9] + NumCounts[6];

    int temp = FlipCount / 2;

    NumCounts[9] = temp;
    NumCounts[6] = FlipCount - temp;

    int SetCount = 0;

    for (int i = 0; i < 10; ++i)
    {
        if (SetCount < NumCounts[i])
        {
            SetCount = NumCounts[i];
        }
    }

    std::cout << SetCount;

    return 0;
}