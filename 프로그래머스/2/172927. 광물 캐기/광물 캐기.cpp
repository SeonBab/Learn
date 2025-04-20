#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int fatigue[3][3] = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};
int answer = INT_MAX;

int getMineralIndex(const string& m)
{
    if (m == "diamond")
    {
        return 0;        
    }
    else if (m == "iron")
    {
        return 1;
    }
    return 2;
}

void dfs(vector<int> picks, const vector<string>& minerals, int index, int currentFatigue)
{
    if (index >= minerals.size() || (picks[0] + picks[1] + picks[2]) == 0)
    {
        answer = min(answer, currentFatigue);
    }
    
    for (int i = 0; i < 3; ++i)
    {
        if(picks[i] == 0)
        {
            continue;
        }
        
        vector<int> tempPicks = picks;
        --tempPicks[i];
        
        int fatigueSum = 0;
        
        int end = min(index + 5, static_cast<int>(minerals.size()));
        for (int j = index; j < end; ++j)
        {
            int mIndex = getMineralIndex(minerals[j]);
            fatigueSum += fatigue[i][mIndex];
        }
        
        dfs(tempPicks, minerals, index + 5, currentFatigue + fatigueSum);
    }
}

int solution(vector<int> picks, vector<string> minerals) {    
    int maxMineCount = (picks[0] + picks[1] + picks[2]) * 5;
    
    if (minerals.size() > maxMineCount)
    {
        minerals.resize(maxMineCount);
    }
    
    dfs(picks, minerals, 0, 0);
    
    return answer;
}