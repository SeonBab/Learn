#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "0";
    
    for (int i = food.size() - 1; i > 0 ; --i)
    {
        int loopCount = food[i] / 2;
        for (int j = 0; j < loopCount; ++j)
        {
            answer = to_string(i) + answer + to_string(i);
        }
    }
    
    return answer;
}