#include <cmath>

int solution(int left, int right) {
    int answer = 0;
    
    for (int i = left; i <= right; ++i)
    {
        int sqrtValue = sqrt(i);
        
        if (sqrtValue * sqrtValue == i)
        {
            answer -= i;
        }
        else
        {
            answer += i;
        }
    }
    
    return answer;
}