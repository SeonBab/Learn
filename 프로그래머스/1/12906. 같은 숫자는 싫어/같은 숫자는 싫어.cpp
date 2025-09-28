#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int prev_num = -1;
    
    for (const auto& e : arr)
    {
        if (prev_num == e)
        {
            continue;
        }
        
        prev_num = e;
        answer.push_back(e);
    }

    return answer;
}