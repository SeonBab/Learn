#include <vector>

using namespace std;

bool isUniform(const vector<vector<int>>& arr, int x, int y, int size)
{
    int first = arr[x][y];
    for (int i = x; i < x + size; ++i)
    {
        for (int j = y; j < y + size; ++j)
        {
            if (arr[i][j] != first)
            {
                return false;
            }
        }
    }
    
    return true;
}

void compress(vector<int>& answer, const vector<vector<int>>& arr, int x, int y, int size)
{
    if (isUniform(arr, x, y, size))
    {
        answer[arr[x][y]]++;
        return;
    }
    
    int newsize = size / 2;
    
    compress(answer, arr, x, y, newsize);
    compress(answer, arr, x, y + newsize, newsize);
    compress(answer, arr, x + newsize, y, newsize);
    compress(answer, arr, x + newsize, y + newsize, newsize);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    
    compress(answer, arr, 0, 0, arr.size());
    
    return answer;
}