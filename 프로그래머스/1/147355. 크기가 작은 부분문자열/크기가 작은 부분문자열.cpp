#include <string>

int solution(std::string t, std::string p) {
    int answer = 0;
    long long pNum = std::stoll(p);
    
    for (int i = 0; i <= t.length() - p.length(); ++i)
    {
        std::string str = t.substr(i, p.length());
        long long tNum = std::stoll(str);
        
        if (tNum <= pNum)
        {
            ++answer;
        }
    }
    
    return answer;
}