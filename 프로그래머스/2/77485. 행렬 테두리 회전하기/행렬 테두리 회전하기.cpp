#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> matrix(rows, vector<int>(columns));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            matrix[i][j] = i * columns + (j + 1);
        }
    }
    
    for (auto query : queries)
    {
        int y1 = query[0] - 1, x1 = query[1] - 1;
        int y2 = query[2] - 1, x2 = query[3] - 1;
        
        int prevValue = matrix[y1][x1];
        int minValue = prevValue;
        
        for (int i = x1; i < x2; ++i)
        {
            swap(matrix[y1][i + 1], prevValue);
            minValue = min(minValue, prevValue);
        }
        
        for (int i = y1; i < y2; ++i)
        {
            swap(matrix[i + 1][x2], prevValue);
            minValue = min(minValue, prevValue);
        }
        
        for (int i = x2; i > x1; --i)
        {
            swap(matrix[y2][i - 1], prevValue);
            minValue = min(minValue, prevValue);
        }
        
        for (int i = y2; i > y1; --i)
        {
            swap(matrix[i - 1][x1], prevValue);
            minValue = min(minValue, prevValue);
        }
        
        answer.push_back(minValue);
    }
    
    return answer;
}