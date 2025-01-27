#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    std::vector<int> box;
    int minScore = 0;
    
    sort(score.rbegin(), score.rend());
    
    for (int i = 0; i < score.size(); ++i)
    {
        box.push_back(score[i]);
        
        if (minScore < score[i])
        {
            minScore = score[i];
        }
        
        if (box.size() == m)
        {
            answer += minScore * m;
            box.clear();
        }
        
        minScore = 0;
    }
    
    return answer;
}