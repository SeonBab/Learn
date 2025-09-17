#include <vector>

using namespace std;

int directionX[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int directionY[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            bool safe = true;
            
            for (int k = 0; k < 9; ++k)
            {
                int dx = j + directionY[k];
                int dy = i + directionX[k];
                
                if (dx >= 0 && dy >= 0 && dx < board[i].size() && dy < board.size())
                {
                    if (board[dy][dx] == 1)
                    {
                        safe = false;
                        break;
                    }
                }
            }
            
            if (safe)
            {
                answer += 1;
            }
        }
    }
    
    return answer;
}