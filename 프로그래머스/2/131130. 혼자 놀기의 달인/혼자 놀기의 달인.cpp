#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    
    int n = cards.size();
    
    vector<bool> visited(n, false);
    
    vector<int> groupSizes;
    
    for (int i = 0; i < n; ++i)
    {
        if (visited[i])
        {
            continue;
        }
        
        int current = i;
        int count = 0;
        
        while (!visited[current])
        {
            visited[current] = true;
            current = cards[current] - 1;
            ++count;
        }
        
        if (count > 0)
        {
            groupSizes.push_back(count);
        }
    }
    
    if (groupSizes.size() >= 2)
    {
        sort(groupSizes.begin(), groupSizes.end(), greater<int>());
        answer = groupSizes[0] * groupSizes[1];
    }
    
    return answer;
}