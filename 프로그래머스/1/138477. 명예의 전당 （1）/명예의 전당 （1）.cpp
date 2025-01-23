#include <vector>
#include <queue>

std::vector<int> solution(int k, std::vector<int> score) {
    std::vector<int> answer;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
    for (auto e : score)
    {
        minHeap.push(e);
        
        if (k < minHeap.size())
        {
            minHeap.pop();
        }
        
        answer.push_back(minHeap.top());
    }
    
    return answer;
}