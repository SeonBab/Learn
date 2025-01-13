#include <string>

std::string solution(std::string s) {
    std::string answer = "";
    
    int index = 0;
    
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ' ')
        {
            index = 0;
            answer += ' ';
            
            continue;
        }
        
        if (index % 2 == 0)
        {
            if ('a' <= s[i])
            {
                s[i] = static_cast<int>(s[i]) - 32;
            }
        }
        else
        {
            if ('a' > s[i])
            {
                s[i] = static_cast<int>(s[i]) + 32;
            }
        }
        
        ++index;
    }

    answer = s;
    
    return answer;
}