#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    for (int i = 1; i < food.size(); ++i)
    {
        int loopCount = food[i] / 2;
        for (int j = 0; j < loopCount; ++j)
        {
            answer += to_string(i);
        }
    }
    
    answer += '0';
    
    for (int i = answer.length() - 2; i >= 0; --i)
    {
        answer += answer[i];
    }
    
    return answer;
}