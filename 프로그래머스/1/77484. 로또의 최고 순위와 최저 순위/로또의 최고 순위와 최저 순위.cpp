#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
        
    int high = 0;
    int low = 0;
    
    for (int i = 0; i < lottos.size(); ++i)
    {
        if (lottos[i] == 0)
        {
            ++high;
            continue;
        }
        
        for (int j = 0; j < win_nums.size(); ++j)
        {
            if (lottos[i] == win_nums[j])
            {
                ++high;
                ++low;
                break;
            }   
        }
    }
    
    high = (high > 1) ? high : 1;
    low = (low > 1) ? low : 1;
    
    answer.push_back(7 - high);
    answer.push_back(7 - low);
    
    return answer;
}