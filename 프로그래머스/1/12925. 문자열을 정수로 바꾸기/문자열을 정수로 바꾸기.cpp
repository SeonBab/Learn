#include <string>

int solution(std::string s) {
    int answer = 0;
    
    for (int i = 0; i < s.size(); ++i)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            answer *= 10;
            answer += s[i] - '0';
        }
    }
    
    if (s[0] == '-')
    {
        answer *= -1;
    }
    
    return answer;
}