#include <string>

int solution(std::string t, std::string p) {
    int answer = 0;
    
    for (int i = 0; i <= t.length() - p.length(); ++i)
    {
        std::string str = t.substr(i, p.length());
        
        if (str <= p)
        {
            ++answer;
        }
    }
    
    return answer;;
}