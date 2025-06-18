#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    
    vector<int> count(201, 0);
    
    for (int i = 0; i < lines.size(); ++i)
    {
        for (int j = lines[i][0]; j < lines[i][1]; ++j)
        {
            count[j + 100] += 1;
        }
    }
    
    for (int i = 0; i < count.size(); ++i)
    {
        if (count[i] >= 2)
        {
            ++answer;
        }
    }
    
    return answer;
}