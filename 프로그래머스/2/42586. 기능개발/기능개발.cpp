#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    for (int i = 0; i < progresses.size(); )
    {
        int count = 0;
        
        for (int j = i; j < progresses.size(); ++j)
        {
            progresses[j] += speeds[j];
            
            if (progresses[i] >= 100)
            {
                ++count;
                ++i;                
            }
        }
        
        if (count != 0)
        {
            answer.push_back(count);
        }
    }
    

    
    return answer;
}