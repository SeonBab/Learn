#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for (int i = 1; i <= number; ++i)
    {
        int divisorCount = 0;
        for(int j = 1; j * j <= i; ++j)
        {
            if (i % j == 0)
            {
                ++divisorCount;
                
                if (i / j != j)
                {
                    ++divisorCount;
                }
            }
            
            if (divisorCount > limit)
            {
                divisorCount = power;
                break;
            }
        }
        
        answer += divisorCount;
    }
    
    return answer;
}