#include <iostream>
#include <string>

int main()
{
    std::string InputStr;
    getline(std::cin, InputStr);

    std::string Result;
    std::string Temp;

    bool InTag = false;

    for (char C : InputStr)
    {
        if (C == '<')
        {
            // 단어 끝이므로, 기존 단어 뒤집기
            for (int i = Temp.size() - 1; i >= 0; --i)
            {
                Result += Temp[i];
            }
                
            Temp.clear();

            InTag = true;
            Result += C;
        }
        else if (C == '>')
        {
            InTag = false;
            Result += C;
        }
        else if (InTag)
        {
            Result += C;
        }
        else
        {
            if (C == ' ')
            {
                // 단어 끝이므로, 기존 단어 뒤집기
                for (int i = Temp.size() - 1; i >= 0; --i)
                    Result += Temp[i];
                Temp.clear();

                Result += ' ';
            }
            else
            {
                Temp += C;
            }
        }
    }

    // 마지막 단어 처리
    for (int i = Temp.size() - 1; i >= 0; --i)
    {
        Result += Temp[i];
    }

    std::cout << Result << std::endl;
}