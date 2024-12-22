#include <vector>

double solution(std::vector<int> numbers) {
    double answer = 0;
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        answer += numbers[i];
    }
    
    answer /= numbers.size();
    
    return answer;
}