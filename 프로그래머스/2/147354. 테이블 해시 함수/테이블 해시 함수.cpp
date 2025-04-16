#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    sort(data.begin(), data.end(), [col](const vector<int>& v1, const vector<int>& v2)
    {
        if (v1[col - 1] == v2[col - 1])
        {
            return v1[0] > v2[0];
        }
        
        return v1[col - 1] < v2[col - 1];
    });
    
    for (int i = row_begin - 1; i <= row_end - 1; ++i)
    {
        int S_i = 0;
        for (int number : data[i])
        {
            S_i += number % (i + 1);
        }
        
        answer ^= S_i;
    }
    
    return answer;
}