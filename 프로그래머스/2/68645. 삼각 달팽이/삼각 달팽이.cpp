#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> snail(n, vector<int>(n));
    
    int x = 0, y = 0;
    int count = 1;
    int dir = 0;
    
    for (int i = 0; i < n; ++i)
    {
        switch (dir)
        {
            // 아래
            case 0:
                for(int j = i; j < n; ++j)
                {
                    snail[y][x] = count;
                    ++count;
                    ++y;
                }

                dir = 1;
                ++x;
                --y;
                break;
            // 오른쪽
            case 1:
                for (int j = i; j < n; ++j)
                {
                    snail[y][x] = count;
                    ++count;
                    ++x;
                }
                
                dir = 2;
                x -= 2;
                --y;
                break;
            //위
            case 2:
                for (int j = i; j < n; ++j)
                {
                    snail[y][x] = count;
                    ++count;
                    --x;
                    --y;
                }
                
                dir = 0;
                ++x;
                y += 2;
                break;
            default:
                break;
        }
    }
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i + 1; ++j)
        {
            answer.push_back(snail[i][j]);
        }
    }
    
    return answer;
}