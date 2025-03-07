#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int>& numbers, int index, int sum, int target)
{
    if (index == numbers.size())
    {
        if (sum == target)
        {
            ++answer;
        }
        
        return;
    }
    
    dfs(numbers, index + 1, sum + numbers[index], target);
    dfs(numbers, index + 1, sum - numbers[index], target);
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, 0, 0, target);
    
    return answer;
}