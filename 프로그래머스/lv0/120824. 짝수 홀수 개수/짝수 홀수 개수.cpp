#include <vector>

std::vector<int> solution(std::vector<int> num_list) {
    std::vector<int> answer{ 0, 0 };

    for (int i = 0; i < num_list.size(); ++i)
    {
        (num_list[i] % 2 == 0) ? ++answer[0] : ++answer[1];
    }
    return answer;
}