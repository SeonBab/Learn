#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> num_list) {
    std::vector<int> answer{};

    std::reverse(num_list.begin(), num_list.end());
    answer = num_list;

    return answer;
}
