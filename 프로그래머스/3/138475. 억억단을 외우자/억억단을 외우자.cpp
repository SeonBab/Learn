#include <vector>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    
    vector<int> count(e + 1, 0);
    for (int i = 1; i <= e; ++i)
    {
        for (int j = i; j <= e; j += i)
        {
            ++count[j];
        }
    }
    
    vector<int> dp(e + 2);
    dp[e] = e;
    
    for (int i = e - 1; i >= 1; --i)
    {
        dp[i] = (count[i] >= count[dp[i + 1]]) ? i : dp[i + 1];
    }
    
    for (int e : starts)
    {
        answer.push_back(dp[e]);
    }
    
    return answer;
}