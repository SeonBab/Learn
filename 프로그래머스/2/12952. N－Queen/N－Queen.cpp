#include <vector>
#include <cmath>

using namespace std;

int answer;

bool isValid(vector<int>& col, int row)
{
    for (int i = 0; i < row; ++i)
    {
        if (col[i] == col[row] || abs(col[i] - col[row]) == abs(i - row))
        {
            return false;
        }
    }
    
    return true;
}

void dfs(int N, vector<int>& col, int row)
{
    if (N == row)
    {
        ++answer;
        return;
    }
    
    for (int i = 0; i < N; ++i)
    {
        col[row] = i;
        if (isValid(col, row))
        {
            dfs(N, col, row + 1);
        }
    }
}

int solution(int n) {
    answer = 0;
    
    vector<int> col(n);
    
    dfs(n, col, 0);
    
    return answer;
}