#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(), jobs.end());
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    int currentTime = 0;
    int index = 0;
    int totalWait = 0;
    int count = 0;
    
    while (count < jobs.size())
    {
        while(index < jobs.size() && jobs[index][0] <= currentTime)
        {
            pq.push({jobs[index][1], jobs[index][0]});
            ++index;
        }
        
        if (!pq.empty())
        {
            auto [duration, requestTime] = pq.top();
            pq.pop();
            
            currentTime += duration;
            totalWait += currentTime - requestTime;
            ++count;
        }
        else
        {
            currentTime = jobs[index][0];
        }
    }
    
    answer = totalWait / jobs.size();
    
    return answer;
}