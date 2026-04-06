#include <iostream>
#include <string>
#include <vector>

bool CharacterCountCheck(std::string first, std::string second)
{
    std::vector<int> firstCharacterCount(26, 0);
    std::vector<int> secondCharacterCount(26, 0);

    for (int i = 0; i < first.length(); ++i)
    {
        int CharacterIndex = first[i] - 'a';
        ++firstCharacterCount[CharacterIndex];
    }

    for (int i = 0; i < second.length(); ++i)
    {
        int CharacterIndex = second[i] - 'a';
        ++secondCharacterCount[CharacterIndex];
    }

    for (int i = 0; i < firstCharacterCount.size(); ++i)
    {
        if (firstCharacterCount[i] != secondCharacterCount[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int CaseCount;
    std::cin >> CaseCount;

    for (int i = 0; i < CaseCount; ++i)
    {
        std::string first, second;
        std::cin >> first >> second;

        bool bIsPossible = CharacterCountCheck(first, second);

        if (bIsPossible)
        {
            std::cout << "Possible" << std::endl;
        }
        else
        {
            std::cout << "Impossible" << std::endl;
        }
    }
}