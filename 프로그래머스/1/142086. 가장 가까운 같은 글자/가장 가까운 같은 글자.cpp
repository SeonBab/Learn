#include <string>
#include <vector>
#include <unordered_map>

#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    for (int i = 0; i < s.length(); ++i)
    {
        for (int j = answer.size(); j >= 0; --j)
        {
            if (0 == j)
            {
                answer.push_back(-1);
            }
            else if (s[j - 1] == s[i])
            {
                answer.push_back(answer.size() - j + 1);
                break;
            }
        }
    }
    
    return answer;
}