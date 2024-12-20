#include <string>

int solution(int n)
{
    int answer = 0;

    std::string num = std::to_string(n);

    for (int i = 0; i < num.size(); ++i)
    {
        answer += num[i] - '0';
    }

    return answer;
}