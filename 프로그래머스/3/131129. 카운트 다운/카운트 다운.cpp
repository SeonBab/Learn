#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool isSingle(int score)
{
    if (score == 50 || 1 <= score && score <= 20)
    {
        return true;
    }
    
    return false;
}

vector<int> solution(int target) {
    vector<int> answer;
    
    vector<int> scores;
    for (int i = 1; i <= 20; ++i)
    {
        scores.push_back(i);
        scores.push_back(i * 2);
        scores.push_back(i * 3);
    }
    
    scores.push_back(50);
    
    vector<pair<int, int>> dp(target + 1, {INT_MAX, 0});
    dp[0] = {0, 0};
    
    for (int i = 0; i <= target; ++i)
    {
        if (dp[i].first == INT_MAX)
        {
            continue;
        }
        
        for (int s : scores)
        {
            if (i + s > target)
            {
                continue;
            }
            
            int nextDartCount = dp[i].first + 1;
            int nextSingleCount = dp[i].second + (isSingle(s) ? 1 : 0);
            
            if (dp[i + s].first > nextDartCount)
            {
                dp[i + s] = {nextDartCount, nextSingleCount};
            }
            else if (dp[i + s].first == nextDartCount && dp[i + s].second < nextSingleCount)
            {
                dp[i + s].second = nextSingleCount;
            }
        }
    }
    
    answer.push_back(dp[target].first);
    answer.push_back(dp[target].second);
    
    return answer;
}