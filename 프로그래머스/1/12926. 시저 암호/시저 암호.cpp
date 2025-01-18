#include <string>

std::string solution(std::string s, int n) {
    std::string answer = "";
    answer.reserve(s.length());
    
    for (int i = 0; i < s.length(); ++i)
    {
        if (' ' == s[i])
        {
            answer += ' ';
            continue;
        }
        
        char shifted = ('a' > s[i]) ? s[i] - 'A' : s[i] - 'a';

        
        shifted += n;
        shifted %= 26;
        
        answer += ('a' > s[i]) ? 'A' + shifted : 'a' + shifted;
    }
    
    return answer;
}