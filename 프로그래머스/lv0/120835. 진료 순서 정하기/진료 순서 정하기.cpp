#include <vector>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;

    for (int i = 0; i < emergency.size(); ++i)
    {
        answer.push_back(1);
        
        for(int j = 0; j < emergency.size(); ++j)
        {
            if(emergency[i] < emergency[j])
            {
                ++answer[i];
            }
        }
    }
    return answer;
}