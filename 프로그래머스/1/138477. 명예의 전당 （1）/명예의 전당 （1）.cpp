#include <vector>
#include <algorithm>

std::vector<int> solution(int k, std::vector<int> score) {
    std::vector<int> answer;
    std::vector<int> temp;
    
    for (int i = 0; i < score.size(); ++i)
    {
        temp.push_back(score[i]);
        
        std::sort(temp.rbegin(), temp.rend());
        
        if (k < temp.size())
        {
            temp.pop_back();
        }
        
        answer.push_back(temp.back());
    }
    
    return answer;
}