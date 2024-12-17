#include <vector>

std::vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    std::vector<int> answer;

    int numerator = numer1 * denom2 + numer2 * denom1;
    int denominator = denom1 * denom2;

    for (int i = std::min(denominator, numerator); i >= 2; i--)
    {
        if (denominator % i == 0 && numerator % i == 0)
        {
            denominator /= i;
            numerator /= i;
            break;
        }
    }

    answer.push_back(numerator);
    answer.push_back(denominator);

    return answer;
}