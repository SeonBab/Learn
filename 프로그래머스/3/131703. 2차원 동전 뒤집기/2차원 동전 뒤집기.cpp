#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = INT_MAX;
    int m = beginning.size();
    int n = beginning[0].size();
    
    for (int bit = 0; bit < (1 << m); ++bit)
    {
        vector<vector<int>> temp = beginning;
        
        for (int i = 0; i < m; ++i)
        {
            if (bit & (1 << i))
            {
                for (int j = 0; j < n; ++j)
                {
                    temp[i][j] ^= 1;
                }
            }
        }
        
        vector<bool> colFlip(n, false);
        
        for (int j = 0; j < n; ++j)
        {
            if (temp[0][j] != target[0][j])
            {
                colFlip[j] = true;
                
                for (int i = 0; i < m; ++i)
                {
                    temp[i][j] ^= 1;
                }
            }
        }
        
        bool ok = true;
        
        for (int i = 0; i < m && ok; ++i)
        {
            for (int j = 0; j < n && ok; ++j)
            {
                if (temp[i][j] != target[i][j])
                {
                    ok = false;
                }
            }
        }
        
        if (ok)
        {
            int rowCount = __builtin_popcount(bit);
            int colCount = 0;
            
            for (bool e : colFlip)
            {
                colCount += e;
            }
            
            answer = min(answer, rowCount + colCount);
        }
    }
    
    return (answer == INT_MAX) ? -1 : answer;
}