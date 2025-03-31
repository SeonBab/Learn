#include <vector>

using namespace std;

int answer = 0;

void dfs(const vector<int>& numbers, const int target, int index, int curNum)
{
    if (numbers.size() <= index)
    {
        if (curNum == target)
        {
            ++answer;
        }
        return;
    }
    
    int nextIndex = index + 1;
    
    dfs(numbers, target, nextIndex,  curNum + numbers[index]);
    dfs(numbers, target, nextIndex,  curNum - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, target, 0, 0);
    
    return answer;
}