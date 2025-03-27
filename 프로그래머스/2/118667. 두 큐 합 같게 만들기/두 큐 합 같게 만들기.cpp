#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0);
    unsigned long long total = sum1 + sum2;
    
    if (total % 2 == 1)
    {
        return -1;
    }
    
    int maxCount = queue1.size() * 3 - 3;
    queue<int> q1, q2;
    
    for (int i = 0; i < queue1.size(); ++i)
    {
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }
    
    while(sum1 != sum2)
    {
        if (sum1 > sum2)
        {
            sum1 -= q1.front();
            sum2 += q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else if (sum1 < sum2)
        {
            sum2 -= q2.front();
            sum1 += q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        
        ++answer;
        
        if (answer > maxCount)
        {
            return -1;
        }
    }
    
    return answer;
}