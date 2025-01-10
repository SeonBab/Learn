#include <vector>

int solution(int n) {
    int answer = 0;

    std::vector<int> str;
    while (n)
    {
        str.push_back(n % 3);
        n /= 3;
    }

    int three = 1;
    for (int i = str.size() - 1; i >= 0; --i)
    {
        answer += str[i] * three;
        three *= 3;
    }

    return answer;
}