#include <string>
#include <vector>

using namespace std;

bool checkWin(const vector<string>& board, char player)
{
    for (int i = 0; i < board.size(); ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }
    
    for (int j = 0; j < board[0].length(); ++j)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
        {
            return true;
        }
    }
    
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }
    else if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }
    
    return false;
}

int solution(vector<string> board) {
    int oCount = 0;
    int xCount = 0;
    
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[0].length(); ++j)
        {
            if (board[i][j] == 'O')
            {
                ++oCount;
            }
            else if (board[i][j] == 'X')
            {
                ++xCount;
            }
        }
    }
    
    if (xCount > oCount || oCount > xCount + 1)
    {
        return 0;
    }
    
    bool isOWin = checkWin(board, 'O');
    bool isXWin = checkWin(board, 'X');
    
    if (isOWin && isXWin)
    {
        return 0;
    }
    else if (isOWin && oCount == xCount)
    {
        return 0;
    }
    else if (isXWin && oCount != xCount)
    {
        return 0;
    }
    
    return 1;
}