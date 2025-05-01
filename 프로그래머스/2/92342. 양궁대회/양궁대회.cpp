#include <vector>

using namespace std;

int maxDiff = 0;
vector<int> answer;

void dfs(const vector<int>& info, vector<int>& currentInfo, int n, int index)
{
    if (index == info.size())
    {
        if (n > 0)
        {
            currentInfo[10] += n;
        }
        
        int lionScore = 0;
        int apeachScore = 0;
        
        for (int i = 0; i < info.size(); ++i)
        {
            if (info[i] == 0 && currentInfo[i] == 0)
            {
                continue;
            }
            
            if (currentInfo[i] > info[i])
            {
                lionScore += 10 - i;
            }
            else
            {
                apeachScore += 10 - i;
            }
        }
        
        if (lionScore > apeachScore)
        {
            int diff = lionScore - apeachScore;
            
            if (diff > maxDiff)
            {
                maxDiff = diff;
                
                answer = currentInfo;
            }
            else if (diff == maxDiff)
            {
                for (int i = info.size(); i >= 0; --i)
                {
                    if (currentInfo[i] > answer[i])
                    {
                        answer = currentInfo;
                        break;
                    }
                    else if (currentInfo[i] < answer[i])
                    {
                        break;
                    }
                }
            }
        }
        
        if (n > 0)
        {
            currentInfo[10] -= n;
        }
        return;
    }
    
    int requiredArrow = info[index] + 1;
    
    if (n >= requiredArrow)
    {
        currentInfo[index] = requiredArrow;
        dfs(info, currentInfo, n - requiredArrow, index + 1);
        
        currentInfo[index] = 0;
    }
    
    dfs(info, currentInfo, n, index + 1);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> currentInfo(info.size(), 0);
    
    dfs(info, currentInfo, n, 0);
    
    if (maxDiff == 0)
    {
        return {-1};
    }
    
    return answer;
}
