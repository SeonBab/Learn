#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> maxHeap;
    
    for (int i = 0; i < enemy.size(); ++i)
    {
        n -= enemy[i];
        maxHeap.push(enemy[i]);
        
        if (n < 0)
        {
            if (k > 0)
            {
                int biggest = maxHeap.top();
                maxHeap.pop();
                
                n += biggest;
                --k;
            }
            else
            {
                return i;
            }
        }
    }
    
    return enemy.size();
}