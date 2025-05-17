#include <vector>
#include <algorithm>

using namespace std;

int findParent(vector<int>& parent, int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    
    return parent[x] = findParent(parent, parent[x]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<int> parent(n);
    
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
    }
    
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b)
         {
             return a[2] < b[2];
         });
    
    for (const auto& edge : costs)
    {
        int a = edge[0];
        int b = edge[1];
        int cost = edge[2];
        
        int aParent = findParent(parent, a);
        int bParent = findParent(parent, b);
        
        if (aParent != bParent)
        {
            if (aParent < bParent)
            {
                parent[bParent] = aParent;
            }
            else
            {
                parent[aParent] = bParent;
            }
            
            answer += cost;
        }
    }
    
    return answer;
}