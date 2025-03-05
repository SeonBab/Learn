#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> pairQueue;
    priority_queue<int> maxPQ(priorities.begin(), priorities.end());
    
    for (int i = 0; i < priorities.size(); ++i)
    {
        pairQueue.push({priorities[i], i});
    }
    
    while (!pairQueue.empty())
    {
        int curPriority = pairQueue.front().first;
        int curIndex = pairQueue.front().second;
        
        pairQueue.pop();
        
        if (curPriority == maxPQ.top())
        {
            ++answer;
            
            if (curIndex == location)
            {
                break;
            }
            
            maxPQ.pop();
        }
        else
        {
            pairQueue.push({curPriority, curIndex});
        }
    }
    
    return answer;
}