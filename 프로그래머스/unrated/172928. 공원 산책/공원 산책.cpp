#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> startingPoint(vector<string> park)
{
    vector<int> sPoint;

    for (int j = 0; j < park.size(); ++j)
    {
        for (int k = 0; k < park[j].length(); ++k)
        {
            if (park[j][k] == 'S')
            {
                sPoint.push_back(j);
                sPoint.push_back(k);
                return sPoint;
            }
        }
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer = startingPoint(park);

    for (int i = 0; i < routes.size(); ++i)
    {
        char op;
        int n;
        stringstream str(routes[i]);

        str >> op >> n;

        if (op == 'N' && answer[0] - n >= 0)
        {
            for (int i = 1; i <= n; ++i)
            {
                if (park[answer[0] - i][answer[1]] == 'X')
                {
                    n = 0;
                    break;
                }
            }
            answer[0] -= n;
        }

        else if (op == 'S' && answer[0] + n < park.size())
        {
            for (int i = 1; i <= n; ++i)
            {
                if (park[answer[0] + i][answer[1]] == 'X')
                {
                    n = 0;
                    break;
                }
            }
            answer[0] += n;
        }

        else if (op == 'W' && answer[1] - n >= 0)
        {
            for (int i = 1; i <= n; ++i)
            {
                if (park[answer[0]][answer[1] - i] == 'X')
                {
                    n = 0;
                    break;
                }
            }
            answer[1] -= n;
        }

        else if (op == 'E' && answer[1] + n < park[0].length())
        {
            for (int i = 1; i <= n; ++i)
            {
                if (park[answer[0]][answer[1] + i] == 'X')
                {
                    n = 0;
                    break;
                }
            }
            answer[1] += n;
        }
        
        str.clear();
    }

    return answer;
}