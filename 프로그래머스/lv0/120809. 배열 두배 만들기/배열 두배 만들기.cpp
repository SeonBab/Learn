#include <vector>

std::vector<int> solution(std::vector<int> numbers) {
    std::vector<int> answer;
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        answer.push_back(numbers[i] * 2);
    }
    
    return answer;
}