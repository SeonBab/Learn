#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    answer = n / 7;
    if (n % 7)
    {
        answer += 1;
    }
    
    return answer;
}