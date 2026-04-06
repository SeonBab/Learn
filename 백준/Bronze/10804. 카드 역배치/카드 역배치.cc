#include <iostream>

int NumberList[20] = { 0 };

void Reverse(int StartIndex, int EndIndex)
{
    int ReverseCount = (EndIndex - StartIndex);

    while (true)
    {
        int temp = NumberList[StartIndex];

        NumberList[StartIndex] = NumberList[EndIndex];
        NumberList[EndIndex] = temp;

        ++StartIndex;
        --EndIndex;

        if (StartIndex >= EndIndex)
        {
            return;
        }
    }
}

int main()
{
    for (int i = 0; i < 20; ++i)
    {
        NumberList[i] = i + 1;
    }

    for (int i = 0; i < 10; ++i)
    {
        int StartNumber, EndNumber;

        std::cin >> StartNumber >> EndNumber;

        Reverse(StartNumber - 1, EndNumber - 1);
    }

    for (int i = 0; i < 20; ++i)
    {
        if (i != 0)
        {
            std::cout << " ";
        }

        std::cout << NumberList[i];
    }
    
    return 0;
}