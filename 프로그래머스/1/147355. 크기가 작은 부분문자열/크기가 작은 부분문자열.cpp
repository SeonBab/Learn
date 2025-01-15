#include <string>

int solution(std::string t, std::string p) {
    int answer = 0;
    long long pNum = 0;
    
    for (int i = 0; i < p.length(); ++i)
    {
        pNum *= 10;
        pNum += static_cast<int>(p[i]) - '0';
    }
    
    for (int i = 0; i <= t.length() - p.length(); ++i)
    {
        long long tNum = 0;
        
        for (int j = 0; j < p.length(); ++j)
        {
            tNum *= 10;
            tNum += static_cast<int>(t[i + j]) - '0';
        }
                
        if (tNum <= pNum)
        {
            ++answer;
        }
    }
    
    return answer;
}