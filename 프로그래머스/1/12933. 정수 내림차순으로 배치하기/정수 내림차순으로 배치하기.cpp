#include <string>
#include <algorithm>

long long solution(long long n) {
    long long answer = 0;
    
    std::string str = std::to_string(n);
    
    sort(str.rbegin(), str.rend());
    
    for (int i = 0; i < str.size(); ++i)
    {
        answer = answer * 10 + (str[i] - '0');
    }
    
    return answer;
}