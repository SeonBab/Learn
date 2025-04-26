#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>

using namespace std;

int timetoMinutes(const string& timeStr)
{
    int hour = stoi(timeStr.substr(0, 2));
    int minute = stoi(timeStr.substr(3,4));
    
    return hour * 60 + minute;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    sort(plans.begin(), plans.end(), [](const vector<string>& a, const vector<string>& b)
         {
             return timetoMinutes(a[1]) < timetoMinutes(b[1]);
         });
    
    stack<pair<string, int>> remain;
    
    for (int i = 0; i < plans.size(); ++i)
    {
        string name = plans[i][0];
        int startTime = timetoMinutes(plans[i][1]);
        int playTime = stoi(plans[i][2]);
        
        int nextStartTime = (i + 1 < plans.size()) ? timetoMinutes(plans[i + 1][1]) : INT_MAX;
        int timeGap = nextStartTime - startTime;
        
        if (playTime <= timeGap)
        {
            answer.push_back(name);
            
            timeGap -= playTime;
            
            while (!remain.empty() && 0 < timeGap)
            {
                auto [remainName, remainTime] = remain.top();
                remain.pop();
                
                if (timeGap >= remainTime)
                {
                    timeGap -= remainTime;
                    answer.push_back(remainName);
                }
                else
                {
                    remain.push({remainName, remainTime - timeGap});
                    break;
                }
            }
        }
        else
        {
            remain.push({name, playTime - timeGap});
        }
    }
    
    while(!remain.empty())
    {
        answer.push_back(remain.top().first);
        remain.pop();
    }
    
    return answer;
}