#include <string>
#include <vector>
#include <unordered_map>

std::string solution(int a, int b) {
    std::string answer = "";
    int totalDate = 0;
    
    std::vector<std::string> week{ "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };
    std::unordered_map<int, int> date;
    date[1] = 31;
    date[2] = 29;
    date[3] = 31;
    date[4] = 30;
    date[5] = 31;
    date[6] = 30;
    date[7] = 31;
    date[8] = 31;
    date[9] = 30;
    date[10] = 31;
    date[11] = 30;
    date[12] = 12;
    
    for (int i = 1; i < a; ++i)
    {
        totalDate += date[i];
    }
    
    totalDate += b;
    
    answer = week[totalDate % 7];
    
    return answer;
}