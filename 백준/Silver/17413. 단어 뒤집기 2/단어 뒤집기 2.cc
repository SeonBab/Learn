#include <iostream>
#include <string>
#include <vector>

std::string ReserveWord(std::string str)
{
    std::string result;

    int BackIndex = str.length();
    if (str.back() == ' ')
    {
        BackIndex = str.length() - 1;
    }

    for (int i = BackIndex - 1; i >= 0; --i)
    {
        result += str[i];
    }

    if (str.back() == ' ')
    {
        result += str[BackIndex];
    }
    
    return result;
}

std::vector<std::string> SubString(std::string str)
{
    std::vector<std::string> Result;

    std::string SubStr;

    bool IsSymbolStart = false;

    for (int i = 0; i < str.size(); ++i)
    {
        // 특수문자 단어 시작
        if (str[i] == '<')
        {
            IsSymbolStart = true;

            // 문자열이 비어있지 않은 경우 단어의 끝
            if (!SubStr.empty())
            {
                Result.push_back(SubStr);
                SubStr.clear();
            }
        }
        
        SubStr += str[i];
        
        // 특수문자가 끝날 경우 단어의 끝
        if (str[i] == '>')
        {
            IsSymbolStart = false;
            Result.push_back(SubStr);
            SubStr.clear();
        }
        // 특수문자 안에 있지 않은 공백일 경우 단어의 끝이다.
        else if (IsSymbolStart == false && str[i] == ' ')
        {
            Result.push_back(SubStr);
            SubStr.clear();
        }
    }

    // 마지막 문자가 남아있을 경우
    if (!SubStr.empty())
    {
        Result.push_back(SubStr);
    }

    return Result;
}

int main()
{
    std::string InputString;
    getline(std::cin, InputString);

    std::vector<std::string> SubStringArr = SubString(InputString);

    std::string ResultStr;
    for (int i = 0; i < SubStringArr.size(); ++i)
    {
        std::string SubStr = SubStringArr[i];

        if (SubStr.front() == '<')
        {
            ResultStr += SubStr;
        }
        else
        {
            ResultStr += ReserveWord(SubStr);
        }
    }

    std::cout << ResultStr << std::endl;
}