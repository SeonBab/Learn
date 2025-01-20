#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); ++i)
    {
        vector<int> vec{ array };
        
        int start = commands[i][0] - 1;
        int end = commands[i][1];
        int numIndex = start + commands[i][2] - 1;

        sort(vec.begin() + start, vec.begin() + end);

        answer.push_back(vec[numIndex]);
    }
    
    
    return answer;
}