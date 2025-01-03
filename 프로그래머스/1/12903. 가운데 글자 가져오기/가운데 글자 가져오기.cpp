#include <string>

std::string solution(std::string s) {
    std::string answer = "";
    
    if (0 == s.size() % 2)
    {
        answer += s[s.size()/2 - 1];   
    }
    
    answer += s[s.size()/2];
    
    return answer;
}