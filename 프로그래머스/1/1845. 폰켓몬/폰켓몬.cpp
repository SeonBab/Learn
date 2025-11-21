#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = nums.size() / 2;
    
    unordered_set<int> numSet;
    
    for (int num : nums)
    {
        numSet.insert(num);
    }
    
    if (numSet.size() < nums.size() / 2)
    {
        answer = numSet.size();
    }
    
    return answer;
}