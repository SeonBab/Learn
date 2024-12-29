#include <cstdlib>

long long solution(int a, int b) {
    long long answer = (long long)(a + b) * (std::abs(a - b) + 1) / 2;
    return answer;
}