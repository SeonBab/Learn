#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0, num{};
    while (i <= j)
    {
        num = i;
        while (num)
        {
            if (num % 10 == k)
            {
                ++answer;
            }
            
            num /= 10;
        }
        
        ++i;
    }
    
    return answer;
}