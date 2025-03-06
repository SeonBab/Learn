#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    sort(dungeons.begin(), dungeons.end());
    
    do {
        int currentFatigue = k;
        int count = 0;
        
        for (int i = 0; i < dungeons.size(); ++i)
        {
            if (currentFatigue >= dungeons[i][0])
            {
                currentFatigue -= dungeons[i][1];
                ++count;
            }
        }
        
        answer = max(answer, count);
        
    }while (next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}