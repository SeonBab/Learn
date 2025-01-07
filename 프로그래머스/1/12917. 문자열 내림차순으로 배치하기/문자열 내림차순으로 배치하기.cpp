#include <string>
#include <algorithm>

std::string solution(std::string s) {
    std::string answer = s;
    
    std::sort(answer.begin(), answer.end(), std::greater<char>());
    
    return answer;
}