#include <string>
#include <vector>

std::vector<int> solution(long long n) {
    std::vector<int> answer;

    std::string str = std::to_string(n);

    for (int i = str.size() - 1; i >= 0; --i)
    {
        answer.push_back(str[i] - '0');
    }

    return answer;
}