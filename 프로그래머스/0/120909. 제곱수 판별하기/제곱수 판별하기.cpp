#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 2;
    
    int x = sqrt(n);
    if (x * x == n)
    {
        answer = 1;
    }
    
    return answer;
}