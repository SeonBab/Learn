#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int n = friends.size();
    unordered_map<string, int> nameIndex;
    
    for (int i = 0; i < n; ++i)
    {
        nameIndex[friends[i]] = i;
    }
    
    vector<vector<int>> give(n, vector<int>(n, 0));
    vector<int> givenCount(n, 0);
    vector<int> receivedCount(n, 0);
    
    for (const auto& e : gifts)
    {
        int spaceIndex = e.find(' ');
        
        string A = e.substr(0, spaceIndex);
        string B = e.substr(spaceIndex + 1);
        
        int AIndex = nameIndex[A];
        int BIndex = nameIndex[B];
        
        ++give[AIndex][BIndex];
        ++givenCount[AIndex];
        ++receivedCount[BIndex];
    }
    
    vector<int> nextrecevied(n, 0);
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            // 선물을 더 많이 줬다면
            if (give[i][j] > give[j][i])
            {
                ++nextrecevied[i];
            }
            // 선물을 더 많이 받았다면
            else if (give[i][j] < give[j][i])
            {
                ++nextrecevied[j];
            }
            // 같은 수로 주고받은 경우
            else
            {
                int AGiftScore = givenCount[i] - receivedCount[i];
                int BGiftScore = givenCount[j] - receivedCount[j];
                
                if (AGiftScore > BGiftScore)
                {
                    ++nextrecevied[i];
                }
                else if (AGiftScore < BGiftScore)
                {
                    ++nextrecevied[j];
                }
            }
        }
    }
    
    int answer = 0;
    
    for (const auto& e : nextrecevied)
    {
        if (answer < e)
        {
            answer = e;
        }
    }
    
    return answer;
}