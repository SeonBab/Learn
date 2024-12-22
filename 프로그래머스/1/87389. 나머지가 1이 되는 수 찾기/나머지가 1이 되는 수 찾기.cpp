#include <cmath>

int solution(int n) {
    int answer = 0;
    int target = n - 1;
    
    for (int i = 2; i <= std::sqrt(target); ++i)
    {
        if (target % i == 0)
        {
            answer = i;
            break;
        }
    }
    
    if (answer == 0)
    {
        answer = target;
    }
    
    return answer;
}