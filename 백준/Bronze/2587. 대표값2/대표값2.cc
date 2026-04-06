#include <iostream>

int main()
{
    const int Count = 5;

    int NumArr[Count] = {};
    int TotalSum = 0;

    for (int i = 0; i < Count; ++i)
    {
        std::cin >> NumArr[i];

        TotalSum += NumArr[i];
    }

    for (int i = 0; i < Count - 1; ++i)
    {
        for (int j = 0; j < Count - 1; ++j)
        {
            if (NumArr[j] > NumArr[j + 1])
            {
                int temp = NumArr[j];

                NumArr[j] = NumArr[j + 1];
                NumArr[j + 1] = temp;
            }
        }
    }

    std::cout << TotalSum / Count << std::endl;
    std::cout << NumArr[Count / 2] << std::endl;

    return 0;
}