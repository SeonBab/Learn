#include <string>
#include <algorithm>

std::string solution(std::string my_string, std::string letter) {
    std::string answer = "";

    my_string.erase(remove(my_string.begin(), my_string.end(), letter.front()), my_string.end());

    return answer = my_string;
}