#include <string>

std::string solution(std::string phone_number) {
    std::string answer = "";

    for (int i = 0; i < phone_number.size(); ++i)
    {
        (i + 4 < phone_number.size()) ? answer.push_back('*') : answer.push_back(phone_number[i]);
    }

    return answer;
}