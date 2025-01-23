#include <string>
#include <vector>

std::string solution(int a, int b) {
    std::string answer = "";
    int totalDate = 0;
    
    std::vector<std::string> week{ "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };
    std::vector<int> date{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    for (int i = 0; i < a - 1; ++i)
    {
        totalDate += date[i];
    }
    
    totalDate += b;
    
    answer = week[totalDate % 7];
    
    return answer;
}