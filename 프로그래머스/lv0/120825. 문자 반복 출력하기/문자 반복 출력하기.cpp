#include <string>

std::string solution(std::string my_string, int n) {
    std::string answer{};

    for (int i = 0; i < my_string.size(); ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            answer += my_string[i];
        }
    }
    return answer;
}