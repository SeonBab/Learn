#include <iostream>
#include <vector>
#include <unordered_set>

int main()
{
    int NumberCount;
    std::cin >> NumberCount;

    std::vector<int> NumArr;
    for (int i = 0; i < NumberCount; ++i)
    {
        int Number;
        std::cin >> Number;

        NumArr.push_back(Number);
    }

    int TargetNumber;
    std::cin >> TargetNumber;

    std::unordered_set<int> FoundNumber;
    int FoundCount = 0;

    for (int i = 0; i < NumArr.size(); ++i)
    {
        int b = TargetNumber - NumArr[i];

        if (FoundNumber.count(b))
        {
            ++FoundCount;
        }

        FoundNumber.insert(NumArr[i]);
    }

    std::cout << FoundCount;
}