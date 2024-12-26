#include <cmath>

long long solution(long long n) {
    long long answer;
    long long root = sqrt(n);
    
    if (root * root == n)
    {
        answer = (root + 1) * (root + 1);
    }
    else
    {
        answer = -1;
    }
    
    return answer;
}