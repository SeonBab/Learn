#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    
    int index{};
    
    for (int i = 0; i < num_list.size() / n; ++i)
    {
        answer.push_back(vector<int>());
        
        for (int j = 0; j < n; ++j, ++index)
        {
            answer[i].push_back(num_list[index]);
        }

    }
    
    return answer;
}