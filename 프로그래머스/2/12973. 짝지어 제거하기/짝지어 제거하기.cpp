#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    
    stack<char> sStack;
    
    for (int i = 0; i < s.length(); ++i)
    {
        if (!sStack.empty() && sStack.top() == s[i])
        {
            sStack.pop();
            continue;
        }
        
        sStack.push(s[i]);
    }
    
    if (sStack.empty())
    {
        answer = 1;
    }

    return answer;
}