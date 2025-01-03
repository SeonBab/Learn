#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> arr) {
    std::vector<int>::iterator min = min_element(arr.begin(), arr.end());

    arr.erase(min);

    if (true == arr.empty())
    {
        arr.push_back(-1);
    }

    return arr;
}