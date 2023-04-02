#include <vector>
#include <algorithm>

int solution(std::vector<int> array) {
    int answer{}, temp{}, min{}, index{};

    std::sort(array.begin(), array.end());

    answer = array[array.size() / 2];

    return answer;
}