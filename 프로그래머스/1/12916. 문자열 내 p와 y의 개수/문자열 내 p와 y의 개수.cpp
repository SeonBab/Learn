#include <string>

bool solution(std::string s)
{
    bool answer = false;
    
    int pCount = 0;
    int yCount = 0;
    
    for (const auto& e : s)
    {
        if (e == 'p' || e == 'P')
        {
            ++pCount;
        }
        else if (e == 'y' || e == 'Y')
        {
            ++yCount;
        }
    }
    
    if (pCount == yCount)
    {
        answer = true;
    }

    return answer;
}