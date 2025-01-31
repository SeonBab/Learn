#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    vector<int> lank{6, 6, 5, 4, 3, 2, 1};
    
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
    
    answer.push_back(lank[high]);
    answer.push_back(lank[low]);
    
    return answer;
}