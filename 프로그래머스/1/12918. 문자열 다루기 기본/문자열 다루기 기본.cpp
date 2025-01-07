#include <string>

bool solution(std::string s) {
    bool answer = true;
    
    if (4 != s.size() && 6 != s.size())
    {
        answer = false;
        return answer;
    }
    
    for (int i = 0; i < s.size(); ++i)
    {
        if ('0' > s[i] || '9' < s[i])
        {
            answer = false;
            break;
        }
    }
    
    return answer;
}