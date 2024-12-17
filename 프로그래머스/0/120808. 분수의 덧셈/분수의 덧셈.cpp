#include <vector>

int GetGCD(int a, int b) {
    if (a % b == 0)
    {
        return b;
    }

    return GetGCD(b, a % b);
}

std::vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    std::vector<int> answer;

    int numerator = numer1 * denom2 + numer2 * denom1;
    int denominator = denom1 * denom2;

    int gcdResult = GetGCD(numerator, denominator);

    numerator /= gcdResult;
    denominator /= gcdResult;

    answer.push_back(numerator);
    answer.push_back(denominator);

    return answer;
}