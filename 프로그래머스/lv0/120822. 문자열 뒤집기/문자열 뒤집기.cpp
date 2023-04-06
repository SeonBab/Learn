#include <string>

std::string solution(std::string my_string) {
    std::string answer (my_string.rbegin(), my_string.rend());

    return answer;
}