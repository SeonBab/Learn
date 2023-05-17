#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i = 0; i < n; ++i)
    {
        ++answer;
        
        while(answer % 3 == 0 || answer % 10 == 3 || answer / 10 == 3 || answer % 100 / 10 == 3)
        {
            ++answer;
        }
    }
    
    return answer;
}