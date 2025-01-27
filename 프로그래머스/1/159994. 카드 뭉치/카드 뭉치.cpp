#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    
    int j = 0;
    int k = 0;
    
    for (int i = 0; i < goal.size(); ++i)
    {
        if (goal[i] == cards1[j])
        {
            ++j;
        }
        else if (goal[i] == cards2[k])
        {
            ++k;
        }
        else
        {
            answer = "No";
            break;
        }
    }
    
    return answer;
}