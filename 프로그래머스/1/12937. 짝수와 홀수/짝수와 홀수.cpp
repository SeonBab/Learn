#include <string>

std::string solution(int num) {
    std::string answer = "";
    
    if (num % 2 == 0)
    {
        answer = "Even";
    }
    else
    {
        answer = "Odd";
    }
    
    return answer;
}