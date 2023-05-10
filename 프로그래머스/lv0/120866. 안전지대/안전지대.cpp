#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    bool check{};

    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            check = true;
            
            for (int k = -1; k < 2; ++k)
            {
                for (int l = -1; l < 2; ++l)
                {
                    
                    if (i + k >= 0 && i + k < board.size() && j + l >= 0 && j + l < board[i].size())
                    {
                        if (board[i + k][j + l] == 1)
                        {
                            check = false;
                        }
                    }

                }
            }
            
            if (check)
            {
                ++answer;
            }
            
        }
    }
    return answer;
}