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
            answer += std::toupper(s[i]);
        }
        else
        {
            answer += std::tolower(s[i]);
        }
        
        ++index;
    }
    
    return answer;
}