#include <vector>
#include <algorithm>

int GetGCD(int a, int b)
{
    int c{};

    std::pair<int, int> r1 = std::minmax(a, b);

    a = r1.first;   // 작은 수
    b = r1.second;  // 큰 수

    while (a != 0)
    {
        c = b % a;
        b = a;
        a = c;
    }
    
    return b;
}

std::vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    std::vector<int> answer;

    // 분자, 분모 계산
    int numer = numer1 * denom2 + numer2 * denom1;
    int denom = denom1 * denom2;

    // 최대공약수를 저장할 변수 생성
    int GCD{};

    // 최대공약수 계산
    GCD = GetGCD(numer, denom);

    // 약분과 대입
    answer.push_back(numer / GCD);
    answer.push_back(denom / GCD);

    return answer;
}