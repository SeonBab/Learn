#include <vector>

int solution(int n) {
    int answer = 0;

    std::vector<int> vec;
    while (n)
    {
        vec.push_back(n % 3);
        n /= 3;
    }

    int power = 1;
    for (int i = vec.size() - 1; i >= 0; --i)
    {
        answer += vec[i] * power;
        power *= 3;
    }

    return answer;
}