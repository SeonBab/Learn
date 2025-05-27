#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 1;
    
    int wanhoAttitude = scores[0][0];
    int wanhoReputation = scores[0][1];
    int wanhoSum = wanhoAttitude + wanhoReputation;
    
    sort(scores.begin(), scores.end(), [](const vector<int>& a, const vector<int>& b)
         {
             if (a[0] == b[0])
             {
                 return a[1] < b[1];
             }
             
             return a[0] > b[0];
         });
    
    int maxReputation = 0;
    
    for (const auto& score : scores)
    {
        if (score[1] < maxReputation)
        {
            if (score[0] == wanhoAttitude & score[1] == wanhoReputation)
            {
                return -1;
            }
        }
        else
        {
            maxReputation = max(maxReputation, score[1]);
            
            if (score[0] + score[1] > wanhoSum)
            {
                ++answer;
            }
        }
    }
    
    return answer;
}