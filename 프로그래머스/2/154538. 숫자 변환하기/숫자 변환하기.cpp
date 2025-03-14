#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int solution(int x, int y, int n) {
    
    if (x == y) return 0;
    
    queue<pair<int, int>> queue;
    unordered_set<int> set;
    
    set.insert(x);
    queue.push({x, 0});
    
    while (!queue.empty())
    {
        int currentNum = queue.front().first;
        int currentCount = queue.front().second;
        
        queue.pop();
        
        int nextValues[] = {currentNum + n, currentNum * 2, currentNum * 3};
        
        for (int nextVal : nextValues)
        {
            if (nextVal == y)
            {
                return currentCount + 1;
            }
            
            if (nextVal < y && set.find(nextVal) == set.end())
            {
                queue.push({nextVal, currentCount + 1});
                set.insert(nextVal);
            }
        }
    }
    
    return -1;
}