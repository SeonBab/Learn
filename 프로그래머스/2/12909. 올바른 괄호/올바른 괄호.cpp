#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<char> str;
    
    str.push_back(s[0]);
    
    for (int i = 1; i < s.length(); ++i)
    {
        if (str.back() == '(' && s[i] == ')')
        {
            str.pop_back();
            continue;
        }
        
        str.push_back(s[i]);
    }
    
    if (str.size() != 0)
    {
        answer = false;
    }

    return answer;
}