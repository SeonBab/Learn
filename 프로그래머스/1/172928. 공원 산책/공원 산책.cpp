#include <string>
#include <vector>

using namespace std;

vector<int> startingPoint(const vector<string>& park)
{
    vector<int> startPoint;

    for (int i = 0; i < park.size(); ++i)
    {
        for (int j = 0; j < park[i].length(); ++j)
        {
            if (park[i][j] == 'S')
            {
                startPoint.push_back(i);
                startPoint.push_back(j);
                return startPoint;
            }
        }
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer = startingPoint(park);
    
    for (int i = 0; i < routes.size(); ++i)
    {
        char Direction = routes[i][0];
        int Count = routes[i][2] - '0';
        
        if (Direction == 'N' && answer[0] - Count >= 0)
        {
            for (int j = 1; j <= Count; ++j)
            {
                if (park[answer[0] - j][answer[1]] == 'X')
                {
                    Count = 0;
                    break;
                }
            }
            
            answer[0] -= Count;
        }
        else if (Direction == 'S' && answer[0] + Count < park.size())
        {
            for (int j = 1; j <= Count; ++j)
            {
                if (park[answer[0] + j][answer[1]] == 'X')
                {
                    Count = 0;
                    break;
                }
            }
            
            answer[0] += Count;
        }
        else if (Direction == 'W' && answer[1] - Count >= 0)
        {
            for (int j = 1; j <= Count; ++j)
            {
                if (park[answer[0]][answer[1] - j] == 'X')
                {
                    Count = 0;
                    break;
                }
            }
            
            answer[1] -= Count;
        }
        else if (Direction == 'E' && answer[1] + Count < park[0].length())
        {
            for (int j = 1; j <= Count; ++j)
            {
                if (park[answer[0]][answer[1] + j] == 'X')
                {
                    Count = 0;
                    break;
                }
            }
            
            answer[1] += Count;
        }
    }
    
    return answer;
}