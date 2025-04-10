#include <string>
#include <vector>

using namespace std;

int dx1[4] = {1, -1, 0, 0};
int dy1[4] = {0, 0, 1, -1};

int dx2[4] = {2, -2, 0, 0};
int dy2[4] = {0, 0, 2, -2};

int dxDiag[4] = {1, 1, -1, -1};
int dyDiag[4] = {1, -1, 1, -1};

bool checkRoom(const vector<string>& room)
{
    for (int y = 0; y < room.size(); ++y)
    {
        for (int x = 0; x < room[0].size(); ++x)
        {
            if (room[y][x] != 'P')
            {
                continue;
            }
            
            for (int d = 0; d < 4; ++d)
            {
                int nx = x + dx1[d];
                int ny = y + dy1[d];
                if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                if (room[ny][nx] == 'P') return false;
            }
            
            for (int d = 0; d < 4; ++d)
            {
                int nx = x + dx2[d];
                int ny = y + dy2[d];
                if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                if (room[ny][nx] == 'P')
                {
                    int mx = x + dx1[d];
                    int my = y + dy1[d];
                    if (room[my][mx] != 'X') return false;
                }
            }
            
            for (int d = 0; d < 4; ++d)
            {
                int nx = x + dxDiag[d];
                int ny = y + dyDiag[d];
                
                if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                if (room[ny][nx] == 'P')
                {
                    int mx1 = x;
                    int my1 = ny;
                    int mx2 = nx;
                    int my2 = y;
                    if (room[my1][mx1] != 'X' || room[my2][mx2] != 'X') return false;
                }
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (const vector<string>& room : places)
    {
        if (checkRoom(room))
        {
            answer.push_back(1);
        }
        else
        {
            answer.push_back(0);
        }
    }
    
    return answer;
}